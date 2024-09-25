#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
private:
    int value{};

public:
    Counter(int enterValue = 1);

    void increaseValue();
    void decreaseValue();
    void printValue();
};

#endif