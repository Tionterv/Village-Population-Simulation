#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player
{
    private:
        int choice = 0;
        int counter = 0; 
   
    public:
        //setters
        void set_choice(int param_choice);
        void set_counter(int param_counter);
        
        //getters
        int get_choice() const;
        int get_counter() const;

        //functions
        void display_msg();
        void interactive_msg();
        void interactive_counter();
        void reset_counter();
        
        //formatter
        void separator();
};
#endif
