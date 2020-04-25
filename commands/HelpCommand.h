//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_HELPCOMMAND_H
#define TRAVELLER_S_APP_HELPCOMMAND_H

#include "ICommand.h"

class HelpCpmmand : public ICommand {
public:
    HelpCpmmand() : ICommand(string("help")) {};
    void execute(System &system) {
        assert(arguments.empty());

    }
};
#endif //TRAVELLER_S_APP_HELPCOMMAND_H
