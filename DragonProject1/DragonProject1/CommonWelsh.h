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
// <CommonWelsh.h>
//
// <Creates the needed private static variable, the constructors, and makes (overrides) but does not define all of the needed public methods for CommonWelsh.cpp>
//
// Instructor: Jocelyn Richardt
// Assignment: <OO Design & C++ Review (Dragon Classes)>
// Student: <Adam McGlin>
// Date: <2/17/2024>
//
// ---------------------------------------------------------------------------

// set up
#pragma once
#ifndef COMMONWELSH_H
#define COMMONWELSH_H
#include "Dragon.h"

class CommonWelsh : public Dragon // CommonWelsh is a subclass of Dragon
{
	public:
		void train() override; // overriding Dragon.h
		void print() override; // overriding Dragon.h
		CommonWelsh(); // declaration of default constructor
	private:
		int static trustFactor_;
};

#endif