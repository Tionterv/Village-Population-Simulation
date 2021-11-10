//-----------------------------------------------------------------------------------------------------------------------//
#include "Resource.h"
#include "Village.h"
#include <iostream>
#include <iomanip>
//-----------------------------------------------------------------------------------------------------------------------//

//default constructor
Resource::Resource(){
    food = 100;
    wood = 100;
    gold = 50;
    type = ' ';
    lott_ticket = 1;
};

//setters
void Resource::set_food(int param_food){
    int temp = food;
    if((temp += param_food) > 0){
        food += param_food;
        type = 'f';
        temp = 0;
        display_message(param_food);
    }
        else{
            food = 0;
            type = 'f';
            display_message(param_food);
            std::cout << "Food is completely depleted!" << std::endl << std::endl;
        }
}

void Resource::set_wood(int param_wood){
    int temp = wood;
    if ((temp += param_wood) > 0) {
        wood += param_wood;
        type = 'w';
        temp = 0;
        display_message(param_wood);
    }
        else{
            wood = 0;
            type = 'w';
            display_message(param_wood);
            std::cout << "Wood is completely depleted!" << std::endl << std::endl;
        }
}

void Resource::set_gold(int param_gold){
    int temp = gold;
    if ((temp += param_gold) > 0) {
        gold += param_gold;
        type = 'g';
        temp = 0;
        display_message(param_gold);
    }
    //this else might be unnecessary
    else {
        gold = 0;
        type = 'g';
        display_message(param_gold);
        std::cout << "Gold is completely depleted!" << std::endl << std::endl;
    }
}

void Resource::set_lott_ticket(int param_lott_ticket){
     int temp = lott_ticket;
    if ((temp += param_lott_ticket) > 0) {
        lott_ticket += param_lott_ticket;
        type = 't';
        temp = 0;
        display_message(param_lott_ticket);
    }
    else {
        lott_ticket = 0;
        type = 't';
        display_message(param_lott_ticket);
        std::cout << "You are out of lottery ticket!" << std::endl << std::endl;
    }
}

//-----------------------------------------------------------------------------------------------------------------------//

//getters
int Resource::get_food() const{
    return food;
}

int Resource::get_wood() const{
    return wood;
}


int Resource::get_gold() const{
    return gold;
}

int Resource::get_lott_ticket() const{
    return lott_ticket;
}

//-----------------------------------------------------------------------------------------------------------------------//

//local functions
void Resource::display_stats(){
    //show food, gold, wood
    std::cout << "Food: " <<  get_food() << std::endl;
    std::cout << "Wood: " << get_wood() << std::endl;
    std::cout << "Gold: " <<  get_gold() << std::endl;
    std::cout << "Lottery: " << get_lott_ticket() << std::endl;

}

void Resource::display_message(int holder){

    switch(type){
        case 'f':
            if(holder < 0){
                std::cout << "------------------------------------------------------------------------" << std::endl;
                std::cout << holder << " food was deducted from your inventory" << std::endl;
                std::cout << "------------------------------------------------------------------------" << std::endl << std::endl;
                break;
            }
                else{
                    std::cout << "------------------------------------------------------------------------" << std::endl;
                    std::cout << holder << " food was added to your inventory." << std::endl;
                    std::cout << "------------------------------------------------------------------------" << std::endl << std::endl;
                    break;
                }
        case 'w':
            if(holder < 0){
                std::cout << "------------------------------------------------------------------------" << std::endl;
                std::cout << holder << " wood was deducted from your inventory" << std::endl << std::endl;
                std::cout << "------------------------------------------------------------------------" << std::endl;
                break;
            }
                else{
                    std::cout << "------------------------------------------------------------------------" << std::endl;
                    std::cout << holder << " wood was added to your inventory." << std::endl;
                    std::cout << "------------------------------------------------------------------------" << std::endl << std::endl;
                    break;
                }

        case 'g':
            if(holder < 0){
                std::cout << "------------------------------------------------------------------------" << std::endl;
                std::cout << holder << " gold was deducted from your inventory" << std::endl;
                std::cout << "------------------------------------------------------------------------" << std::endl << std::endl;
                break;
            }
                else{
                    std::cout << "------------------------------------------------------------------------" << std::endl;
                    std::cout << holder << " gold was added to your inventory." << std::endl;
                    std::cout << "------------------------------------------------------------------------" << std::endl << std::endl;
                    break;
                }

        case 't':
            if(holder < 0){
                std::cout << "------------------------------------------------------------------------" << std::endl;
                std::cout << holder << " ticket was deducted from your inventory" << std::endl;
                std::cout << "------------------------------------------------------------------------" << std::endl << std::endl;
                break;
            }
                else{
                    std::cout << "------------------------------------------------------------------------" << std::endl;
                    std::cout << holder << " ticket was added to your inventory." << std::endl;
                    std::cout << "------------------------------------------------------------------------" << std::endl << std::endl;
                    break;
                }
    }
}

//-----------------------------------------------------------------------------------------------------------------------//

//other functions
void Resource::display_shop(){
    std::cout << "Hello, Welcome to the Merchant's Store!" << std::endl;
    std::cout << "1. Food x 10" << '\t\t\t' << "Price: 1 gold"<< std::endl;
    std::cout << "2. Wood x 5" << '\t\t\t' << "Price: 1 gold"<< std::endl;
    std::cout << "3. Lottery Ticket x 1" << '\t\t' << "Price: 30 gold" << std::endl; 
    std::cout << "4. Expand your territory to increase population by 100" << '\t' << "Price: 50 gold & 100 wood" << std::endl;
    std::cout << "5. Exit Store" << std::endl;
}


void Resource::use_ticket(){
    if(lott_ticket == 0){
        std::cout << "You do not have any lottery ticket to scratch! Please purchase a ticket to gamble.";
    }
    else{
    lott_ticket -= 1;
    }

}

