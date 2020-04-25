#include <iostream>
#include "System.h"
#include "CallingCommandLine.h"

using namespace std;
int main() {
    System syss;
    CallingCommandLine sys(syss);
    sys.run();
    return 0;
}