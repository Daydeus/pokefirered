#include "global.h"
#include "gflib.h"
#include "scanline_effect.h"
#include "text_window_graphics.h"
#include "menu.h"
#include "task.h"
#include "overworld.h"
#include "help_system.h"
#include "text_window.h"
#include "strings.h"
#include "field_fadetransition.h"
#include "gba/m4a_internal.h"
#include "event_data.h"

// can't include the one in menu_helpers.h since Task_OptionMenu needs bool32 for matching
bool32 IsActiveOverworldLinkBusy(void);

// Button inputs
enum
{
    NO_BUTTON_PRESSED,
    A_B_PRESSED,
    LEFT_RIGHT_PRESSED_ON_FRAME,
    UP_DOWN_PRESSED,
    LEFT_RIGHT_PRESSED,
    SELECT_PRESSED
};

// Menu Page 1 General Options
enum
{
    PAGE1_TEXTSPEED = 0,
    PAGE1_MOVEMENTMODE,
    PAGE1_SOUND,
    PAGE1_BUTTONMODE,
    PAGE1_FRAMETYPE,
    PAGE1_CANCEL,
    PAGE1_COUNT
};

// Menu Page 2 Battle Options
enum
{
    PAGE2_STRONG_AI = 0,
    PAGE2_BATTLESTYLE,
    PAGE2_BATTLEITEMBAN,
    PAGE2_BATTLESCENE,
    PAGE2_CANCEL,
    PAGE2_COUNT
};

#define MAX_PAGE_LENGTH 7

// Window Ids
enum
{
    WIN_TEXT_OPTION,
    WIN_OPTIONS
};

// RAM symbols
struct OptionMenu
{
    u16 optionPage1[PAGE1_COUNT];
    u16 optionPage2[PAGE2_COUNT];
    u16 cursorPos;
    u8 loadState;
    u8 state;
    u8 loadPaletteState;
};

static EWRAM_DATA u8 currentOptionsPage = 0;
static EWRAM_DATA struct OptionMenu *sOptionMenuPtr = NULL;

//Function Declarataions
static void CB2_InitOptionMenu(void);
static void VBlankCB_OptionMenu(void);
static void OptionMenu_InitCallbacks(void);
static void OptionMenu_SetVBlankCallback(void);
static void CB2_OptionMenu(void);
static void SetOptionMenuTask(void);
static void InitOptionMenuBg(void);
static void OptionMenu_PickSwitchCancel(void);
static void OptionMenu_ResetSpriteData(void);
static bool8 LoadOptionMenuPalette(void);
static void Task_OptionMenu(u8 taskId);
static u8 OptionMenu_ProcessInput(void);
static void BufferOptionMenuString(u8 selection);
static void BufferAllOptionMenuStrings(void);
static void CloseAndSaveOptionMenu(u8 taskId);
static void PrintOptionMenuHeader(void);
static void DrawOptionMenuBg(void);
static void LoadOptionMenuItemNames(void);
static void UpdateSettingSelectionDisplay(u16 selection);

// Data Definitions
static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 7,
        .width = 26,
        .height = 12,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    {
        .bg = 2,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x16e
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
   {
       .bg = 1,
       .charBaseIndex = 1,
       .mapBaseIndex = 30,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 0,
       .baseTile = 0
   },
   {
       .bg = 0,
       .charBaseIndex = 1,
       .mapBaseIndex = 31,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 1,
       .baseTile = 0
   },
   {
       .bg = 2,
       .charBaseIndex = 1,
       .mapBaseIndex = 29,
       .screenSize = 0,
       .paletteMode = 0,
       .priority = 2,
       .baseTile = 0
   },
};

static const u16 sOptionMenuPalette[] = INCBIN_U16("graphics/misc/option_menu.gbapal");

// Page 1 Options
static const u16 sOptionMenuPage1ItemCounts[PAGE1_COUNT] = {3, 2, 2, 3, 10, 0};

