//
// Created by Miroslav Parapanov on 2020-06-04.
//


#ifndef TRAVELLER_S_APP_SHOWCOMMAND_H
#define TRAVELLER_S_APP_SHOWCOMMAND_H
#include "ICommand.h"

class ShowCommand: public ICommand {
public:
    ShowCommand() : ICommand(string("show")) {};
    void execute(System &system) {
        assert(arguments.size() == 1);
        system.show(arguments[0]);
    }
};
#endif //TRAVELLER_S_APP_SHOWCOMMAND_H
