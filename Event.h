#ifndef EVENT_H
#define EVENT_H
#include <iostream>


//forward declaration
class Time;

class Event
{
private:
    int random_degree; //rating from 1-10 of the adverse event effect  //star
    int random_num = 0; 
    int trigger_num = 0;
    int event_death; // how many deaths were caused by an event 
    int special_death;
    int disaster_death;
    int reward; 
    std::string disaster; 
    std::string final_disaster = " "; // if 1 = allows function set_disaster to continue, if not, ntn happens. 

public: 
    //constructor
    Event();

    //setters
    void set_random_degree(int max_degree);
    void set_random_num(int max_num);
    void set_trigger_num(int number);
    void set_event_deaths(int death_param);
    void set_disaster(int random_num);
    void set_special_event_deaths(int param_special_death);
 

    //getters
    int get_random_degree();
    int get_random_num();
    int get_trigger_num();
    int get_event_deaths();
    int get_disaster_death();
    std::string get_disaster();
    std::string get_final_disaster();
  

    //function
    void display_event(int param_event_death);
    bool pick_day();

    //friend function
    friend void nat_disaster(Time& time, Event& event);

    //virtual function
    virtual void special_event();
};
#endif

