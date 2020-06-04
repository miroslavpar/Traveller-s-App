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
    holidays = user.holidays;
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
    ifstream iFile(nickname + ".db.txt",ios::in);
    double rating;
    string city,country, arrivingDate, leavingDate, comment, photo;
    while(!iFile.eof()){
        iFile >> city >> country >> arrivingDate >> leavingDate >> rating >> comment >> photo;
        Holiday holiday(city,country,arrivingDate,leavingDate,rating,comment,photo);
        holidays.push_back(holiday);
    }
    iFile.close();
}
User::User(string& _nickname, string& _pass, string& _email){
    nickname = _nickname;
    validatepass(_pass);
    email = _email;
    logged = false;
    ifstream iFile(nickname + ".db.txt",ios::in);
    double rating;
    string city,country, arrivingDate, leavingDate, comment, photo;
    while(!iFile.eof()){
        iFile >> city >> country >> arrivingDate >> leavingDate >> rating >> comment >> photo;
        Holiday holiday(city,country,arrivingDate,leavingDate,rating,comment,photo);
        holidays.push_back(holiday);
    }
    iFile.close();
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
void User::setEmail(const string& _email) {
    email = _email;
}
void User::setNickname(const string& _nickname) {
    nickname = _nickname;
}
void User::setPass(const string& _pass) {
    password = _pass;
}
bool User::getLogged()const{
    return logged;
}
void User:: setLogged(bool _status){
    logged = _status;
}
void User::addFriend(string& _name,string& _password,string& _email) {
    User user(_name,_password,_email);
    friends.push_back(user);
}
void User::showFriendInfo(const string& friendName, const string& destination) const {
    for(auto& it: friends){
        if(friendName == it.getNickname()) {
            it.getHolidayComment(destination);
            return;
        }
    }
    cerr << friendName << " is not a friend to " << nickname <<endl;
}
void User::getHolidayComment(const string& dest)const{
    bool flag = false;
    for(auto&it:holidays){
        if(it.getCity() == dest){
            cout << it.getComment() << endl;
            flag = true;
        }
    }
    if(!flag) {
        cout << " User's database is empty\n";
    }
}
