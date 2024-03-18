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
// <This file contains the 'main' function. Program execution begins and ends there. Hosts the Dragon game with user input>
//
// Instructor: Jocelyn Richardt
// Assignment: <OO Design & C++ Review (Dragon Classes)>
// Student: <Adam McGlin>
// Date: <3/18/2024>
//
// ---------------------------------------------------------------------------

// set up
#include <iostream>
#include "Dragon.h"
#include "ChineseFireball.h"
#include "CommonWelsh.h"
#include "HungarianHorntail.h"
#include <list>

int CommonWelsh::trustFactor_ = 5; // sets the static int trustFactor_ variable to 5 for the Common Welsh Dragon's train() to work properly

Dragon* select(list<Dragon*>& paramDragon) { // asks the user which Dragon from their list they would like to Train/Battle/Recruit with
    int index = 1;
    int dragonChoice;
    bool invalid = true;
    for (Dragon* dragon : paramDragon) { // prints out all of the options (with numbers) 
        cout << index << ". ";
        dragon->print();
        index++;
    }   
    while (invalid) { // makes sure they select in bounds
        cout << "Enter the index of the dragon you want to select: ";
        cin >> dragonChoice;
        if (dragonChoice > paramDragon.size() || dragonChoice < 1) {
            cout << "Please enter a valid index " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            continue;
        }
        else {
            list<Dragon*>::iterator iter = paramDragon.begin();
            advance(iter, dragonChoice - 1);
            invalid = false;
            return *iter; // returns the Dragon the user selected
        }
    }
}

void moveDragonToEnd(list<Dragon*>& paramDragon, Dragon* selectedDragon) { // moves the selected Dragon to the end of the linked list
    for (list<Dragon*>::iterator iterMove = paramDragon.begin(); iterMove != paramDragon.end(); iterMove++) {
        if (*iterMove == selectedDragon) {
            paramDragon.splice(paramDragon.end(), paramDragon, iterMove);
        }
    }
}

void moveDragonToFront(list<Dragon*>& paramDragon, Dragon* selectedDragon) { // moves the selected Dragon to the front of the linked list
    for (list<Dragon*>::iterator iterMove = paramDragon.begin(); iterMove != paramDragon.end(); ++iterMove) {
        if (*iterMove == selectedDragon) {
            paramDragon.splice(paramDragon.begin(), paramDragon, iterMove);
        }
    }
}

Dragon* getRandomEnemyDragon() { // creates a random Dragon (used for game creation, recruits, and battles) 
    int choice = rand() % 3;
    Dragon* enemyDragon = nullptr;
    if (choice == 0) {
        enemyDragon = new HungarianHorntail();
    }
    else if (choice == 1) {
        enemyDragon = new CommonWelsh();
    }
    else {
        enemyDragon = new ChineseFireball();
    }
    return enemyDragon;
}

bool battleDragons(Dragon* playerDragon, Dragon* enemyDragon, bool isRecruitOrTraining) { // used for all of the dragon battles
    // used for battle setup and makes sure no data is lost 
    int potentialDamage = playerDragon->getFirepower();
    int enemyPotentialDamage = enemyDragon->getFirepower();
    int actualDamage;
    int playerMaxHealth = playerDragon->getHealth();
    int enemyMaxHealth = enemyDragon->getHealth();
    int playerActualHealth = playerMaxHealth;
    int enemyActualHealth = enemyMaxHealth;

    cout << "\n" << endl;
    if (isRecruitOrTraining == false) { // makes sure the correct Dragon goes first
        while (enemyDragon->getHealth() > 0 && playerDragon->getHealth() > 0) {
            if (enemyDragon->getHealth() > 0 && playerDragon->getHealth() > 0) {
                int choice = rand() % 101;
                actualDamage = choice * potentialDamage * 0.01; // gives the attacks a percent hit
                cout << "Your Dragon attacks the enemy Dragon dealing " << actualDamage << "! " << endl;
                enemyDragon->setHealth(enemyActualHealth - actualDamage);
                enemyActualHealth = enemyDragon->getHealth();
                enemyDragon->print();
                cout << "\n" << endl;
            }
            if (enemyDragon->getHealth() > 0 && playerDragon->getHealth() > 0) {
                int choice = rand() % 101;
                actualDamage = choice * enemyPotentialDamage * 0.01; // gives the attacks a percent hit
                cout << "The enemy Dragon attacks your Dragon dealing " << actualDamage << "! " << endl;
                playerDragon->setHealth(playerActualHealth - actualDamage);
                playerActualHealth = playerDragon->getHealth();
                playerDragon->print();
                cout << "\n" << endl;
            }
        }
    }
    else { // same thing just flipped to make sure the correct Dragon goes first
        while (enemyDragon->getHealth() > 0 && playerDragon->getHealth() > 0) {
            if (enemyDragon->getHealth() > 0 && playerDragon->getHealth() > 0) {
                int choice = rand() % 101;
                actualDamage = choice * enemyPotentialDamage * 0.01; // gives the attacks a percent hit
                cout << "The enemy Dragon attacks your Dragon dealing " << actualDamage << "! " << endl;
                playerDragon->setHealth(playerActualHealth - actualDamage);
                playerActualHealth = playerDragon->getHealth();
                playerDragon->print();
                cout << "\n" << endl;
            }
            if (enemyDragon->getHealth() > 0 && playerDragon->getHealth() > 0) {
                int choice = rand() % 101;
                actualDamage = choice * potentialDamage * 0.01; // gives the attacks a percent hit
                cout << "Your Dragon attacks the enemy Dragon dealing " << actualDamage << "! " << endl;
                enemyDragon->setHealth(enemyActualHealth - actualDamage);
                enemyActualHealth = enemyDragon->getHealth();
                enemyDragon->print();
                cout << "\n" << endl;
            }
        }
    }

    if (enemyDragon->getHealth() <= 0 && playerDragon->getHealth() > 0) { // won the battle
        cout << "Your Dragon won and you recruited the defeated Dragon! " << endl;
        enemyDragon->setHealth(enemyMaxHealth);
        playerDragon->setHealth(playerMaxHealth + 10);
        return true; 
    }
    else if (enemyDragon->getHealth() > 0 && playerDragon->getHealth() <= 0) { // lost the battle
        cout << "Your Dragon lost and died :( " << endl;
        delete enemyDragon; // deletes enemy Dragon
        return false; // used to delete the other Dragon
    }
    else { // failsafe just incase
        cout << "Something went wrong." << endl; 
        return false;
    }
    return false;
}

