#include <iostream>
#include "System.h"
#include "CallingCommandLine.h"

using namespace std;
int main() {
    System system;
    CallingCommandLine sys(system);
    sys.run();
    return 0;
}