static const u8 *const sOptionMenuPage1ItemsNames[PAGE1_COUNT] =
{
    [PAGE1_TEXTSPEED]    = gText_TextSpeed,
    [PAGE1_MOVEMENTMODE] = gText_MovementMode,
    [PAGE1_SOUND]        = gText_Sound,
    [PAGE1_BUTTONMODE]   = gText_ButtonMode,
    [PAGE1_FRAMETYPE]    = gText_Frame,
    [PAGE1_CANCEL]       = gText_OptionMenuCancel,
};

static const u8 *const sTextSpeedOptions[] =
{
    gText_TextSpeedSlow, 
    gText_TextSpeedMid, 
    gText_TextSpeedFast
};


static const u8 *const sMovementModeOptions[] =
{
    gText_MovementWalk,
    gText_MovementRun
};

static const u8 *const sSoundOptions[] =
{
    gText_SoundMono, 
    gText_SoundStereo
};

static const u8 *const sButtonTypeOptions[] =
{
    gText_ButtonTypeHelp,
	gText_ButtonTypeLR,
	gText_ButtonTypeLEqualsA
};

// Page 2 Options
static const u16 sOptionMenuPage2ItemCounts[PAGE2_COUNT] = {2, 2, 4, 2, 0};

static const u8 *const sOptionMenuPage2ItemsNames[PAGE2_COUNT] =
{
    [PAGE2_STRONG_AI]     = gText_StrongAI,
    [PAGE2_BATTLESTYLE]   = gText_BattleStyle,
    [PAGE2_BATTLEITEMBAN] = gText_BattleItemBan,
    [PAGE2_BATTLESCENE]   = gText_BattleScene,
    [PAGE2_CANCEL]        = gText_OptionMenuCancel,
};

static const u8 *const sStrongAIOptions[] =
{
    gText_BattleSceneOff,
    gText_BattleSceneOn
};

static const u8 *const sBattleStyleOptions[] =
{
    gText_BattleStyleShift,
    gText_BattleStyleSet
};

static const u8 *const sBattleItemBanOptions[] =
{
    gText_BattleSceneOff,
    gText_BattleItemBanFoe,
    gText_BattleItemBanPlayer,
    gText_BattleItemBanBoth,
};

static const u8 *const sBattleSceneOptions[] =
{
    gText_BattleSceneOn,
    gText_BattleSceneOff
};

static const u8 sOptionMenuPickSwitchCancelTextColor[] = {TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
static const u8 sOptionMenuTextColor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED};

// Functions
static void CB2_InitOptionMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_OptionMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_OptionsMenuFromStartMenu(void)
{
    u8 i;

    if (gMain.savedCallback == NULL)
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;
    sOptionMenuPtr = AllocZeroed(sizeof(struct OptionMenu));
    sOptionMenuPtr->loadState = 0;
    sOptionMenuPtr->loadPaletteState = 0;
    sOptionMenuPtr->state = 0;
    sOptionMenuPtr->cursorPos = 0;

    // Read currently saved Page 1 options
    sOptionMenuPtr->optionPage1[PAGE1_TEXTSPEED]    = gSaveBlock2Ptr->optionsTextSpeed;
    sOptionMenuPtr->optionPage1[PAGE1_MOVEMENTMODE] = FlagGet(FLAG_MOVEMENTMODE);
    sOptionMenuPtr->optionPage1[PAGE1_SOUND]        = gSaveBlock2Ptr->optionsSound;
    sOptionMenuPtr->optionPage1[PAGE1_BUTTONMODE]   = gSaveBlock2Ptr->optionsButtonMode;
    sOptionMenuPtr->optionPage1[PAGE1_FRAMETYPE]    = gSaveBlock2Ptr->optionsWindowFrameType;
    for (i = 0; i < PAGE1_COUNT - 1; i++)
    {
        if (sOptionMenuPtr->optionPage1[i] > (sOptionMenuPage1ItemCounts[i]) - 1)
            sOptionMenuPtr->optionPage1[i] = 0;
    }

    // Read currently saved Page 2 options
    sOptionMenuPtr->optionPage2[PAGE2_STRONG_AI]     = FlagGet(FLAG_STRONG_AI);
    sOptionMenuPtr->optionPage2[PAGE2_BATTLESTYLE ]  = gSaveBlock2Ptr->optionsBattleStyle;
    sOptionMenuPtr->optionPage2[PAGE2_BATTLEITEMBAN] = gSaveBlock2Ptr->optionsBattleItemBan;
    sOptionMenuPtr->optionPage2[PAGE2_BATTLESCENE]   = gSaveBlock2Ptr->optionsBattleSceneOff;
    for (i = 0; i < PAGE2_COUNT - 1; i++)
    {
        if (sOptionMenuPtr->optionPage2[i] > (sOptionMenuPage2ItemCounts[i]) - 1)
            sOptionMenuPtr->optionPage2[i] = 0;
    }
    SetHelpContext(HELPCONTEXT_OPTIONS);
    SetMainCallback2(CB2_OptionMenu);
}

