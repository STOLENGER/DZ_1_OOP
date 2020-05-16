#include <iostream>
#include "Application.h"
using namespace std;
int main() {
    Application c;
    c.run2();
    try {
        c.run1();
        c.run2();
        c.run3();
    } catch (const std::exception&) {

    }
    return 0;
}
