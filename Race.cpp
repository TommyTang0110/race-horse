#include "Race.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Race::Race() {
    for (int i = 0; i < NUM_HORSES; i++) {
        horses[i] = Horse("Horse " + std::to_string(i + 1));
    }
}

void Race::run() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    while (!hasWinner()) {
        for (int i = 0; i < NUM_HORSES; i++) {
            horses[i].advance();
        }
        printTrack();
    }

    printWinners();
}

void Race::printTrack() const {
    for (int i = 0; i < NUM_HORSES; i++) {
        std::cout << horses[i].getName() << ": ";
        int pos = horses[i].getPosition();
        for (int j = 0; j < pos; j++) std::cout << ".";
        std::cout << "🐎" << "\n";
    }
    std::cout << "---------------------\n";
}

bool Race::hasWinner() const {
    for (int i = 0; i < NUM_HORSES; i++) {
        if (horses[i].hasFinished(TRACK_LENGTH)) return true;
    }
    return false;
}

void Race::printWinners() const {
    std::cout << "Winner(s):\n";
    for (int i = 0; i < NUM_HORSES; i++) {
        if (horses[i].hasFinished(TRACK_LENGTH)) {
            std::cout << " - " << horses[i].getName() << "\n";
        }
    }
}
