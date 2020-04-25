//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_LOGINCOMMAND_H
#define TRAVELLER_S_APP_LOGINCOMMAND_H


#include "ICommand.h"

class LoginCommand: public  ICommand {
public:
    LoginCommand() : ICommand(string("login")) {};
    void execute(System &system) {
        assert(arguments.size() == 2);
        system.logIn(arguments[0],arguments[1]);
    }
};


#endif //TRAVELLER_S_APP_LOGINCOMMAND_H
