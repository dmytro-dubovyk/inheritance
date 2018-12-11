#include <iostream>
#include <vector>

#include "circle.h"
#include "engine.h"
#include "mybaseclass.h"
#include "student_private.h"
#include "student_public.h"
//#include "vehicle.h"

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

    Car car;
    car.start();

    AnotherCar car2;
    car2.start();
    
    CircleInherited circle1(10.0f);
    circle1.setRadius(12.0);
    std::cout << "Radius #1 = " << circle1.getRadius()
              << ", Major radius = " << circle1.getMajorRadius() << std::endl;
    circle1.getMajorRadius();

    CircleComposed circle2(11.0f);
    circle2.setRadius(13.0);
    std::cout << "Radius #2 = " << circle2.getRadius() << std::endl;
    
    Derived d;
    d.processData();

    return 0;
}
