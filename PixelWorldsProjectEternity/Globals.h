#ifndef GLOBALS_H
#define GLOBALS_H

static int fpsOptions = 0;

void *LocalPlayerInstantiate = nullptr;
void *MyPlayerData = nullptr;
void *WorldInstantiate = nullptr;
void *WorldControllerInstantiate = nullptr;
void *ZoomSlider = nullptr;
void *FishingGaugeMinigameUIInstantiate = nullptr;
void *GameplayUIInstantiate = nullptr;

monoList<void **> *collectables = nullptr;

int worldType;

double deltaTime = 0.016666;

static bool checkIsPlayerInMenu = false;

static int playerMaxHealth;

Vector2i getCurrentWorldSize;
Vector2i MyMapPoint;
Vector2 MyMapPointVec2, MyWorldToScreenVec2;
Vector3 MyPositionOK;

static bool EnableDisableAiEnemy = false;

static bool EnableAutoSearchNetherBoss = false;
static bool NetherBossFound = true;
static bool ReloadWorldNetherBoss = false;
static bool isReloadOptionsMenuOpen = false;
static bool EnableNetherAimbot = false;
static bool EnableAutoClaimNetherGiftBox = false;
static bool EnableAutoBreakNetherTreasureBox = false;

float NetherBeforeStart = 15.0f;
float NetherActionTimer = 0.0f;
float NetherActionDelay = 0.150f;

void *CloserMonster = nullptr;

int PixelPerfectCamera_cameraZoom;
Vector2 PixelPerfectCamera_cameraOrigin;
float tileSizeXVal = 0.32f, tileSizeYVal = 0.32f, worldScaleValue = 100.0f;

void *MineClosestMonster = nullptr;
void *MineSafestMonster = nullptr;

static bool EnableAutoMine = false;
static bool EnableMineAutoCollect = false;
static bool EnableAutoBreakGemstone = false;
static bool EnableAutoBreakCrate = false;
static bool EnableAutoKillMonster = false;

static bool exitOnce = false;
static bool repairOnce = false;

bool EnableJumpButton = false;

static int current_pickaxe;
static int PickaxeID;

static float MineActionTimer = 0.0f;
static float MineActionCooldown = 0.150f;

static bool SafestAutoMine = true;
float MineBeforeStart = 15.0f;
Vector2i SafestTargetActionMapPoint;

static bool EnableAntiInvertedControls = false;
static bool EnableAntiPortal = false;
static bool EnableAntiCheckPoint = false;
static bool EnableAntiPickup = false;
static bool DoLogOutOnce = false;
static bool EnableUnlockAllRecipes = false;
static bool EnableAlwaysLightOn = false;
static bool EnableAlwaysFogOff = false;
static bool EnableAntiAFKKick = false;
static bool EnableAntiWordCensor = false;
static bool EnableCanPlaceSeedOnTop = false;

static bool EnableToSelectDrop = false;
float DropDelay = 1.000f;
float DropTimer = 0.000f;

static bool EnableAntiLavaBounce = true;
static bool EnableAntiBounce = false;
static bool EnableAntiElastic = false;
static bool EnableAntiPinball = false;
static bool EnableAntiTrampolin = false;
static bool EnableAntiWind = false;
static bool EnableAntiDeflector = false;
static bool EnableAntiElevator = false;

static float setRunSpeed = 1.8f;

static int SetHealthPercentForHeal = 0;
static int LastAutoHeal = 0;

static bool canHeal = false;

static bool EnableSuperHeroAimbot = false;
static bool EnableSuperHeroAutoCollectGiftBox = false;
static float superHeroActionDelay = 0.150f;
static float SuperHeroTimer = 0.0f;
Vector2i MyMapPointInSB;

const char *PlayerName = OBFUSCATE("Modded By 0xCsy");
static float setFistCooldown = 1.0f;
static int setJumpModeID = 0;
static int setGravityModeID = 0;

Vector2 SpiritVec2;
Vector2i SpiritVec2i;

static bool EnableZoomHack = false;

const char* GiftBoxItems[] = {"None", "None", "None", "None", "None"};

float boxSizeY;

static bool EnableManuallyReloadNetherWorld = false;
static bool EnableVisualRight = false;
static int setBackground = 0;
static int setWeather = 0;
static int setLighting = 0;

static bool EnableDrawVisualBlock = false;

static int setVisualBlockType = 0;

static int VisualItemTouchMapPointState = 1;

static int BlockToRemoveState = 0;

Vector2i VisualItemTouchMapPoint = {};
Vector2i VisualItemTouchMapPoint2 = {};
Vector2i VisualItemMapPoint = Vector2i{-1, -1};

static bool refreshEntity = false;

static bool EnableTeleportation = false;

static int TPTouchMapPointState = 1;

Vector2i currentTPTouchMapPoint = {};
Vector2i currentTPTouchMapPoint2 = {};
Vector2i finalTPMapPoint = Vector2i{-1, -1};

#endif
