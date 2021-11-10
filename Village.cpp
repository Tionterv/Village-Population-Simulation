//-----------------------------------------------------------------------------------------------------------------------//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Village.h"
//-----------------------------------------------------------------------------------------------------------------------//

    // static data declaration and const vars
    const int birth_num = 11;
    const int disaster_num = 4;
    int Village::population = 200;

    //-----------------------------------------------------------------------------------------------------------------------//

    //default constructor
    Village::Village(){
        death = 0;
        birth = 0;
        std::string well_being = "Happy";
        std::string class_division = "Settlement"; 
        Resource Inventory;
        Event Encounter;
    };

    //-----------------------------------------------------------------------------------------------------------------------//

    //setters
    void Village::set_birth(int param_birth){
        birth = param_birth;
        population += birth;
        set_class_division(population);
    }

    void Village::set_death(int param_death){
        death = param_death;
        // we reduce the population and use if-statements to make sure it doesn't go below 0
        // Lose game when population is 0
        int temp = population;
        if ((temp -= death) < 0){
            std::cout << death << " people died. " << std::endl << std::endl;
            population = 0;
            //create a class that deals with ascii design and make an outro. show player statistics and achievements before ending
            std::cout << "THE GAME HAS ENDED, YOU FAILED TO KEEP YOUR PEOPLE ALIVE!" << std::endl;
        }
        else{
            std::cout << death << " people died. "<< std::endl;
            population -= death;
            // Functions that updates the population
            set_class_division(population);
        }
    }

    void Village::set_well_being(std::string class_division) {
        int food_temp = Inventory.get_food();
        //for Happy State
        if ((class_division == "Settlement") && food_temp >= 200) {
            well_being = "Happy";
        }
        else if ((class_division == "Village") && food_temp >= 400) {
            well_being = "Happy";
        }
        else if ((class_division == "Town") && food_temp >= 600) {
            well_being = "Happy";
        }
        else if ((class_division == "City") && food_temp >= 800) {
            well_being = "Happy";
        }
        else if ((class_division == "Country") && food_temp >= 1000) {
            well_being = "Happy";
        }

        // for Neutral State
        else if ((class_division == "Settlement") && food_temp >= 100 && food_temp < 200) {
            well_being = "Neutral";
        }
        else if ((class_division == "Village") && food_temp >= 300 && food_temp < 400) {
            well_being = "Neutral";
        }
        else if ((class_division == "Town") && food_temp >= 500 && food_temp < 600) {
            well_being = "Neutral";
        }
        else if ((class_division == "City") && food_temp >= 700 && food_temp < 1000) {
            well_being = "Neutral";
        }
        else if ((class_division == "Country") && food_temp >= 900 && food_temp < 1000) {
            well_being = "Neutral";
        }

        ///for Angry State
        else if ((class_division == "Settlement") && food_temp < 100 && food_temp >= 0) {
            well_being = "Angry";
        }
        else if ((class_division == "Village") && food_temp < 300 && food_temp >= 0) {
            well_being = "Angry";
        }
        else if ((class_division == "Town") && food_temp < 500 && food_temp >= 0) {
            well_being = "Angry";
        }
        else if ((class_division == "City") && food_temp < 800 && food_temp >= 0) {
            well_being = "Angry";
        }
        else if ((class_division == "Country") && food_temp < 900 && food_temp >= 0) {
            well_being = "Angry";
        }
    }

    void Village::set_class_division(int population){
        if (population >= 0 && population <= 200) {
            class_division = "Settlement";
        }
        else if (population > 200 && population <= 400) {
            class_division = "Village";
        }
        else if (population > 400 && population <= 600) {
            class_division = "Town";
        }
        else if (population > 600 && population <= 1000) {
            class_division = "City";
        }
        else if (population > 1000) {
            class_division = "Country";
        }
        set_well_being(class_division);
    }

    void Village::set_random_birth(int birth_num) {
        srand((unsigned int)time(NULL));
        random_birth = rand() % birth_num + 1;
    }
    int Village::get_random_birth() {

        return random_birth;
    }

    //-----------------------------------------------------------------------------------------------------------------------//

    //getters
	int Village::get_birth() const{
        return birth;
    }

	int Village::get_death() const{
        return death;
    }

	std::string Village::get_class_division() const{
        return class_division;
    }

    std::string Village::get_well_being() const{
        return well_being;
    }

    int Village::get_lott() {
        return Inventory.get_lott_ticket();
    }

    int Village::get_gold() {
        return Inventory.get_gold();
    }

    int Village::get_vwood() {
        return Inventory.get_wood();
    }

    //-----------------------------------------------------------------------------------------------------------------------//

    //operator functions 
    Village Village::operator++ (int unused_param) {
        Village temp = *this;
        population = population + 80;
        return temp;
    }

    Village Village::operator --(int temp_param) {
        Village temp = *this;
        update_food(-10);
        return temp;
    }

    //-----------------------------------------------------------------------------------------------------------------------//

    //function
    void Village::display_stats(){
        // Functions that updates the population and class division
        set_class_division(population);
        win_game();
        set_well_being(class_division);
        std::cout << "|CURRENT STATISTICS| " << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Population: " << population << std::endl;
        std::cout << "Class division: " << get_class_division() << std::endl;
        std::cout << "Well being: " << get_well_being() << std::endl << std::endl;

        std::cout << "|RESOURCE| " <<std::endl;
        std::cout << "------------------------------------" << std::endl;
        Inventory.display_stats();
        std::cout << std::endl;
    }

    //-----------------------------------------------------------------------------------------------------------------------//

    //update function
    void Village::update_food(int param_food){
        Inventory.set_food(param_food);
        int temp_food = Inventory.get_food();
        if(temp_food <= 0){
            set_death(5);
            std::cout << "People are starving to death!" << std::endl;
        }
    }
  
    void Village::update_wood(int param_wood){
        Inventory.set_wood(param_wood);
    }
    void Village::update_gold(int param_gold){
        Inventory.set_gold(param_gold);

    }
    void Village::update_ticket(int param_ticket){
        Inventory.set_lott_ticket(param_ticket);

    }

    //-----------------------------------------------------------------------------------------------------------------------//

    //functions relating to event

    bool Village::trigger_event() {
        bool temp = Encounter.pick_day();
        if (temp == true) {
            int param_death = Encounter.get_event_deaths();
            set_death(param_death);
            return temp;
        }
        else {
            return temp;
        }
    }

    bool Village::trigger_birth() {
        set_random_birth(birth_num);
        int temp = get_random_birth();
        if (temp == 1 || temp == 2 || temp == 4 || temp == 6 || temp == 8 || temp == 10 || temp == 7) {
            std::cout << std::endl << "Newborns are coming, your population will increase!" << std::endl << std::endl;
            return true;
        }
        else {
            return false;
        }
    }

    void Village::win_game() {
        if (class_division == "Country") {
            std::cout << "CONGRATULATION! YOU HAVE ACHIEVED \"COUNTRY\" STATUS." << std::endl << std::endl;
            std::cout << "You may continue to enjoy the game or exit the game. :)" << std::endl << std::endl;
            system("pause");
        }
    }

    //-----------------------------------------------------------------------------------------------------------------------//

    //functions relating to merchant's store

    void Village::show_shop(){
        Inventory.display_shop();
        std::cout << std::endl << "What would you like to purchase? : ";
    }

    void Village::use_lott(){
        Inventory.use_ticket();
    }


    //-----------------------------------------------------------------------------------------------------------------------//

    //Calling function
    std::string Village::get_event_nat_disaster(){
        Encounter.set_random_num(disaster_num);
        return Encounter.get_disaster();
    }