static void OptionMenu_InitCallbacks(void)
{
    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void OptionMenu_SetVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_OptionMenu);
}

static void CB2_OptionMenu(void)
{
    u8 i, state, pageLength;
    state = sOptionMenuPtr->state;
    switch (state)
    {
    case 0:
        OptionMenu_InitCallbacks();
        break;
    case 1:
        InitOptionMenuBg();
        break;
    case 2:
        OptionMenu_ResetSpriteData();
        break;
    case 3:
        if (LoadOptionMenuPalette() != TRUE)
            return;
        break;
    case 4:
        PrintOptionMenuHeader();
        break;
    case 5:
        DrawOptionMenuBg();
        break;
    case 6:
        LoadOptionMenuItemNames();
        break;
    case 7:
        pageLength = (currentOptionsPage == 0) ? PAGE1_COUNT : PAGE2_COUNT;
        for (i = 0; i < pageLength; i++)
            BufferOptionMenuString(i);
        break;
    case 8:
        UpdateSettingSelectionDisplay(sOptionMenuPtr->cursorPos);
        break;
    case 9:
        OptionMenu_PickSwitchCancel();
        break;
    default:
        SetOptionMenuTask();
		break;
    }
    sOptionMenuPtr->state++;
}

static void SetOptionMenuTask(void)
{
    CreateTask(Task_OptionMenu, 0);
    SetMainCallback2(CB2_InitOptionMenu);
}

static void InitOptionMenuBg(void)
{
    void *dest = (void *)VRAM;
    DmaClearLarge16(3, dest, VRAM_SIZE, 0x1000);    
    DmaClear32(3, (void *)OAM, OAM_SIZE);
    DmaClear16(3, (void *)PLTT, PLTT_SIZE);    
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sOptionMenuBgTemplates, NELEMS(sOptionMenuBgTemplates));
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    InitWindows(sOptionMenuWinTemplates);
    DeactivateAllTextPrinters();
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_EFFECT_LIGHTEN);
    SetGpuReg(REG_OFFSET_BLDY, BLDCNT_TGT1_BG1);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_CLR);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
};

static void OptionMenu_PickSwitchCancel(void)
{
    s32 x;
    x = 0xE4 - GetStringWidth(FONT_SMALL, gText_PickSwitchCancel, 0);
    FillWindowPixelBuffer(2, PIXEL_FILL(15)); 
    AddTextPrinterParameterized3(2, FONT_SMALL, x, 0, sOptionMenuPickSwitchCancelTextColor, 0, gText_PickSwitchCancel);
    PutWindowTilemap(2);
    CopyWindowToVram(2, COPYWIN_FULL);
}

static void OptionMenu_ResetSpriteData(void)
{
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetTasks();
    ScanlineEffect_Stop();
}

