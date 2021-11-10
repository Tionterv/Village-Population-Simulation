//-----------------------------------------------------------------------------------------------------------------------//
/*
*   Author: Tom Zheng and Kevin Zhang
*   Program: This project is a strategy survival simulation of a civilization that starts from a settlement of a group of people.
*            The objective of the game is to achieve the status of "Country" by expanding your population to greater than 1000.
*            To do this, you must ensure adequate food supplies to feed your people and also bet on your luck to how often you 
*            encounter adverse events, which may decrease your population. All in all, this is a simple, fun, and quick survival 
*            game. Have fun! :)
*
*/

//-----------------------------------------------------------------------------------------------------------------------//

#include <iostream>
#include <cstdlib>
#include "Resource.h"
#include "Village.h"
#include "Time.h"
#include "Event.h"
#include "Player.h"
#include "EventIO.h"

using namespace std;

//-----------------------------------------------------------------------------------------------------------------------//

//constant global vars
const int max_degree = 8;
const int max_num = 4;
const int const_num = 10;
const int reward_g = 30;
const int reward_w = 50;

//-----------------------------------------------------------------------------------------------------------------------//

//random generator *****
int random_generator_main(int const_num){
        int temp;
        srand((unsigned int)time(NULL));
        temp = rand() % const_num + 1; // 1-10
         return temp;
}
//-----------------------------------------------------------------------------------------------------------------------//

// friend function - Time and Event class - verifies if season matches the random generated disaster
void nat_disaster(Time& time, Event& event){
    if (time.season == "Fall" && event.disaster == "Tornado") {
        //modifying data member of Event class
        event.final_disaster = "Due to strong weather conditions, a Tornado formed. "; 
        event.disaster_death = 35;
    }
    else if (time.season == "Spring" && event.disaster == "Flood") {
        event.final_disaster = "Due to a consecutive days of heavy storm, a Flood was created. ";
        event.disaster_death = 45;
    }
    else if (time.season == "Summer" && event.disaster == "Hurricane") {
        event.final_disaster = "Get back to safety! Hurricane is coming! ";
        event.disaster_death = 55;
    }
    else if (time.season == "Winter" && event.disaster == "Blizzard") {
        event.final_disaster = "Brr...the heavy storm and snow formed a merciless Blizzard. ";
        event.disaster_death = 35;
    }
    else{
        cout << endl;
        event.final_disaster = "Weather forcast: No predicted disaster coming. ";
        event.disaster_death = 0;
    }
}

void what() {
    cout << "Invalid input!" << endl;
}


//-----------------------------------------------------------------------------------------------------------------------//

