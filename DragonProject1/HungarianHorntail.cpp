// ---------------------------------------------------------------------------
//
// University of Wisconsin-Stout
// Mathematics, Statistics & Computer Science
// CS-244 Data Structures -- Spring 2024
// 
// This software is student work for CSS-244 Data Structures and may not
// be copied except by the original author and instructor.
// Copyright 2024
//
// <HungarianHorntail.cpp>
//
// <This cpp file contains the HungarianHorntail.h method definitions. The purpose of HungarianHorntail.cpp is to give definitions to override the Dragon methods.>
//
// Instructor: Jocelyn Richardt
// Assignment: <OO Design & C++ Review (Dragon Classes)>
// Student: <Adam McGlin>
// Date: <3/18/2024>
//
// ---------------------------------------------------------------------------

// set up
#include "HungarianHorntail.h"

void HungarianHorntail::train() { // defining the overriden train() method

	// increases firePower_ by a different value depending on its current value
	if (firePower_ < 20) { 
		firePower_ += ((rand() % 25) + 15); // the ammount firePower_ is increased by
	}
	if (firePower_ > 20) {
		firePower_ += ((rand() % 15) + 10); // the ammount firePower_ is increased by
	}

	if (firePower_ >= 100) { // Fire Power is limited to 100
		firePower_ = 100;
		cout << "  *Fire Power cannot go any higher*\n";
	}

}

void HungarianHorntail::print() { // prints out the variables in an easy to read way // defining the overriden print() method
	cout << "Hungarian Horntail --Current Fire Power = " << this->firePower_ << "--   --Current Charisma = " << this->charisma_ << "--   --Current Health = " << this->health_ << "-- " << endl;
}


// getters and setters required for the game
int HungarianHorntail::getHealth() {
	return health_;
}

void HungarianHorntail::setHealth(int newHealth) {
	health_ = newHealth;
}

int HungarianHorntail::getCharisma() {
	return charisma_;
}
void HungarianHorntail::setCharisma(int newCharisma) {
	charisma_ = newCharisma;
}
int HungarianHorntail::getFirepower() {
	return firePower_;
}