static bool8 LoadOptionMenuPalette(void)
{
    switch (sOptionMenuPtr->loadPaletteState)
    {
    case 0:
        LoadBgTiles(1, GetUserWindowGraphics(sOptionMenuPtr->optionPage1[PAGE1_FRAMETYPE])->tiles, 0x120, 0x1AA);
        break;
    case 1:
        LoadPalette(GetUserWindowGraphics(sOptionMenuPtr->optionPage1[PAGE1_FRAMETYPE])->palette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        break;
    case 2:
        LoadPalette(sOptionMenuPalette, BG_PLTT_ID(1), sizeof(sOptionMenuPalette));
        LoadPalette(GetTextWindowPalette(2), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        break;
    case 3:
        LoadStdWindowGfxOnBg(1, 0x1B3, BG_PLTT_ID(3));
        break;
    default:
        return TRUE;
    }
    sOptionMenuPtr->loadPaletteState++;
    return FALSE;
}

static void Task_OptionMenu(u8 taskId)
{
    switch (sOptionMenuPtr->loadState)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        OptionMenu_SetVBlankCallback();
        sOptionMenuPtr->loadState++;
        break;
    case 1:
        if (gPaletteFade.active)
            return;
        sOptionMenuPtr->loadState++;
        break;
    case 2:
        if (((bool32)IsActiveOverworldLinkBusy()) == TRUE)
            break;
        switch (OptionMenu_ProcessInput())
        {
        case NO_BUTTON_PRESSED:
            break;
        case A_B_PRESSED:
            sOptionMenuPtr->loadState++;
            break;
        case LEFT_RIGHT_PRESSED_ON_FRAME:
            LoadBgTiles(1, GetUserWindowGraphics(sOptionMenuPtr->optionPage1[PAGE1_FRAMETYPE])->tiles, 0x120, 0x1AA);
            LoadPalette(GetUserWindowGraphics(sOptionMenuPtr->optionPage1[PAGE1_FRAMETYPE])->palette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
            BufferOptionMenuString(sOptionMenuPtr->cursorPos);
            break;
        case UP_DOWN_PRESSED:
            UpdateSettingSelectionDisplay(sOptionMenuPtr->cursorPos);
            break;
        case LEFT_RIGHT_PRESSED:
            BufferOptionMenuString(sOptionMenuPtr->cursorPos);
            break;
        case SELECT_PRESSED:
            PrintOptionMenuHeader();
            LoadOptionMenuItemNames();
            BufferAllOptionMenuStrings();
            UpdateSettingSelectionDisplay(sOptionMenuPtr->cursorPos);
            break;
        }
        break;
    case 3:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        sOptionMenuPtr->loadState++;
        break;
    case 4:
        if (gPaletteFade.active)
            return;
        sOptionMenuPtr->loadState++;
        break;
    case 5:
        CloseAndSaveOptionMenu(taskId);
        break;
    }
}

static u8 OptionMenu_ProcessInput(void)
{ 
    u16 current;
    u16 *curr;
    u32 pageEnd = (currentOptionsPage == 0) ? PAGE1_CANCEL : PAGE2_CANCEL;

    if (JOY_REPT(DPAD_RIGHT))
    {
        if (currentOptionsPage == 0)
        {
            current = sOptionMenuPtr->optionPage1[(sOptionMenuPtr->cursorPos)];
            if (current == (sOptionMenuPage1ItemCounts[sOptionMenuPtr->cursorPos] - 1))
                sOptionMenuPtr->optionPage1[sOptionMenuPtr->cursorPos] = 0;
            else
                sOptionMenuPtr->optionPage1[sOptionMenuPtr->cursorPos] = current + 1;
            if (sOptionMenuPtr->cursorPos == PAGE1_FRAMETYPE)
                return LEFT_RIGHT_PRESSED_ON_FRAME;
        }
        else
        {
            current = sOptionMenuPtr->optionPage2[(sOptionMenuPtr->cursorPos)];
            if (current == (sOptionMenuPage2ItemCounts[sOptionMenuPtr->cursorPos] - 1))
                sOptionMenuPtr->optionPage2[sOptionMenuPtr->cursorPos] = 0;
            else
                sOptionMenuPtr->optionPage2[sOptionMenuPtr->cursorPos] = current + 1;
        }
        return LEFT_RIGHT_PRESSED;
    }
    else if (JOY_REPT(DPAD_LEFT))
    {
        if (currentOptionsPage == 0)
        {
            curr = &sOptionMenuPtr->optionPage1[sOptionMenuPtr->cursorPos];
            if (*curr == 0)
                *curr = sOptionMenuPage1ItemCounts[sOptionMenuPtr->cursorPos] - 1;
            else
                --*curr;

            if (sOptionMenuPtr->cursorPos == PAGE1_FRAMETYPE)
                return LEFT_RIGHT_PRESSED_ON_FRAME;
        }
        else
        {
            curr = &sOptionMenuPtr->optionPage2[sOptionMenuPtr->cursorPos];
            if (*curr == 0)
                *curr = sOptionMenuPage2ItemCounts[sOptionMenuPtr->cursorPos] - 1;
            else
                --*curr;
        }
        return LEFT_RIGHT_PRESSED;
    }
    else if (JOY_REPT(DPAD_UP))
    {
        if (sOptionMenuPtr->cursorPos == 0)
            sOptionMenuPtr->cursorPos = pageEnd;
        else
            sOptionMenuPtr->cursorPos = sOptionMenuPtr->cursorPos - 1;
        return UP_DOWN_PRESSED;
    }
    else if (JOY_REPT(DPAD_DOWN))
    {
        if (sOptionMenuPtr->cursorPos == pageEnd)
            sOptionMenuPtr->cursorPos = 0;
        else
            sOptionMenuPtr->cursorPos = sOptionMenuPtr->cursorPos + 1;
        return UP_DOWN_PRESSED;
    }
    else if (JOY_NEW(SELECT_BUTTON))
    {
        currentOptionsPage ^= 1;
        sOptionMenuPtr->cursorPos = 0;
        return SELECT_PRESSED;
    }
    else if (JOY_NEW(B_BUTTON) || JOY_NEW(A_BUTTON))
    {
        return A_B_PRESSED;
    }
    else
    {
        return NO_BUTTON_PRESSED;
    }
}

static void BufferOptionMenuString(u8 selection)
{
    u8 str[20];
    u8 buf[12];
    u8 dst[3];
    u8 x, y;
    
    memcpy(dst, sOptionMenuTextColor, 3);
    x = 0x82;
    y = ((GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT) - 1) * selection) + 2;
    FillWindowPixelRect(1, 1, x, y, 0x46, GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT));

    if (currentOptionsPage == 0)
    {
        switch (selection)
        {
        case PAGE1_TEXTSPEED:
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, sTextSpeedOptions[sOptionMenuPtr->optionPage1[selection]]);
            break;
        case PAGE1_MOVEMENTMODE:
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, sMovementModeOptions[sOptionMenuPtr->optionPage1[selection]]);
            break;
        case PAGE1_SOUND:
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, sSoundOptions[sOptionMenuPtr->optionPage1[selection]]);
            break;
        case PAGE1_BUTTONMODE:
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, sButtonTypeOptions[sOptionMenuPtr->optionPage1[selection]]);
            break;
        case PAGE1_FRAMETYPE:
            StringCopy(str, gText_FrameType);
            ConvertIntToDecimalStringN(buf, sOptionMenuPtr->optionPage1[selection] + 1, 1, 2);
            StringAppendN(str, buf, 3);
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, str);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (selection)
        {
        case PAGE2_STRONG_AI:
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, sStrongAIOptions[sOptionMenuPtr->optionPage2[selection]]);
            break;
        case PAGE2_BATTLESTYLE:
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, sBattleStyleOptions[sOptionMenuPtr->optionPage2[selection]]);
            break;
        case PAGE2_BATTLEITEMBAN:
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, sBattleItemBanOptions[sOptionMenuPtr->optionPage2[selection]]);
            break;
        case PAGE2_BATTLESCENE:
            AddTextPrinterParameterized3(1, FONT_NORMAL, x, y, dst, -1, sBattleSceneOptions[sOptionMenuPtr->optionPage2[selection]]);
            break;
        default:
            break;
        }
    }

    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void BufferAllOptionMenuStrings(void)
{
    u8 pageLength = (currentOptionsPage == 0) ? PAGE1_COUNT - 1 : PAGE2_COUNT - 1;
    u32 i;

    for (i = 0; i < pageLength; i++)
    {
        BufferOptionMenuString(i);
    }
}

