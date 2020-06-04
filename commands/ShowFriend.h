//
// Created by Miroslav Parapanov on 2020-06-04.
//

#ifndef TRAVELLER_S_APP_SHOWFRIEND_H
#define TRAVELLER_S_APP_SHOWFRIEND_H


#include "ICommand.h"

class ShowFriend: public ICommand {
public:
    ShowFriend() : ICommand(string("showfriend")) {};
    void execute(System &system) {
        assert(arguments.size() == 2);
        system.showFriendDest(arguments[0], arguments[1]);
    }
};
#endif //TRAVELLER_S_APP_SHOWFRIEND_H
