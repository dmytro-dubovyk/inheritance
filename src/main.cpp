#include <iostream>
#include <vector>
#include "student_private.h"
#include "student_public.h"
#include "vehicle.h"

int main() {
/*
    std::cout << "Creating car #1:" << std::endl;
    Car car1;
    std::cout << "Creating car #2:" << std::endl;
    Car car2("BMW");
    std::cout << "Creating bus #1:" << std::endl;
    Bus bus;
    std::cout << "Creating a bus #2:" << std::endl;
    DieselBus dieselBus;

    std::cout << "Creating a link to car #1:" << std::endl;
    Vehicle& pV = car1; 
    pV.drive();

    std::cout << "--------------------" << std::endl;

    FourWheelerCar fourWheelerCar;
    FourWheeler* fw = dynamic_cast<FourWheeler*>(&fourWheelerCar);
    fw->drive();

    Vehicle* vehicle = dynamic_cast<Vehicle*>(&fourWheelerCar);
    vehicle->drive();

    std::cout << "--------------------" << std::endl;
    std::vector<Vehicle*> vec{ &car1, &car2, &bus, &dieselBus };
    for(auto vehicle_ : vec) {
        vehicle_->drive();
        vehicle_->stop();
    }
    std::cout << "--------------------" << std::endl;
*/

    Student student("Vassily Poupkine", 10);
    std::cout << student;
    student = Student(5);
    std::cout << student;
    
    StudentPrivate st("Homer Simpson", 5);
    std::cout << st;
    st = StudentPrivate(10);
    std::cout << st;
    return 0;
}
