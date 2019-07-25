#include <iostream>
#include <vector>

#include "circle.h"
//#include "engine.h"
#include "mybaseclass.h"
#include "student_private.h"
#include "student_public.h"
#include "vehicle.h"
#include "virtual_worker.h"
#include "worker.h"
#include "undefined.h"

int main() {
// Block #1
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


// Block #2
/*
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

    BigCar car3;
    car3.start();
*/

// Block #3
/*
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


    BigCar car;
    car.start();

    //using namespace Workers;
    using namespace VirtualWorkers;

    Waiter waiter("Vassily Popkine", 123L, 4);
    Singer singer("Ivan Piotr", 666L, 3);
    Waiter w_temp;
    Singer s_temp;
    Worker* pw[4] = { &waiter, &singer, &w_temp, &s_temp };
    int i{};
    for (i = 2; i < 4; i++) pw[i]->set();
    for (i = 0; i < 4; i++) {
        pw[i]->show();
        std::cout << std::endl;
    }

    SingingWaiter sw;
    sw.set();
    sw.show();

    F f;
    f.f1();
    f.f2();
*/
    return 0;
}
