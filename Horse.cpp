#include "Horse.h"
#include <cstdlib>  // rand()

Horse::Horse(std::string name)
    : name(name), position(0), finished(false) {}

void Horse::reset() {
    position = 0;
    finished = false;
}

void Horse::advance() {
    if (!finished && (std::rand() % 2 == 1)) {
        position++;
    }
}

int Horse::getPosition() const {
    return position;
}

bool Horse::hasFinished(int trackLength) const {
    return position >= trackLength;
}

std::string Horse::getName() const {
    return name;
}
