//
// Created by Miroslav Parapanov on 2020-05-26.
//

#ifndef TRAVELLER_S_APP_HOLIDAY_H
#define TRAVELLER_S_APP_HOLIDAY_H

#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"

using namespace std;

class Holiday {
private:
    string city;
    string country;
    Date arrivingDate;
    Date leavingDate;
    double rating;
    string comment;
    string photos;

    bool validatePhotos(const string&)const;
public:
    Holiday() = default;
    Holiday(string&, string& ,string&, string&, double, string&, string&);
    string getCity()const;
    string getComment()const;
};

#endif //TRAVELLER_S_APP_HOLIDAY_H
