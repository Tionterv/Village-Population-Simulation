#ifndef RESOURCE_h
#define RESOURCE_h
#include <iostream>

class Resource{
 
private:
    int food;
    int wood;
    int gold;
    char type;
    int lott_ticket;

public:
    //constructor
    Resource();
    
    // Setter functions
    void set_food(int param_food);
    void set_wood(int param_wood);
    void set_gold(int param_gold);
    void set_lott_ticket(int param_lott_ticket);
    
    // Getter functions
    int get_food() const;
    int get_wood() const;
    int get_gold() const;
    int get_lott_ticket() const;

    //functions
    void display_stats();
    void display_message(int holder);
    void display_shop();
    void use_ticket();
};
#endif /* RESOURCE_h */
