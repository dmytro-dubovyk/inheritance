#include <iostream>
#include <vector>

// Please uncomment one of te defines to build Block #0 or Block #1
#define BLOCK0
//#define BLOCK1

#ifdef BLOCK0
#include "engine.h"
#endif

#ifdef BLOCK1
#include "vehicle.h"
#endif

int main() {
// Block #0. Make sure Block #1 is undefined before using it
#ifdef BLOCK0
    {
    Car car;
    car.start();

    AnotherCar car2;
    car2.start();

    BigCar car3;
    car3.start();
#endif
//--------------------

// Block #1. Make sure Block #0 is undefined before using it
#ifdef BLOCK1
    std::cout << "Creating car #1:" << std::endl;
    Car car1;
    std::cout << "Creating car #2:" << std::endl;
    Car car2("BMW");
    std::cout << "Creating bus #1:" << std::endl;
    Bus bus;
    std::cout << "Creating a bus #2:" << std::endl;
    DieselBus dieselBus;

    std::cout << "Creating a link to a base class and calling drive() in a derived one: " << std::endl;
    Vehicle& pV = car1; 
    pV.drive();

    std::cout << "--------------------" << std::endl;

    FourWheelerCar fourWheelerCar;    
    FourWheeler* fw = //dynamic_cast<FourWheeler*>
                      (&fourWheelerCar);
    fw->drive();

    Vehicle* vehicle = //dynamic_cast<Vehicle*>
                       (&fourWheelerCar);
    vehicle->drive();

    FourWheelerCar* pCar{nullptr};
    //let's check if we can downcast parent to a child
    if (pCar = dynamic_cast<FourWheelerCar*>(vehicle)) {
        std::cout<< " object is FourWheelerCar" << std::endl;
    } else {
        std::cout<< "can't cast objects" << std::endl;
    }

    std::cout << "--------------------" << std::endl;
    std::vector<Vehicle*> vec{ &car1, &car2, &bus, &dieselBus };
    for(auto vehicle_ : vec) {
        vehicle_->drive();
        vehicle_->stop();
    }
    std::cout << "--------------------" << std::endl;
//--------------------
#endif
    return 0;
}
