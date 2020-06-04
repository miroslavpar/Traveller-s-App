//
// Created by Miroslav Parapanov on 2020-05-26.
//

#include <vector>
#include "Holiday.h"
const int DURATION_DAYS = 2;
vector<int> toInt(const string& date){
    int size = date.size();
    int res = 0;
    vector<int> dayMonthYear;
    for(size_t i = 0 ; i <= size ; i++){
        if(date[i] == '.' || i == size) {
            dayMonthYear.push_back(res);
            res = 0;
        }
        else{
            res = 10 * res + (date[i] - '0');
        }
    }
    return dayMonthYear;
}
Holiday::Holiday(string& _city, string& _country,string& _arrivingDate, string& _leavingDate,double _rating,string& _comment,string& _photos):
city(_city),country(_country),rating(_rating),comment(_comment),photos(_photos) {
    vector<int> firstDate, secondDate;
    firstDate = toInt(_arrivingDate);
    secondDate = toInt(_leavingDate);
    arrivingDate.setDate(firstDate[0]);
    arrivingDate.setMonth(firstDate[1]);
    arrivingDate.setYear(firstDate[2]);
    leavingDate.setDate(secondDate[0]);
    leavingDate.setMonth(secondDate[1]);
    leavingDate.setYear(secondDate[2]);
    if(leavingDate < arrivingDate){
        cerr << "Invalid period of time\n";
        return;
    }
}
bool isInString (const string& first, string& second){
    bool flag = true;
    for(int j = 0,i = 0 ; i < first.size() ; i++){
        if(first[i] == second[j]){
            flag = true;
            j++;
        }
        else flag = false;
    }
    return flag;
}
bool Holiday::validatePhotos(const string& _photo)const{
    string firstToCheck = "jpeg";
    string secondToCheck = "png";
    if (isInString(_photo,firstToCheck) || isInString(_photo,secondToCheck)){
        return true;
    }
    else {
        cerr << "Not valid photo extension!\n";
        return false;
    }
}
string Holiday::getCity() const {
    return city;
}
string Holiday::getComment() const {
    return comment;
}
double Holiday::getRating()const{
    return rating;
}