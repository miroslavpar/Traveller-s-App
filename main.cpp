#include <iostream>
#include <fstream>
#include "System.h"
#include "CallingCommandLine.h"
#include "Holiday.h"
using namespace std;
int main() {
    System system;
    CallingCommandLine sys(system);
    sys.run();
//    string city = "Plovdiv",country = " Bulgaria";
//    Place* place;
//    const char*
//    ofstream oFile("test.bin",ios::out | ios::binary);
//    oFile.write((const char*)&place,sizeof(Place));
//    oFile.close();
    return 0;
}