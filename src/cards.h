#ifndef CARDS_H
#define CARDS_H

#include <cstdint>
#include <string>
#include <time.h>

struct Card
{
    uint16_t id;
    std::string en;
    std::string ru;
    uint8_t sr;
    time_t nextReview;
};

#endif // CARDS_H
