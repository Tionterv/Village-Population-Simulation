#ifndef VILLAGE_H
#define VILLAGE_H
#include <iostream>
#include "Resource.h"
#include "Event.h"

class Village {

private:
    static int population;
    int death;
    int birth;
    int random_birth = 0;
    std::string well_being;
    std::string class_division;
    Resource Inventory;
    Event Encounter;

public:
    //constructor
    Village();

    //setters
    void set_birth(int param_birth);
    void set_death(int param_death);
    void set_well_being(std::string param_well_being);
    void set_class_division(int population);
    void set_random_birth(int birth_num);

    //-----------------------------------------------------------------------------------------------------------------------//

    //getters
	int get_birth() const;
	int get_death() const;
    int get_random_birth();
    int get_lott();
    int get_gold();
    int get_vwood();
    std::string get_class_division() const;
    std::string get_well_being() const;
    
    //-----------------------------------------------------------------------------------------------------------------------//
    
    //operator functions
    Village operator++ (int unused_param);
    Village operator-- (int temp_param);

    //-----------------------------------------------------------------------------------------------------------------------//

    //function
    void display_stats();

    //-----------------------------------------------------------------------------------------------------------------------//

    //update functions relating to resources
    void update_food(int param_food);
    void update_wood(int param_wood);
    void update_gold(int param_gold);
    void update_ticket(int param_lott_ticket);

    //-----------------------------------------------------------------------------------------------------------------------//

    //functions relating to event
    bool trigger_event();
    bool trigger_birth();
    void win_game();
    //-----------------------------------------------------------------------------------------------------------------------//

    //functions relating to merchant's store
    void show_shop();
    void use_lott();
  
    //-----------------------------------------------------------------------------------------------------------------------//

    //calling to friend function
    std::string get_event_nat_disaster();
};

#endif
