//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_FRIENDCOMMAND_H
#define TRAVELLER_S_APP_FRIENDCOMMAND_H


#include "ICommand.h"

class FriendCommand: public ICommand {
public:
    FriendCommand() : ICommand(string("friend")) {};
    void execute(System &system) {
        assert(arguments.size() == 1);
        system.friends(arguments[0]);
    }
};


#endif //TRAVELLER_S_APP_FRIENDCOMMAND_H
