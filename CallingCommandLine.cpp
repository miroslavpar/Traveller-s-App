//
// Created by Miroslav Parapanov on 2020-04-23.
//

#include <sstream>
#include "CallingCommandLine.h"
#include "commands/RegistrationCommand.h"
#include "commands/LoginCommand.h"
#include "commands/FriendCommand.h"
#include "commands/ExitAccountCommand.h"

string name;

CallingCommandLine::CallingCommandLine(System& _system):system(_system) {
    commands.push_back(std::make_unique<RegistrationCommand>());
    commands.push_back(std::make_unique<LoginCommand>());
    commands.push_back(std::make_unique<FriendCommand>());
    commands.push_back(std::make_unique<ExitAccountCommand>());
}
string takeCommand(string command){
    stringstream stream;
    stream << command;
    stream>>command;
    return command;
}
void CallingCommandLine::afterLogin() {
    string line, command;
    do{
        cout << name << " $: " << endl;
        getline(cin, line);
        command = takeCommand(line);
        parseLine(line);
    }
    while(command != "logout");
    name.clear();
}
void CallingCommandLine::run() {
    string line,command;
    for(;;){
        cout << "$: " << endl;
        getline(cin, line);
        command = takeCommand(line);
        if(command != "registration" && command != "login"){
            cout << " Please first registrate or login ! " <<endl;
            continue;
        }
        if (command == "login") {
            parseLine(line);
            if(!system.getWrongConnection())
                afterLogin();
            continue;
        }
        parseLine(line);
    }
}
void CallingCommandLine::parseLine(string& line) {
    stringstream stream;
    stream << line;
    string commandName;
    stream >> commandName;
    vector<string> arguments;
    string argument;
    while(stream >> argument) {
        arguments.push_back(argument);
    }
    name = arguments[0];
    applyArguments(commandName, arguments);
}
void CallingCommandLine::applyArguments(const string &commandName, vector<string> arguments) {
    for(auto& command: commands) {
        if(command->convertToString() == commandName) {
            command->setArguments(arguments);
            command->execute(system);
        }
    }
}
