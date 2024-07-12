#ifndef CSY_PROFANITYFILTER_H
#define CSY_PROFANITYFILTER_H

void (*old_ProfanityFilter_Censor)(void *instance);
void ProfanityFilter_Censor(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAntiWordCensor)
        {
            return;
        }
    }
    old_ProfanityFilter_Censor(instance);
}

#endif
