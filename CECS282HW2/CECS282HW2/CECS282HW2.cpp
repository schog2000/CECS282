// CECS282HW2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <math.h>

int checkSeed(int seed) {
    while (seed < 1) {
        std::cout << "Enter a positive seed.\n";
        std::cin >> seed;
    }
    return seed;
}

double checkAngle(double angle) {
    while (angle < 0 || angle > 90) {
        std::cout << "Enter an angle between 0 and 90.\n";
        std::cin >> angle;
    }
    return angle;
}

double checkGunpowder(double gunpowder) {
    while (gunpowder < 0) {
        std::cout << "Enter an amount of gunpowder in kilograms.\n";
        std::cin >> gunpowder;
    }
    return gunpowder;
}

double calculateShot(double velocity, double angle, double time) {
    double calc;
    double PI = 3.14159265358979323846;
    calc = (velocity * cos((angle * PI) / 180))* time;
    return calc;
}

int checkAns(int checker, double calculatedShot, double cannonLoc) {
    if (calculatedShot > cannonLoc - 1 && calculatedShot < cannonLoc + 1) {
        std::cout << "That is a hit!\n";
        checker = 1;
    }
    else if (calculatedShot > cannonLoc + 1){
        std::cout << "You were " << (calculatedShot - cannonLoc) << " long.\n";
        checker = -1;
    }
    else {
        std::cout << "You were " << (cannonLoc - calculatedShot) << " short.\n";
        checker = -1;
    }
    return checker;
}

int main()
{
    unsigned int userSeed = -1;
    double cannonLoc;
    double angle = 0;
    double gunpowder = 0;
    double velocity;
    double time;
    double calculatedShot;
    double PI = 3.14159265358979323846;
    double g = 9.8;
    int checker = -1;

    userSeed = checkSeed(userSeed);
    std::mt19937 engine{ userSeed };

    std::default_random_engine generator(userSeed);
    std::uniform_real_distribution<double> distribution(1, 1000);
    cannonLoc = distribution(generator);
    double holdCannonLoc = cannonLoc;
    
    while (checker == -1) {
        std::cout << "The target is " << cannonLoc << " meters away.\n";

        std::cout << "Enter an angle between 0 and 90.\n";
        std::cin >> angle;
        angle = checkAngle(angle);

        std::cout << "Enter an amount of gunpowder in kilograms.\n";
        std::cin >> gunpowder;
        gunpowder = checkGunpowder(gunpowder);

        velocity = gunpowder * 30;
        time = (2.0 * velocity * sin((angle * PI) / 180)) / g;

        calculatedShot = calculateShot(velocity, angle, time);

        checker = checkAns(checker, calculatedShot, cannonLoc);
        cannonLoc = holdCannonLoc;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu