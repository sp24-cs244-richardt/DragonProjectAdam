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
// <Dragon.h>
//
// <Creates all of the protected variables, the constructors, and makes all of the needed public abstract methods for other methods to override.
// This class is abstract and serves as a base class for all types of dragons. >
//
// Instructor: Jocelyn Richardt
// Assignment: <OO Design & C++ Review (Dragon Classes)>
// Student: <Adam McGlin>
// Date: <2/17/2024>
//
// ---------------------------------------------------------------------------

// set up
#pragma once
#include <string>;
#include <iostream>
#include <random>;
#include <time.h>;
using namespace std;

class Dragon
{
protected: 
	string skinColor_;
	string nativeRange_;
	int firePower_;
public:
	virtual void train() = 0; // abstract method
	virtual void print() = 0; // abstract method
	Dragon(string skinColor, string nativeRange, int firePower){
		this->firePower_ = firePower;
		this->skinColor_ = skinColor;
		this->nativeRange_ = nativeRange;
	}
};

