#ifndef EVENTIO_h
#define EVENTIO_h
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Event.h" 

class EventIO: public Event
{
private:
    int random_gen = 0;
    const int max_gen = 12;

public:
    //fstream
    Event readfile();

    //setters
    void set_random_gen(int max_gen);

    //getters
    int get_random_gen();
    int get_special_deaths();

    //virtual
    void special_event();
};

#endif 




