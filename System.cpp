//
// Created by Miroslav Parapanov on 2020-04-23.
//

#include "System.h"
#include <fstream>
const char* USERS_DATABASE_FILE = "users.db.txt";
System::System() {
    wrongConnection = false;
    nameOfLoggedUser = "";
}
System::~System() {}
void System::help() {
    cout << "Commands : \n"
            "\t\tregistration <nickname> <password> <email>\n"
            "\t\tlogin <nickname> <password>\n"
            " IF LOGGED IN : \n"
            "\t\tfriend <nickname> \n"
            "\t\tlogout <yours_nickname> logouts of user\n";
    cout << "\nUPGRADES ARE COMMIGN SOON!!!!!\n";


}
void System::logout(string & name) {
    if(!isLogged()){
        cout << " You are not logged in yet in order to logout.\n";
        return;
    }
    if(!isExisting(name)){
        cout << " User with this name does not exist in order to be logged out.\n ";
        return;
    }
    for(auto& it : users){
        if(it.getNickname() == name){
            it.setLogged(false);
            cout << " Successfully logged out. " << it.getNickname() << "\n";
            nameOfLoggedUser.clear();
        }
    }
}
bool System::isDuplicate(string& _nickname, string& _pass, string& _email){
    for (auto& it : users) {
        if(it.getNickname() == _nickname) {
            cout << " User with this nickname already exists ! \n";
            return true;
        }
        if(it.getEmail() == _email) {
            cout << " User with this email already exists ! \n";
            return true;
        }
    }
    return false;
}
User System::getUserByName(string& _name){
    for(auto& it : users){
        if(it.getNickname() == _name){
            return it;
        }
    }
}
bool System::isLogged(){
    for (auto& it : users){
        if(it.getLogged()){
            return true;
        }
    }
    return false;
}
void System::registration (string& _nickname, string& _pass, string& _email) {
    if(isLogged()){
        cout << " Cannot use command \"registration\" when you are logged in!\n";
        return;
    }
    if(isDuplicate(_nickname, _pass, _email)){
        return;
    }
    User user(_nickname, _pass, _email);
    user.createOwnDB();
    nameOfLoggedUser = _nickname;
    users.push_back(user);
    ofstream out (USERS_DATABASE_FILE, ios::app);
    if(!out) {
        cout << " Please reload. ERROR ERROR ERROR \n";
        return;
    }
    out << _nickname << endl << _pass <<endl << _email << endl;
    out.close();
    cout << " Successfully registered with name. " << user.getNickname() << endl;
    cout << " Please check your email. \n";
    wrongConnection = false;
}
void System::logIn(string& _nickname, string& _pass) {
    if(isLogged()){
        cout << " You are already logged in ! \n";
        wrongConnection = true;
        return;
    }
    ifstream in (USERS_DATABASE_FILE, ios::in);
    if(!in){
        cout << " Something went wrong! Maybe there is no one registered yet. \n" ;
        wrongConnection = true;
        return;
    }
    string nick, password,email;
    while(!in.eof()){
        in >> nick;
        if(nick == _nickname){
            in >> password;
            if(password != _pass){
                cout << " Wrong password! \n";
                return;
            }
            else {
                cout << " Successfully logged in " << _nickname << " 🙂\n";
                for (auto& it : users){
                    if(it.getNickname() == _nickname){
                        it.setLogged(true);
                        wrongConnection = false;
                    }
                }
                return;
            }
        }
        in >> password;
        in >> email;
    }
    wrongConnection = true;
    cout << " No user found please. Please try again! \n";
}
bool System::isExisting(string & _name) {
    for(auto& it : users){
        if(it.getNickname() == _name){
            return true;
        }
    }
    return false;
}
void System::friends(string& _name) {
    if(!isExisting(_name)){
        cout << " User with name " << _name << " is not found." << " 🙁\n";
        return;
    }
    if (!isLogged()){
        cout << " You are not logged ! " << endl;
        return;
    }
    User user = getUserByName(_name);
    string name,pass,email;
    for(auto& it :users){
        if(it.getLogged()){
            name = user.getNickname();
            pass = user.getPass();
            email = user.getEmail();
            it.addFriend(name,pass,email);
        }
    }
    name.clear();pass.clear();email.clear();
    name = user.getNickname();
    pass = user.getPass();
    email = user.getEmail();
    user.addFriend(name,pass,email);
    cout << nameOfLoggedUser << " you have successfully become friends with " << _name << " 🙂\n";
}
bool System::getWrongConnection() {
    return wrongConnection;
}
string System::getNameOfloggeduser(){
    return nameOfLoggedUser;
}
