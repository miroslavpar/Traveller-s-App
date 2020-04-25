//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_ICOMMAND_H
#define TRAVELLER_S_APP_ICOMMAND_H
#include <string>
#include <vector>
#include "../System.h"
using namespace std;

class ICommand {
    protected:
        string commandName;
        vector<string> arguments;
    public:
        ICommand();
        ICommand(const string&);
        virtual void execute(System&){};
        void setArguments(vector<string>&);
        string& convertToString();
        virtual ~ICommand() {};
};


#endif //TRAVELLER_S_APP_ICOMMAND_H
