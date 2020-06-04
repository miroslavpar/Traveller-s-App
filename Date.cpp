//
// Created by Miroslav Parapanov on 2020-06-02.
//

#include "Date.h"
bool Date::validate(int _date, int _month, int _year){
    return _date <= 31 && _date >= 31 && _month <= 12 && _month >=1  && _year >=2010;
}
int Date::getDate() const {
    return  date;
}
int Date::getMonth() const {
    return month;
}
int Date::getYear() const {
    return year;
}
Date::Date(int tempdate, int tempmonth, int tempyear) {
    if (!validate(tempdate,tempmonth,tempyear)){
        cerr << "Not valid dates\n";
        return;
    }
    else {
        date = tempdate;
        month = tempmonth;
        year = tempyear;
    }
}
bool Date::operator<(const Date & obj) {
    return (this->date < obj.date && this->month < obj.month &&this->year < obj.year);
}
void Date::setDate(int _date) {
    date = _date;
}
void Date::setMonth(int _month) {
    month = _month;
}
void Date::setYear(int _year) {
    year = _year;
}