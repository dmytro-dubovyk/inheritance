#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

class Engine {
public:
    Engine(int nc) : cylinder(nc) {}

    void start() const {
        std::cout << getCylinder() << " cylinder engine started" << std::endl;
    };

    int getCylinder() const { return cylinder; }

private:
    int cylinder;
};

class Car : private Engine { // Car has-a Engine
public:
    Car(int nc = 4) : Engine(nc) {}

    virtual void start() {
        std::cout << "Car with " << Engine::getCylinder()
                  << " cylinder engine started" << std::endl;
        Engine:: start();
    }
};

class AnotherCar {
public:
    AnotherCar(int n = 6): engine(n) {}  

    void start() {
        std::cout << "Car with " << engine.getCylinder()
                  << " cylinder engine started" << std::endl;
        engine.start();
    }

private:
    Engine engine; // Car has-a Engine
 };

class BigCar : protected Car {
public:
    BigCar(int nc = 8) : Car(nc) {}
    void start() {
        std::cout << "Big Car started" << std::endl;
        Car::start();
    }
};

#endif
