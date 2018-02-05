/*Now I would like you to do a switch statement with breaks
**between the cases. Create a program that asks the user for
**two float numbers. Then asks the user if they would like to:
**add the numbers, subtract the numbers, multiply the numbers,
**divide the numbers.
**The program should then print the numbers with the chosen
**operation and the solution.
*/

#include <iostream>

int main() {
    float in_1, in_2;
    char op;
    std::cout << "Enter two numbers:\n";
    std::cin >> in_1;
    std::cin >> in_2;
    std::cout << "Enter the operation '+','-','*','/':\n";
    std::cin >> op;
    switch(op) {
        case('+'):
            std::cout << in_1 + in_2 << std::endl;
            break;
        case('-'):
            std::cout << in_1 - in_2 << std::endl;
            break;
        case('*'):
            std::cout << in_1 * in_2 << std::endl;
            break;
        case('/'):
            std::cout << in_1 / in_2 << std::endl;
            break;
        default:
            std::cout << "Please give a valid character" << std::endl;
    }
    return 0;
}
