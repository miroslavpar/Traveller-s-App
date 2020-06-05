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
    bool isDuplicate(const string&,const string&,const string&)const;
    bool isExisting(const string&)const;
    bool isLogged()const;
public:
    System();
    ~System();
    void help()const;
    void logout(const string&);
    User getUserByName(const string&)const;
    void registration(string&, string&, string&);
    void logIn(const string&,const string&);
    void friends(const string&);
    bool getWrongConnection()const;
    string getNameOfloggeduser()const;
    void showFriendDest(const string&,const string&)const;
    void show(const string&)const;
};


#endif //TRAVELLER_S_APP_SYSTEM_H
