#ifndef RACE_H
#define RACE_H

#include "Horse.h"

class Race {
private:
    static const int NUM_HORSES = 5;
    static const int TRACK_LENGTH = 20;
    Horse horses[NUM_HORSES];

public:
    Race();
    void run();
    void printTrack() const;
    bool hasWinner() const;
    void printWinners() const;
};

#endif
