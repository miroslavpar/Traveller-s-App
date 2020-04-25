//
// Created by Miroslav Parapanov on 2020-04-23.
//

#include "ICommand.h"
ICommand::ICommand(){}
ICommand::ICommand(const string& _commandName):commandName(_commandName){}
void ICommand::setArguments(vector<string> & _arguments) {
    this->arguments = _arguments;
}
string& ICommand::convertToString() {
    return commandName;
}

