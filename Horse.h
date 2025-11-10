#ifndef HORSE_H
#define HORSE_H

#include <string>

class Horse {
private:
    std::string name;
    int position;
    bool finished;

public:
    Horse(std::string name = "Horse");
    void reset();
    void advance();
    int getPosition() const;
    bool hasFinished(int trackLength) const;
    std::string getName() const;
};

#endif