static void CloseAndSaveOptionMenu(u8 taskId)
{
    gFieldCallback = FieldCB_DefaultWarpExit;
    SetMainCallback2(gMain.savedCallback);
    FreeAllWindowBuffers();

    // Save Options Page 1
    gSaveBlock2Ptr->optionsTextSpeed = sOptionMenuPtr->optionPage1[PAGE1_TEXTSPEED];
    (sOptionMenuPtr->optionPage1[PAGE1_MOVEMENTMODE] == 1) ? FlagSet(FLAG_MOVEMENTMODE) : FlagClear(FLAG_MOVEMENTMODE);
    gSaveBlock2Ptr->optionsSound = sOptionMenuPtr->optionPage1[PAGE1_SOUND];
    gSaveBlock2Ptr->optionsButtonMode = sOptionMenuPtr->optionPage1[PAGE1_BUTTONMODE];
    gSaveBlock2Ptr->optionsWindowFrameType = sOptionMenuPtr->optionPage1[PAGE1_FRAMETYPE];

    // Save Options Page 2
    (sOptionMenuPtr->optionPage2[PAGE2_STRONG_AI] == 1) ? FlagSet(FLAG_STRONG_AI) : FlagClear(FLAG_STRONG_AI);
    gSaveBlock2Ptr->optionsBattleStyle = sOptionMenuPtr->optionPage2[PAGE2_BATTLESTYLE];
    gSaveBlock2Ptr->optionsBattleItemBan = sOptionMenuPtr->optionPage2[PAGE2_BATTLEITEMBAN];
    gSaveBlock2Ptr->optionsBattleSceneOff = sOptionMenuPtr->optionPage2[PAGE2_BATTLESCENE];

    SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
    FREE_AND_SET_NULL(sOptionMenuPtr);
    DestroyTask(taskId);
}

