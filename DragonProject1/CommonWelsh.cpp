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
// <CommonWelsh.cpp>
//
// <This cpp file contains the CommonWelsh.h method definitions. The purpose of CommonWelsh.cpp is to give definitions to override the Dragon methods.>
//
// Instructor: Jocelyn Richardt
// Assignment: <OO Design & C++ Review (Dragon Classes)>
// Student: <Adam McGlin>
// Date: <3/18/2024>
//
// ---------------------------------------------------------------------------

// set up
#include "CommonWelsh.h"

CommonWelsh::CommonWelsh() : Dragon("Green", "Wales", (rand() % 50) + 10, (rand() % 5) + 95, (rand() % 10) + 45) {} // declaration of constructor (was trying a new way to do this)

void CommonWelsh::train() { // defining the overriden train() method

	firePower_ += trustFactor_; // the ammount firePower_ is increased by
	trustFactor_ += 5; // increases by 5 everytime the CommonWelsh train() is called

	if (firePower_ >= 100) { // Fire Power is limited to 100
		firePower_ = 100;
		cout << "  *Fire Power cannot go any higher*\n";
	}
	if (trustFactor_ > 50) { // Trust Factor is limited to 50
		trustFactor_ = 5; // resets to 5 when 50 is surpassed
	}

	
}


void CommonWelsh::print() { // prints out the variables in an easy to read way // defining the overriden print() method
	cout << "Common Welsh       --Current Fire Power = " << this->firePower_ << "--   --Current Charisma = " << this->charisma_ << "--   --Current Health = " << this->health_ << "--   --Trust "<< this-> trustFactor_ << "-- " << endl;
}

// getters and setters required for the game
int CommonWelsh::getHealth() {
	return health_;
}

void CommonWelsh::setHealth(int newHealth) {
	health_ = newHealth;
}

int CommonWelsh::getCharisma() {
	return charisma_;
}
void CommonWelsh::setCharisma(int newCharisma) {
	charisma_ = newCharisma;
}
int CommonWelsh::getFirepower() {
	return firePower_;
}