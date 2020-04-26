//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_SYSTEM_H
#define TRAVELLER_S_APP_SYSTEM_H


#include "User.h"

class System {
private:
    vector<User> users;
    bool wrongConnection;
    string nameOfLoggedUser;
    bool isDuplicate(string&, string&, string&);
    bool isExisting(string&);
    bool isLogged();
public:
    System();
    ~System();
    void help();
    void logout(string&);
    User getUserByName(string&);
    void registration(string&,string&,string&);
    void logIn(string&,string&);
    void friends(string&);
    bool getWrongConnection();
    string getNameOfloggeduser();
};


#endif //TRAVELLER_S_APP_SYSTEM_H