//MAIN
int main(){
    //-----------------------------------------------------------------------------------------------------------------------//
    //this section will hold all the variable and objects created and manipulated throughout the program.
    //objects
    Village new_start;
    Time new_time;
    Player new_player;
    Event new_event;
    EventIO new_eventio;
    Event* eventptr; //declaring a pointer of Event object
    //Resource new_res;

    //variables
    int counter = 0;
    int action_choice = 0; //user input of action command in int values
    int command = 0; //user input of command in int values
    char input = ' '; //user input of 'y' or 'n'
    int purchase_choice = 0; //try figure out a way to reuse the variables rather than making too many
    int temp_death = 0; //to be use in skip_natural for holding natural disaster death
    int temp_sdeath = 0; //temporary var that holds death caused by special event
    int event_selector; // used in skip_wake for holding random val of selecting which events to occur after wake
    int temper = 0; //var holder that holds values to decide if a special event should occur 3=ticketevent, 0=specialevent, 1=normalevent

    //-----------------------------------------------------------------------------------------------------------------------//

    //color settings
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char blue_l[] = { 0x1b, '[', '4', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };

    
    //INTRODUCTION - WELCOME MESSAGE
    std::cout << blue_l <<"Welcome to the World of Survival! " << normal << endl << endl << endl;

    //script1
    std::cout << blue << "You are the leader of a newly created settlement, your objective is to expand the population." << endl
        << "You are also responsible for keeping them happy and safe by securing adequate resources and" << endl
        << "avoiding excessive deaths." << normal << endl << endl;

    std::system("pause");
 
    //script2
    std::cout << endl << "Your new settlement will begin with" << green << " 100 people, 200 food, 100 wood, and 20 gold." << normal << endl
        << "As your population increases, your settlement will upgrade into different class divisions. " << endl
        << "To keep your community healthy and happy, ensure there is always an adequate amount of food for the population." << endl
        << "You can also use your gold and wood to trade for more food and increase the population." << endl << endl;

    std::system("pause");
    std::system("cls");
    std::cout << endl <<"Loading Game..." << endl;
    new_player.separator();
    std::cout << endl << blue << "A new settlement was created. " << normal << endl << endl;
    new_start.display_stats();
    new_time.display_date();

    std::system("pause");
    std::cout << endl;

    //-----------------------------------------------------------------------------------------------------------------------//
    //this is the action menu for the user
skip_action:

    while(new_player.get_counter() != 4){
        new_player.interactive_msg();
        std::cin >> action_choice;
        
        try {
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Your input was an alphabet, please input an integer value! " << std::endl;
            }
            else if (action_choice <= 6 && action_choice >= 1) 
            {
                switch (action_choice) {
                    case 1: //search for food = +20
                        std::cout << endl << "Searching for food..." << endl;
                        std::cout << endl;
                        new_start.update_food(20);
                        new_player.set_counter(1);
                        new_player.interactive_counter();
                        break;

                    case 2: //gather for wood = +15
                        std::cout << endl << "Gathering wood..." << endl;
                        std::cout << endl;
                        new_start.update_wood(15);
                        new_player.set_counter(1);
                        new_player.interactive_counter();
                        break;

                    case 3: //mines for gold = +2
                        std::cout << endl << "Mining for gold..." << endl;
                        std::cout << endl;
                        new_start.update_gold(2);
                        new_player.set_counter(1);
                        new_player.interactive_counter();
                        break;

                    case 4: //visits the merchant's store
                        system("cls");
                        std::cout << endl << "Visiting the Merchant's Store..." << endl;
                        std::cout << endl;
                        do{
                            new_start.display_stats();
                            new_start.show_shop();
                            std::cin >> purchase_choice;
                            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            if (purchase_choice == 4) {
                                if (new_start.get_gold() >= 50 && new_start.get_vwood() >= 100) {
                                    std::cout << std::endl << "You purchased more land to expand your territory..." << std::endl;
                                    new_start.update_gold(-50);
                                    new_start.update_wood(-100);
                                    new_start++;
                                    break;
                                }
                                else {
                                    std::cout << "You do not have sufficient gold or wood to purchase this item!" << std::endl;
                                    break;
                                }
                            }
                            else if (purchase_choice == 3) {
                                if (new_start.get_gold() >= 30) {
                                    std::cout << std::endl << "You purchased a lottery ticket. Good Luck!" << std::endl;
                                    new_start.update_gold(-30);
                                    new_start.update_ticket(1);
                                    break;
                                }
                                else {
                                    std::cout << "You do not have sufficient gold to purchase this item!" << std::endl;
                                    break;
                                }
                            }
                            else if (purchase_choice == 2){
                                if (new_start.get_gold() >= 1) {
                                    std::cout << std::endl << "You purchased 5 wood. Thank you!" << std::endl;
                                    new_start.update_gold(-1);
                                    new_start.update_wood(5);
                                    break;
                                }
                                else {
                                    std::cout << "You do not have sufficient gold to purchase this item!" << std::endl;
                                    break;
                                }
                            }
                            else if (purchase_choice == 1) {
                                if (new_start.get_gold() >= 1) {
                                    std::cout << std::endl << "You purchased 10 food. Thank you!" << std::endl;
                                    new_start.update_gold(-1);
                                    new_start.update_food(10);
                                    break;
                                }
                                else {
                                    std::cout << "You do not have sufficient gold to purchase this item!" << std::endl;
                                    break;
                                }
                            }
                            else if (purchase_choice == 5) {
                                break;
                            }
                        } while (purchase_choice != 5);
                        break;

                    case 5:
                        if (new_start.get_lott() >> 0) {
                            std::cout << endl << "Retrieving your ticket... Good Luck!" << endl;
                            new_player.separator();
                            new_start.use_lott();
                            std::cout << endl;
                            temper = 3;
                            goto skip_eventio;
                        }
                        else {
                            std::cout << "You do not have sufficient tickets. Please visit the merchant's store to purchase. " << endl;
                            break;
                        }

                    case 6:
                        std::cout << endl;
                        goto skip_menu;

                }//end switch
                
            }
            else {
                //switch for interactive object. Please make a function for this due to repetiveness *************
                throw invalid_argument("Invalid input. Please input value between 1 and 6.");
            }//end else
        }//end try

        catch (const invalid_argument& e) {
            std::cout << e.what() << endl;
        }
    }//end while
    
