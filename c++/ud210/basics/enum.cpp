#include <iostream>

using namespace std;
int main() {
    enum MONTH {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    MONTH best_month = Jan;
    if(best_month == Jan) {
        cout << "I am not sure if January is the best month" << endl;
    }
    return 0;
}
