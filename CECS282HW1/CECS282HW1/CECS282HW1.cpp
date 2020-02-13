// CECS282HW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

int main()
{
    int correctDoor;
    int userPick;
    int goatDoor;
    char userAnswer;

    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(1, 3);
    correctDoor = distribution(generator);

    std::random_device rd1;
    std::default_random_engine generator1(rd1());
    std::uniform_int_distribution<int> range(1, 3);
    goatDoor = range(generator1);

    std::cout << "Choose a door from 1 to 3.\n";
    std::cin >> userPick;
    while (goatDoor == correctDoor || goatDoor == userPick) {
        goatDoor = range(generator1);
    }
    std::cout << "Door " << goatDoor << " was a goat door.\n";
    std::cout << "Would you like to switch doors? y/n\n";
    std::cin >> userAnswer;
    if (userAnswer == 'y') {
        int newPick = 1;
        if (newPick == goatDoor || newPick == userPick) {
            newPick = 2;
            if (newPick == goatDoor || newPick == userPick) {
                newPick = 3;
            }
        }
        userPick = newPick;
    }

    if (userPick != correctDoor) {
        std::cout << "Sorry, you lost.\n";
    }
    else {
        std::cout << "You won a prize.\n";
        
        std::random_device rd2;
        std::default_random_engine generator2(rd2());
        std::uniform_int_distribution<> prizeRange(1, 5);
        int prize = prizeRange(generator2);

        if (prize == 1) {
            std::cout << "You won a day to hang out with Ninja.\n";
        }
        else if (prize == 2) {
            std::cout << "You won a top of the line gaming PC.\n";
        }
        else if (prize == 3) {
            std::cout << "You won a lifetime supply of apple juice.\n";
        }
        else if (prize == 4) {
            std::cout << "You won a getaway trip to Sri Lanka.\n";
        }
        else {
            std::cout << "You won an immunity to the CoronaVirus.\n";
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
