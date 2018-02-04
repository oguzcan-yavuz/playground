/*Formatting Output
**Goal: practice using cout to format output to console
**Print the variables in three columns:
**Ints, Floats, Doubles
*/

#include <iostream>
#include <iomanip>

int main() {
    int a = 45;
    float b = 45.323;
    double c = 45.5468;
    int aa = a + 9;
    float bb = b + 9;
    double cc = c + 9;
    int aaa = aa + 9;
    float bbb = bb + 9;
    double ccc = cc + 9;
    std::cout << a << std::setw(10) << b << std::setw(10) << c << std::endl;
    std::cout << aa << "\t" << bb << "\t" << cc << std::endl;
    std::cout << aaa << " " << bbb << " " << ccc << std::endl;
    return 0;
}
