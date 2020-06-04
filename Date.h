//
// Created by Miroslav Parapanov on 2020-06-02.
//

#ifndef TRAVELLER_S_APP_DATE_H
#define TRAVELLER_S_APP_DATE_H

using namespace std;
#include <iostream>

class Date {
private:
    int date;
    int month;
    int year;
    bool validate(int,int,int);
public:
    Date() = default;
    Date(int ,int, int);
    int getDate()const;
    int getMonth()const;
    int getYear()const;
    bool operator<(const Date&);
    void setDate(int);
    void setMonth(int);
    void setYear(int);

};


#endif //TRAVELLER_S_APP_DATE_H
