#include "HEADERS/Timestamp.h"
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

void Timestamp::init(struct tm *tm_time) {
   secs = (unsigned int) tm_time->tm_sec;
   mins = (unsigned int) tm_time->tm_min;
   hours = (unsigned int) tm_time->tm_hour;
   month = (unsigned int) tm_time->tm_mon + 1;
   day = (unsigned int) tm_time->tm_mday;
   year = (unsigned int) tm_time->tm_year + 1900;
}

Timestamp::Timestamp(const Timestamp& other){
    secs = other.secs;
    mins = other.mins;
    hours = other.hours;
    month = other.month;
    day = other.day;
    year = other.year;
}

Timestamp& Timestamp::operator=(const Timestamp& other){
    secs = other.secs;
    mins = other.mins;
    hours = other.hours;
    month = other.month;
    day = other.day;
    year = other.year;
    return *this;
}

Timestamp::Timestamp() {
   now();
}

void Timestamp::now() {
   time_t rightnow = time(0);
   struct tm *tm_time = localtime(&rightnow);
   init(tm_time);
}

string Timestamp::toString(){
    stringstream ss("");
    ss << setw(4) << setfill('0') << year;
    ss << '/';
    ss << setw(2) << setfill('0') << month;
    ss << '/';
    ss << setw(2) << setfill('0') << day << ' ';
    ss << setw(2) << setfill('0') << hours;
    ss << ':';
    ss << setw(2) << setfill('0') << mins;
    ss << ':';
    ss << setw(2) << setfill('0') << secs;
    return ss.str();
}