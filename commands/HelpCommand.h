//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_HELPCOMMAND_H
#define TRAVELLER_S_APP_HELPCOMMAND_H

#include "ICommand.h"

class HelpCommand : public ICommand {
public:
    HelpCommand() : ICommand(string("help")) {};
    void execute(System &system) {
        assert(arguments.empty());
        system.help();
    }
};
#endif //TRAVELLER_S_APP_HELPCOMMAND_H
