//
// Created by Miroslav Parapanov on 2020-04-23.
//

#include <sstream>
#include <iomanip>
#include "CallingCommandLine.h"
#include "commands/RegistrationCommand.h"
#include "commands/LoginCommand.h"
#include "commands/FriendCommand.h"
#include "commands/ExitAccountCommand.h"
#include "commands/HelpCommand.h"


CallingCommandLine::CallingCommandLine(System& _system):system(_system) {
    commands.push_back(std::make_unique<RegistrationCommand>());
    commands.push_back(std::make_unique<LoginCommand>());
    commands.push_back(std::make_unique<FriendCommand>());
    commands.push_back(std::make_unique<ExitAccountCommand>());
    commands.push_back(std::make_unique<HelpCommand>());

}
string takeCommand(string command){
    stringstream stream;
    stream << command;
    stream>>command;
    return command;
}
void menu(){
    cout <<"\n"<<setw(70)<< "Welcome to Traveller's app\n";
    cout << "\nPlease enter command. If you don't know the commands and their usage, please type help.\n";
}
void CallingCommandLine::afterLogin() {
    string line, command;
    do{
        cout << system.getNameOfloggeduser() << " $: ";
        getline(cin, line);
        command = takeCommand(line);
        parseLine(line);
    }
    while(command != "logout");
}
void CallingCommandLine::run() {
    string line,command;
    menu();
    for(;;){
        cout << "$: ";
        getline(cin, line);
        command = takeCommand(line);
        if (command == "help") {
            parseLine(line);
            continue;
        }
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
    applyArguments(commandName, arguments);
}
void CallingCommandLine::applyArguments(const string &commandName, vector<string> arguments) {
    int counter = 0;
    for(auto& command: commands) {
        if(command->convertToString() == commandName) {
            command->setArguments(arguments);
            command->execute(system);
            counter++;
        }
    }
    if(counter == 0){
        cout << "\tWRONG COMMAND\t\n"
                "Please use \"help\" command\n";
    }
}