static void PrintOptionMenuHeader(void)
{
    const u8 *optionsPageHeader = (currentOptionsPage == 0) ? gText_GeneralOption : gText_BattleOption;
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_TEXT_OPTION, FONT_NORMAL, optionsPageHeader, 8, 1, TEXT_SKIP_DRAW, NULL);
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void DrawOptionMenuBg(void)
{
    u8 h;
    h = 2;
    
    FillBgTilemapBufferRect(1, 0x1B3, 1, 2, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B4, 2, 2, 0x1B, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B5, 0x1C, 2, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1B6, 1, 3, 1, h, 3);
    FillBgTilemapBufferRect(1, 0x1B8, 0x1C, 3, 1, h, 3);
    FillBgTilemapBufferRect(1, 0x1B9, 1, 5, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1BA, 2, 5, 0x1B, 1, 3);
    FillBgTilemapBufferRect(1, 0x1BB, 0x1C, 5, 1, 1, 3);
    FillBgTilemapBufferRect(1, 0x1AA, 1, 6, 1, 1, h);
    FillBgTilemapBufferRect(1, 0x1AB, 2, 6, 0x1A, 1, h);
    FillBgTilemapBufferRect(1, 0x1AC, 0x1C, 6, 1, 1, h);
    FillBgTilemapBufferRect(1, 0x1AD, 1, 7, 1, 0x10, h);
    FillBgTilemapBufferRect(1, 0x1AF, 0x1C, 7, 1, 0x10, h);
    FillBgTilemapBufferRect(1, 0x1B0, 1, 0x13, 1, 1, h);
    FillBgTilemapBufferRect(1, 0x1B1, 2, 0x13, 0x1A, 1, h);
    FillBgTilemapBufferRect(1, 0x1B2, 0x1C, 0x13, 1, 1, h);
    CopyBgTilemapBufferToVram(1);
}

static void LoadOptionMenuItemNames(void)
{
    u32 i;
    
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    if (currentOptionsPage == 0)
    {
        for (i = 0; i < PAGE1_COUNT; i++)
        {
            AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sOptionMenuPage1ItemsNames[i], 8, (u8)((i * (GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT))) + 2) - i, TEXT_SKIP_DRAW, NULL);
        }
    }
    else
    {
        for (i = 0; i < PAGE2_COUNT; i++)
        {
            AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sOptionMenuPage2ItemsNames[i], 8, (u8)((i * (GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT))) + 2) - i, TEXT_SKIP_DRAW, NULL);
        }
    }
}

static void UpdateSettingSelectionDisplay(u16 selection)
{
    u16 maxLetterHeight, y;
    
    maxLetterHeight = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT);
    y = selection * (maxLetterHeight - 1) + 0x3A;
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(y, y + maxLetterHeight));
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0x10, 0xE0));
}
