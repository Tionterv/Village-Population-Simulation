//-----------------------------------------------------------------------------------------------------------------------//
#include <iostream>
#include "Player.h"
//-----------------------------------------------------------------------------------------------------------------------//

//setters
void Player::set_choice(int param_choice){
	choice = param_choice;
}

void Player::set_counter(int param_counter){
	counter = counter + param_counter;
}

//-----------------------------------------------------------------------------------------------------------------------//

//getters
int Player::get_choice() const
{
	return choice;
}

int Player::get_counter() const{
	return counter;
}

//-----------------------------------------------------------------------------------------------------------------------//

//functions
void Player::display_msg(){
	std::cout << "------------------------------------" << std::endl;
	std::cout << "COMMAND MENU " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "1. Show General Statstics" << std::endl;
	std::cout << "2. Show Time" << std::endl;
	std::cout << "3. End Day." << std::endl;
	std::cout << "4. Exit the command menu " << std::endl;
	std::cout << "5. Exit Game" << std::endl << std::endl; //CREATE A FUNCTION RECONFIRMING IF PLAYER WANTS TO EXIT GAME?
	std::cout << "Please enter your command: ";
}

void Player::interactive_msg(){
	std::cout << std::endl << "------------------------------------" << std::endl;
	std::cout << "What would you like to do? " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "1. Scavenge for food" << std::endl;
	std::cout << "2. Gather wood in the forest" << std::endl;
	std::cout << "3. Mine for gold" << std::endl;
	std::cout << "4. Visit the Merchant's shop" << std::endl;
	std::cout << "5. Scratch your lottery ticket" << std::endl;
	std::cout << "6. Show menu options" << std::endl << std::endl;
	std::cout << "Please enter your choice: "; 
}

void Player::interactive_counter() {
	std::cout << "You have " << 4 - counter << " remaining actions for the day!" << std::endl << std::endl;
}

void Player::reset_counter() {
	counter = 0;
}

//-----------------------------------------------------------------------------------------------------------------------//

//formatting function for organization
void Player::separator() {
	std::cout << std::endl << "------------------------------------------------------------------------" << std::endl << std::endl;
	system("pause");
}