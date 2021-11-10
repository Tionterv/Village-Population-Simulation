//-----------------------------------------------------------------------------------------------------------------------//
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "EventIO.h"
//-----------------------------------------------------------------------------------------------------------------------//

//initalized vars
Event list;
int value = 0;
int reward_value = 0;
std::string reward_type;

//-----------------------------------------------------------------------------------------------------------------------//
//fstream
Event EventIO::readfile() {
  
    //initializing buffers
    std::string buffer_death = "";
    std::string buffer_reward = "";
    std::string buffer_type = "";
    std::string buffer_event = "";

    //open file
    std::string filename = "Special_Events.txt";
    std::ifstream input_file;
    input_file.open(filename);

    //calls random generator to pick ONE line from textfile
    set_random_gen(max_gen);
    int random_value = get_random_gen();

        //output specified line from textfile using line count
        int line_no = 0;
        while(line_no != random_value  && std::getline(input_file, buffer_death, '\t')) // replace value 2 with a random generator
        {
            //convert string to int, assign to value
            value = std::stoi(buffer_death);
            //Object list of Class calls to Event member function to set special deaths.
            list.set_special_event_deaths(value);  
            
            //store the remaining event description
            getline(input_file, buffer_event);
            //counter
            ++line_no;
        }   

            //if line counter matches the random_value, it will output the line from textfile.
            if(line_no == random_value){
                std::cout << std::endl << buffer_event << std::endl;
            }
                else{
                    std::cout << "Event does not exist.";
                }   
    input_file.close();
    return list;
}

//-----------------------------------------------------------------------------------------------------------------------//

//setters
void EventIO::set_random_gen(int max_gen){
    srand(time(NULL));
    random_gen = rand() % max_gen; // 0-11number

}

//-----------------------------------------------------------------------------------------------------------------------//

//getters
int EventIO::get_random_gen(){
return random_gen;    
}

int EventIO::get_special_deaths() {
    return list.get_event_deaths();
}


//-----------------------------------------------------------------------------------------------------------------------//

//virtual
    void EventIO::special_event(){
        //this should take a param and do readfile
        //this will call to readfile then output the textf
        readfile();
    }



   