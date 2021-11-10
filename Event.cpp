//-----------------------------------------------------------------------------------------------------------------------//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Time.h"
#include "Event.h"
#include "EventIO.h"
//-----------------------------------------------------------------------------------------------------------------------//

//const vars
const int max_degree = 8;
const int max_num = 4;
const int number = 11;

//-----------------------------------------------------------------------------------------------------------------------//
//default constructor
Event::Event(){
    random_degree = 0; 
    event_death = 0;
    special_death = 0;
    disaster_death = 0;
    reward = 0;
    disaster = " ";
};

    //-----------------------------------------------------------------------------------------------------------------------//

    //setters 
    void Event::set_disaster(int random_num){
        switch(random_num){
            case 0: 
                disaster = "Tornado";
                break;

            case 1: // flooding 
                disaster = "Flood";
                break;
                
            case 2: // hurricanes
                disaster = "Hurricane";
                break;

            case 3: 
                disaster = "Blizzard";
                break;
        }
    }

    //default in_game events //textfile will provide an external, randomly selected event to overwrite this, based on key triggers.
    void Event::set_event_deaths(int random_degree) {
        switch (random_degree) { 

            case 0:
                event_death = 0; //no event, no death 
                //display_event(event_death);
                std::cout << "Nothing interesting happened today." << std::endl << std::endl;
                break;
            case 1:
                event_death = 10; // animal attack, monster attack
                //display_event(event_death);
                std::cout << "Today we were attacked by animals." << std::endl << std::endl;
                break;
            case 2:
                event_death = 15; //external group attack, eg. bandits
                //display_event(event_death);
                std::cout << "We were raided by a group of ruthless bandits." << std::endl << std::endl;
                break;

            case 3:
                event_death = 25; // fire
                //display_event(event_death);
                std::cout << "A fire broke out in a nearby restaurant." << std::endl << std::endl;
                break;

            case 4:
                event_death = 35; //
                //display_event(event_death);
                std::cout << "An immense wind blew deathly debris onto us." << std::endl << std::endl;
                break;

            case 5:
                event_death = 55; // earthquake
                //display_event(event_death);
                std::cout << "An earthquake of magnitude 6.8 hit us." << std::endl << std::endl;
                break;

            case 6:
                event_death = 70; // plague
                //display_event(event_death);
                std::cout << "We suffered from an unknown plague." << std::endl << std::endl;
                break;

            case 7:
                event_death = 45; // A riot broke out
                //display_event(event_death);
                std::cout << "A riot broke out!" << std::endl << std::endl;
                break;
        }
    }

    //this ran generator is for default disasters within the game
    void Event::set_random_degree(int max_degree) {
        srand(time(NULL));
        random_degree = rand() % max_degree; // 0-7 number
        set_event_deaths(random_degree);
    }

    //this generator is for default seasonal disaster
    void Event::set_random_num(int max_num) {
        srand(time(NULL));
        random_num = rand() % max_num; // 0-3number
        set_disaster(random_num);
        /// use this part soon /// set_event_deaths(random_degree);
    }

    void Event::set_trigger_num(int number) {
        srand(time(NULL));
        trigger_num = rand() % number + 1;
    }

    //-----------------------------------------------------------------------------------------------------------------------//
    //getters
    std::string Event::get_disaster(){
        return disaster;
    }

    std::string Event::get_final_disaster(){
        return final_disaster;
    }

    void Event::set_special_event_deaths(int param_special_death){
        event_death = param_special_death;
    }

    int Event::get_random_degree(){
        return random_degree;
    }

    int Event::get_random_num(){
        return random_num;
    }

    int Event::get_trigger_num(){
        return trigger_num;
    }

    int Event::get_disaster_death(){
        return disaster_death;
    }

    int Event::get_event_deaths(){
       return event_death;
    }

    //-----------------------------------------------------------------------------------------------------------------------//
    //display function
    void Event::display_event(int param_event_death){
        std::cout << param_event_death << " people died. ";

    }

    bool Event::pick_day() {
        set_trigger_num(number);
        int temp = get_trigger_num();
        if (temp == 1 || temp == 4 || temp == 6 || temp == 10) {
            std::cout << std::endl << "Event occurring" << std::endl;
            set_random_degree(max_degree);
            return true;
        }
        else {
            return false;
        }
    }

    //-----------------------------------------------------------------------------------------------------------------------//
    //virtual
    void Event::special_event(){
        std::cout << "Not sure if it is a good thing, but seems it like there will be no SPECIAL event..." << std::endl << std::endl;
        set_random_degree(max_num);
    }
