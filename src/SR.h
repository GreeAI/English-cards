#ifndef SR_H
#define SR_H

#include "cards.h"

class SRLEG{
public:
    SRLEG() = default;

    static time_t processingDate(uint8_t sr) {
        time_t now = time(nullptr);

        int daysToAdd;
            
        switch(sr) {
            case 1: daysToAdd = 1; break;
            case 2: daysToAdd = 3; break;
            case 3: daysToAdd = 7; break;
            case 4: daysToAdd = 14; break;
            case 5: daysToAdd = 28; break;
            default: daysToAdd = 1;
        }

        time_t nextReview = now + (daysToAdd * 86400);

        return nextReview;
    }
private: 
};

#endif // SR_H