int main() // 'main' function
{
    srand((unsigned int)time(NULL)); // sets the seed for the random number generator based on time
    list<Dragon*> playerDragons; // creates the dragons LinkedList for the player holding the 3 Dragon objects
    string user;
    int choice;
    bool game = true;
    bool winBattle;
    int index;
    int currentHealthHolder;
    int actualCharisma;
    int enemyActualCharisma;
    int maxCharisma;

    for (int i = 0; i < 3; i++) { // makes the army of 3 player Dragons
        Dragon* tempDragon = getRandomEnemyDragon();
        playerDragons.push_back(tempDragon);
    }
    while (game == true) { 
        cout << "Here are your dragons" << endl;
        index = 1;
        for (Dragon* dragon : playerDragons) {
            cout << index << ". ";
            dragon->print();
            index++;
        }
        Dragon* selectedDragon = nullptr;
        cout << "\nWhat would you like to do? (Train, Recruit, or Battle) " << endl; // asks for user input
        cin >> user;
        if (user == "Train" || user == "t" || user == "T" || user == "train") { // train
            selectedDragon = select(playerDragons);
            cout << "You have selected ";
            selectedDragon->print();
            cout << "\n";
            selectedDragon->train();
            currentHealthHolder = selectedDragon->getHealth();
            selectedDragon->setHealth(currentHealthHolder - 20); // training is exhausting
            choice = rand() % 100; // used to see if attacked

            if (choice < 10) { // 10% chance of being attacked while training
                Dragon* trainDragon = getRandomEnemyDragon();
                cout << "Oh no! An enemy Dragon has found you training and attacked! " << endl;
                trainDragon->print();
                winBattle = battleDragons(selectedDragon, trainDragon, true);
                if (winBattle) { // won the battle
                    moveDragonToFront(playerDragons, selectedDragon);
                    cout << "Trained Dragon: " << endl;
                    selectedDragon->print();
                }
                else { // lost the battle
                    moveDragonToEnd(playerDragons, selectedDragon);
                    playerDragons.pop_back();
                    delete selectedDragon;
                }
                
            }
            else { // only moves to the end of the linkedlist if not attacked (from how I interpreted it)
                moveDragonToEnd(playerDragons, selectedDragon);
                selectedDragon->setHealth(currentHealthHolder);
                cout << "Trained Dragon: " << endl;
                selectedDragon->print();
            }
            cout << "\n" << endl;
        }
        else if (user == "Recruit" || user == "recruit" || user == "r" || user == "R") { // recruit
            selectedDragon = select(playerDragons);

            cout << "\nA Dragon approaches: " << endl;
            Dragon* dragonRecruit = getRandomEnemyDragon();
            dragonRecruit->print();
            maxCharisma = selectedDragon->getCharisma();
            enemyActualCharisma = dragonRecruit->getCharisma();
            actualCharisma = maxCharisma;
            if (actualCharisma > enemyActualCharisma) { // recruit the dragon
                playerDragons.push_back(dragonRecruit);
                if (selectedDragon->getCharisma() < 96) {
                    selectedDragon->setCharisma(maxCharisma + 5);
                }
            }
            else { // fight the Dragon (because charisma was not higher)
                winBattle = battleDragons(selectedDragon, dragonRecruit, true);
                if (winBattle) { // won the battle
                    moveDragonToFront(playerDragons, selectedDragon);
                    playerDragons.push_back(dragonRecruit);
                }
                else { // lost the battle and deletes Dragon
                    moveDragonToEnd(playerDragons, selectedDragon);
                    playerDragons.pop_back();
                    delete selectedDragon;
                }
                
            }

        }
        else if (user == "Battle" || user == "battle" || user == "b" || user == "B") { // battle
            selectedDragon = select(playerDragons);
            cout << "\nAn enemy Dragon approaches: " << endl;
            Dragon* dragonFight = getRandomEnemyDragon();
            dragonFight->print();
            winBattle = battleDragons(selectedDragon, dragonFight, false);
            if (winBattle) { // won the battle
                moveDragonToFront(playerDragons, selectedDragon);
                playerDragons.push_back(dragonFight);
            }
            else { // lost the battle and deletes Dragon
                moveDragonToEnd(playerDragons, selectedDragon);
                playerDragons.pop_back();
                delete selectedDragon;
            }
           
        }
        else {
            cout << "Invalid Input. " << endl;
        }

        if (playerDragons.size() == 0) { // ends the game if no available Dragons
            game = false;
        }
    }

    cout << "Game Over. " << endl;
    

}
