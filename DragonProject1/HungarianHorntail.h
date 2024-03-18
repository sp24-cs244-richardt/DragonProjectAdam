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
// <HungarianHorntail.h>
//
// <Creates the constructors, and makes (overrides) but does not define all of the needed public methods for HungarianHorntail.cpp>
//
// Instructor: Jocelyn Richardt
// Assignment: <OO Design & C++ Review (Dragon Classes)>
// Student: <Adam McGlin>
// Date: <3/18/2024>
//
// ---------------------------------------------------------------------------

// set up
#pragma once
#include "Dragon.h";

class HungarianHorntail : public Dragon // HungarianHorntail is a subclass of Dragon
{
	public:
		void train() override; // overriding Dragon.h
		void print() override; // overriding Dragon.h
		int getHealth() override; // overriding Dragon.h
		void setHealth(int newHealth) override; // overriding Dragon.h
		int getCharisma() override; // overriding Dragon.h
		void setCharisma(int newCharisma) override; // overriding Dragon.h
		int getFirepower() override; // overriding Dragon.h
		HungarianHorntail() : Dragon("Black", "Hungary", (firePower_ = (rand() % 75) + 10), (rand() % 30) + 60, (rand() % 20) + 75) {}; // declaration of constructor
};