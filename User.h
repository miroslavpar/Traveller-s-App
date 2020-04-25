//
// Created by Miroslav Parapanov on 2020-04-23.
//

#ifndef TRAVELLER_S_APP_USER_H
#define TRAVELLER_S_APP_USER_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class User {
private:
    string nickname;
    string email;
    string password;
    bool logged;
    vector<User>friends;

    void validatepass(string&);
public:
    User(const User&);
    User();
    User(string&,string&,string&);
    ~User(){};
    void createOwnDB();
    string getNickname()const;
    string getEmail() const;
    string getPass()const;
    void setNickname(string&);
    void setEmail(string&);
    void setPass(string&);
    bool getLogged()const;
    void  setLogged(bool);
    void addFriend(string&,string&,string&);
};


#endif //TRAVELLER_S_APP_USER_H
