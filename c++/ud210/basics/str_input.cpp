#include <iostream>
#include <string>

using namespace std;
int main() {
    string test;
    cout << "give me a string" << endl;
    // we are using this function for getting strings which includes spaces in them.
    // the standart cin function accepts a white space as end of the input.
    getline(cin, test);
    // default delimeter for getline function is '\n'
    // but we can determine a different delimeter by giving it as a third parameter to the function
    // getline(cin, test, '\t');
    cout << "the given string: " << test << endl;
    return 0;
}
