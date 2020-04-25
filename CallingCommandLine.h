//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_CALLINGCOMMANDLINE_H
#define TRAVELLER_S_APP_CALLINGCOMMANDLINE_H
#include <vector>
#include "commands/ICommand.h"
#include <iostream>
using namespace std;
class CallingCommandLine {
private:
    vector<unique_ptr<ICommand>> commands;
    System system;
    void afterLogin();
    void parseLine(string&);
    void applyArguments(const string& commandName, vector<string> arguments);
public:
    CallingCommandLine(System& system);
    void run();
};


#endif //TRAVELLER_S_APP_CALLINGCOMMANDLINE_H
