//
// Created by Miroslav Parapanov on 2020-04-24.
//

#ifndef TRAVELLER_S_APP_EXITACCOUNTCOMMAND_H
#define TRAVELLER_S_APP_EXITACCOUNTCOMMAND_H

#include "ICommand.h"

class ExitAccountCommand: public ICommand{
public:
    ExitAccountCommand() : ICommand(string("logout")) {};
    void execute(System &system) {
        assert(arguments.size() == 1);
        system.logout(arguments[0]);
    }
};
#endif //TRAVELLER_S_APP_EXITACCOUNTCOMMAND_H
