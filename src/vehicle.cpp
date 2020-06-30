#include "vehicle.h"

#include <iostream>

Engine::Engine(int cylinders)
    : mCylinders{cylinders} {
}

int Engine::getCylinders() const {
    return mCylinders;
}

void Engine::start() const {
    std::cout << mCylinders << " cylinder engine started" << std::endl;
}

// 1st derived
Car::Car(int nc)
    : Engine(nc) {}

void Car::start() const {
    std::cout << "Car with " << mCylinders//Engine::getCylinders()
              << " cylinder engine started" << std::endl;
}


// 2nd derived
BigCar::BigCar(int nc)
    : Car(nc) {}

void BigCar::start() const {
    std::cout << "Big Car started" << mCylinders << std::endl;
    Engine::start();
    Car::start();
}
