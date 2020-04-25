//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_REGISTRATIONCOMMAND_H
#define TRAVELLER_S_APP_REGISTRATIONCOMMAND_H


#include "ICommand.h"

class RegistrationCommand: public ICommand {
public:
    RegistrationCommand(): ICommand (string("registration")) {};
    void execute(System& system) {
        assert(arguments.size() == 3);
        system.registration(arguments[0], arguments[1],arguments[2]);
    }
};


#endif //TRAVELLER_S_APP_REGISTRATIONCOMMAND_H
