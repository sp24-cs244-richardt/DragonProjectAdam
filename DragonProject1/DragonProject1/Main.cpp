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
// <Main.cpp>
//
// <This file contains the 'main' function. Program execution begins and ends there>
//
// Instructor: Jocelyn Richardt
// Assignment: <OO Design & C++ Review (Dragon Classes)>
// Student: <Adam McGlin>
// Date: <2/17/2024>
//
// ---------------------------------------------------------------------------

// set up
#include <iostream>
#include "Dragon.h";
#include "ChineseFireball.h";
#include "CommonWelsh.h";
#include "HungarianHorntail.h";

int CommonWelsh::trustFactor_ = 5; // sets the static int trustFactor_ variable to 5 for the Common Welsh Dragon's train() to work properly

int main() // 'main' function
{
    srand((unsigned int)time(NULL)); // sets the seed for the random number generator based on time

    Dragon* dragons[9]; // creates the dragons array for holding Dragon objects
    for (int i = 0; i < 9; i++) { 
            if (i >= 6) { 
                dragons[i] = new HungarianHorntail();
            }
            else if (i >= 3) { 
                dragons[i] = new CommonWelsh();
            }
            else if (i >= 0) { 
                dragons[i] = new ChineseFireball();
            }
        
    }
    
    std::cout << "------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < 9; i++) {
        std::cout << "First Print: \n"; 
        dragons[i]->print(); // prints the dragon using its own correctly overriden print() method
        std::cout << "Train + Second Print: \n";
        dragons[i]->train(); // uses the dragon's own overriden train() method
        dragons[i]->print(); // prints the dragon using its own correctly overriden print() method
        std::cout << "------------------------------------------------------------------------------------------------\n"; 
    }
}