//end skip_action


//-----------------------------------------------------------------------------------------------------------------------//
    //this section is for if the actions for the day are exhausted. 
    //It will ask the player to sleep to replenish the actions or go to the default menu. 

    if(new_player.get_counter() == 4){
        std::cout << "You have exhausted all of your remaining actions for the day. Please wait for the next day to continue." << endl << endl;
        std::cout << "Would you like to end the day? (y/n) : " ;
        std::cin >> input;
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(tolower(input) == 'y'){
                new_time.set_day();
                new_player.reset_counter();
                goto skip_wake; //find a new beginning for every new day that occurred. create function that displays a message template for every new day occurred. 
            }
            else{
            goto skip_menu; //maybe there are other loops to skip to rather than the commmand menu. revise this
            }
    }

//-----------------------------------------------------------------------------------------------------------------------//
//screen for menu of commands
skip_menu:
    command = 0;
    do{
        new_player.display_msg();
        std::cin >> command;
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        try {
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Your input was an alphabet, please input an integer value! " << std::endl;
            }
            else if (command <= 5 && command >= 1) {
                switch (command) {
                case 1: //this will display population information and current resource inventory
                    std::cout << endl << "General Statistics: " << endl;
                    std::cout << endl;
                    new_start.display_stats();
                    break;

                case 2: //this will display the current time and season
                    std::cout << endl << "Current Time: " << endl;
                    std::cout << endl;
                    new_time.display_date();
                    break;

                case 3: //this will end the day and reset the counter for "skip_action", replenishing players with 3 more actions
                    std::cout << endl << "Ending the day..." << endl;
                    std::cout << endl;
                    new_time.set_day();
                    new_player.reset_counter();
                    goto skip_wake;
                    //find a way to move the control of this loop back to the previous loop. Call to simplified loop above. 
                    break;

                case 4: //this will exit out of the command menu and goto a default menu [not created yet]
                    std::cout << endl << "Exiting Menu Options..." << endl;
                    std::cout << endl;
                    goto skip_action; //make another skip for this instead of wake here. becaues you dont wake after exiting the command menu
                    break;

                case 5:
                    std::system("cls");
                    std::cout << "Please confirm that you would like to exit the game. (y/n): ";
                    std::cin >> input;
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (!std::cin) {
                        std::cin.clear();
                        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else if (tolower(input == 'y')) {
                        std::cout << std::endl << "Thank you so much for playing the game! Goodbye!" << endl;
                        exit(0);
                    }
                    else {
                        std::cout << std::endl << "I know you won't quit so easily!" << std::endl << std::endl;
                        continue;
                    }
                }
            }
            else {
                throw invalid_argument("Invalid Input. Please enter a value between 1-5!");
            }
        }
        catch (const invalid_argument& e) {
           std::cout << e.what() << std::endl;
        }
    } while (command != 5);//end while
//end skip_menu


