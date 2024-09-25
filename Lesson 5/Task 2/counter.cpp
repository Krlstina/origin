#include <iostream>
#include "Counter.h"


Counter::Counter(int enterValue) : value{ enterValue } {}

void Counter::increaseValue() { ++value; }
void Counter::decreaseValue() { --value; }
void Counter::printValue() { std::cout << value << std::endl; }