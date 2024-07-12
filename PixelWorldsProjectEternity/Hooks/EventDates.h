#ifndef CSY_EVENTDATES_H
#define CSY_EVENTDATES_H

void Next_EvenDate()
{
    //StPatricks = 2
    LOGI("PW -> St. Patrick's Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(2, false)));
    //EasterEggHunt = 3
    LOGI("PW -> Easter Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(3, false)));
    //Summer = 4
    LOGI("PW -> Summer Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(4, false)));
    //HalloweenSpirits = 5
    LOGI("PW -> Halloween Spirits Will Start On The %s", getTime(EventDates_GetEventStartDateTime(5, false)));
    //HalloweenTower = 6
    LOGI("PW -> Halloween Black Tower Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(6, false)));
    //ThanksGiving = 7
    LOGI("PW -> Thanks Giving Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(7, false)));
    //FindependenceDay = 8
    //LOGI("PW -> Suomi Finland 100 Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(8)));
    //XmasSnowflakes = 9
    LOGI("PW -> Catch a Snowflake! Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(9, false)));
    //PixelWorldsAnniversary = 10
    LOGI("PW -> Anniversary Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(10, false)));
    //ValentinesDay = 11
    LOGI("PW -> Valentine's Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(11, false)));
    //CommissionEvent = 12
    LOGI("PW -> Market Madness Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(12)));
    //ButterflyEvent = 13
    //LOGI("PW -> Butterfly Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(13, false)));
    //FridayTheThirteenth = 14
    LOGI("PW -> Friday the 13th Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(14, false)));
    //CincoDeMayo = 15
    LOGI("PW -> Once De Mayo Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(15, false)));
    //SuperHero = 16
    LOGI("PW -> Superhero Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(16, false)));
    //FlowersOfSummer = 17
    LOGI("PW -> Flowers of Summer! Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(17, false)));
    //ArchaeologyBoost = 18
    LOGI("PW -> Archaeology Bone Boost Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(18)));
    //GraffitiBoost = 19
    LOGI("PW -> Spray Can Drop Boost Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(19)));
    //RiftEvent = 20
    //LOGI("PW -> Rift Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(20, false)));
    //TreasureBoost = 21
    LOGI("PW -> Treasure Hunt Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(21)));
    //ChineseNewYear = 22
    LOGI("PW -> Lunar New Year Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(22, false)));
    //FishingPiranha = 23
    LOGI("PW -> Perilous Piranhas Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(23, false)));
    //NetherBossWraith = 24
    LOGI("PW -> Netherworld Miniboss Hunt Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(24, false)));
    //FarmingFrenzy = 25
    LOGI("PW -> Farming Frenzy! Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(25)));
    //ClanXPBoost = 26
    LOGI("PW -> Clan XP Boost! Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(26)));
    //GoneFishing = 27
    LOGI("PW -> Gone Fishing! Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(27)));
    //PotionBoost = 28
    LOGI("PW -> Double Potion Boost! Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(28)));
    //ButterflySeason = 29
    LOGI("PW -> Butterfly season! Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(29)));
    //ClanGemBoost = 30
    LOGI("PW -> Clan Gem Boost! Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(30)));
    //RecycleEvent = 31
    LOGI("PW -> Please Recycle! Event Will Start On The %s", getTime(EventDates_GetMiniEventNextStartTime(31)));
    //JetRaceDiscount = 32
    //LOGI("PW -> Jet Race Discount Event Will Start On The %s", getTime(EventDates_GetEventStartDateTime(32, false)));

    //PetOwnersDay = 1
    LOGI("PW -> Pet Owner's Day Event Will Start On The %s", getTime(EventDates_GetEventStartDateTimeExtra(1, false)));
    //FourthOfJuly = 2
    LOGI("PW -> Celebrate the 4th of July! Event Will Start On The %s", getTime(EventDates_GetEventStartDateTimeExtra(2, false)));
    //XmasCalendar = 3
    LOGI("PW -> X-Mas Daily Bonus Event Will Start On The %s", getTime(EventDates_GetEventStartDateTimeExtra(3, false)));
    //Fireworks = 4
    LOGI("PW -> Fireworks Super Sale Event Will Start On The %s", getTime(EventDates_GetEventStartDateTimeExtra(4, false)));
    //FishingTournament = 5
    LOGI("PW -> Fishing Tournament Will Start On The %s", getTime(EventDates_GetEventStartDateTimeExtra(5, false)));
    //ValentinesDaySelfie = 6
    //LOGI("PW -> Valentine's Selfie Contest Event Will Start On The %s", getTime(EventDates_GetEventStartDateTimeExtra(6, false)));
    //TheBestSet = 7
    LOGI("PW -> The Best Set Event Will Start On The %s", getTime(EventDates_GetEventStartDateTimeExtra(7, false)));
    //CardSeason = 8
    LOGI("PW -> Battle Cards Tournament Will Start On The %s", getTime(EventDates_GetEventStartDateTimeExtra(8, false)));
}

#endif