//-----------------------------------------------------------------------------------------------------------------------//
//screen for player wake

skip_wake:
    std::system("cls");
    std::cout << endl <<  "You woke up to a new day..." << endl << endl;
    new_start--;
    std::cout << endl;

    std::system("pause");

    event_selector = random_generator_main(const_num);
    switch (event_selector){
       
        case 1: 
            goto skip_event;
            break;

        case 2:
            goto skip_birth;
            break;

        case 3:
            goto skip_birth;
            break;   

        case 4:
            goto skip_birth;
            break;    

        case 5:
            std::cout << std::endl << "Good luck, an event is occuring!" << endl;
            temper = 0;
            goto skip_eventio;
            break;  

        case 6:
            goto skip_event;
            break;

        case 7:
            goto skip_natural;
            break;  

        case 9:
            goto skip_natural;
            break;  

        case 10: 
            goto skip_natural;
            break;

    }
//end skip_wake


//-----------------------------------------------------------------------------------------------------------------------//
//this is the main area where events occurs. Control of the program will redirect to here at intervals of new days
skip_event:

    if(new_start.trigger_event() == true){
        new_start.display_stats();
        goto skip_action;
    }
        else{
        goto skip_action;
        }

//after event, goto skip_action


//-----------------------------------------------------------------------------------------------------------------------//
skip_birth:

    if(new_start.trigger_birth() == true){
            new_start++;
            new_start.display_stats();
            goto skip_action;
        }
            else{
                goto skip_action;
            }


    //-----------------------------------------------------------------------------------------------------------------------//

skip_natural:

    new_event.set_random_num(max_num); //activates generator for natural disaster

    nat_disaster(new_time, new_event); //triggers friend function to test if the season and disaster matched together
    cout << new_event.get_final_disaster(); // retrieves the final disaster if there is a disaster matched with the season
    
    //this will take event death caused by natural disaster and subtract the population
    temp_death = new_event.get_disaster_death();
    if(temp_death > 0)
    {
        new_start.set_death(temp_death);
        temp_death = 0;
        goto skip_action;
    }
        else
        {
             goto skip_action;
        }

    //need something interactive. a menu of actions by player
    //
    
    // Test out if changing food, gold and wood on resource class will affect the instances on Village class.
    // setfood, setgold, set wood...



//-----------------------------------------------------------------------------------------------------------------------//
//special event here
skip_eventio:

    //make function that uses modulus to calculate certain intervals of days. to switch between a sunny day desc and a rainy desc
    cout << endl << "The sky coated in darkness as an unpredictable event may be approaching" << endl << endl;
    cout << endl;

    system("pause");
  
    //assigning eventio object to object eventptr
    eventptr = &new_eventio;
    
    //if statement will execute if player decides to use a ticket to trigger special event
    if (temper == 3) {
        eventptr->special_event(); //trigger derived function
            temp_sdeath = new_eventio.get_special_deaths(); //store deaths by derived function's event
            if (temp_sdeath == 0) {
                new_start.update_gold(reward_g);
            }
            else if (temp_sdeath == -1) {
                new_start.update_wood(reward_w);
            }       
            else {
                new_start.set_death(temp_sdeath);
            }
    }     
    //this is for when the probability triggers either the base function or derived function of the virtual function
    else {
        temper = rand() % 2; // 0-1
            if (temper == 0) {

                eventptr->special_event(); //trigger derived function
                temp_sdeath = new_eventio.get_special_deaths(); //store deaths by derived function's event
                if (temp_sdeath == 0) {
                    new_start.update_gold(reward_g);
                }
                else if (temp_sdeath == -1) {
                    new_start.update_wood(reward_w);
                }
                else {
                    new_start.set_death(temp_sdeath);
                }

            }
            else if (temper == 1) {
                //base/parent virtual 
                new_event.special_event();
            }
    }  
    goto skip_action;

    return 0;
}//end main

//-----------------------------------------------------------------------------------------------------------------------//
