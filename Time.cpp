//-----------------------------------------------------------------------------------------------------------------------//
#include <iostream>
#include <string>
#include "Time.h"
#include "Event.h"
//-----------------------------------------------------------------------------------------------------------------------//

int Time::day = 1;


//default constructor
Time::Time(){
    std::string season = "Fall";
};

//-----------------------------------------------------------------------------------------------------------------------//

//setters
void Time::set_day()
{
	day += 1; //infinite - throw exception if past the int limit 32k
    system("cls");
    std::cout << "The darkness of night cloaked the entirety of your community. As you close your eyes, you wander off into a dreamy dimension, hoping life would be better the next." << std::endl << std::endl; 
}

void Time::set_season()
{  
    int temp_day = day;

    if(day > 80){
        temp_day %= 80;
    }

    if (temp_day >= 0 && temp_day < 20) {
        season = "Fall";
    }
    else if (temp_day >= 20 && temp_day < 40) {
        season = "Spring";
    }
    else if (temp_day >= 40 && temp_day < 60) {
        season = "Summer";
    }
    else if (temp_day >= 60 && temp_day < 80) {
        season = "Winter";
    }
}

//-----------------------------------------------------------------------------------------------------------------------//

//getters
int Time::get_day()
{
	return day;
}

std::string Time::get_season()
{
    return season;
}

//-----------------------------------------------------------------------------------------------------------------------//

//functions
void Time::display_date()
{
    set_season();
    std::cout << "|CALENDAR| " << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Day: " << get_day() << std::endl;
    std::cout << "Season: " << get_season() << std::endl;
    std::cout << "------------------------------------" << std::endl << std::endl;
}