#include "calculator.h"
#include <string>

Calculator::Calculator(int num1, int num2) : num1{num1}, num2{num2} {}
int Calculator::add() { return (num1 + num2); }
int Calculator::multiply() { return (num1 * num2); }
int Calculator::subtract() { return (num1 - num2); }
double Calculator::divide() { return (num1 / num2); }
double Calculator::exponentiation()
{
    int degree{ num2 };
    double result{ 1 };
    if (degree == 0) { return result; }
    if (degree < 0 ) {
        while (degree < 0)
        {
            result /= num1;
            degree += 1;
        }
    }
    else {
        while (degree > 0)
        {
            result *= num1;
            degree -= 1;
        }
    }
    return result;
}