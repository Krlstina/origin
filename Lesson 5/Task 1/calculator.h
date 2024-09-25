#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
private:
    int num1{};
    int num2{};

public:
    Calculator(int num1, int num2);
    int add();
    int multiply();
    int subtract();
    double divide();
    double exponentiation();
};

#endif