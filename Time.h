#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>

//forward declaration
class Event;

class Time
{
private:
    static int day;
    std::string season;

public:
    //constructor
    Time();

    //setters
    static void set_day();
    void set_season();

    //getters
    static int get_day();
    std::string get_season();

    //functions
    void display_date();

    //friend function
    friend void nat_disaster(Time& time, Event& event);
};
#endif

