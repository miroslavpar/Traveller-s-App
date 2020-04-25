//
// Created by Miroslav Parapanov on 2020-04-23.
//

#include <fstream>
#include "User.h"
User::User(const User& user){
    nickname = user.nickname;
    password = user.password;
    email = user.email;
    friends = user.friends;
    logged = user.logged;
}
void User::validatepass(string& _pass) {
    while(_pass.length() < 5){
        cout << " Password too short ! "<<endl;
        cout << " Please enter password: " <<endl;
        cout << "\t" << _pass << endl;
    }
    password = _pass;
}

User::User(){
    nickname = "";
    email = "";
    password = "";
    logged = false;
}
User::User(string& _nickname, string& _pass, string& _email){
    nickname = _nickname;
    validatepass(_pass);
    email = _email;
    logged = false;
}
void User::createOwnDB() {
    ofstream out(nickname + ".db.txt");
    out.close();
}
string User::getEmail() const {
    return email;
}
string User::getNickname() const {
    return nickname;
}
string User::getPass() const {
    return password;
}
void User::setEmail(string& _email) {
    email = _email;
}
void User::setNickname(string& _nickname) {
    nickname = _nickname;
}
void User::setPass(string& _pass) {
    password = _pass;
}
bool User::getLogged()const{
    return logged;
}
void User:: setLogged(bool _status){
    logged = _status;
}
void User::addFriend(string& _name,string& _password, string& _email) {
    User user(_name,_password,_email);
    friends.push_back(user);
}