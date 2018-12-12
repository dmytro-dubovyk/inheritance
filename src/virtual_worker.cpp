#include "virtual_worker.h"

#include <iostream>

namespace VirtualWorkers {

Worker::~Worker() { std::cout << "destroying Worker object" << std::endl; }

void Worker::data() const {
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}

void Worker::get() {
    std::getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n') continue;
}

//---------- Waiter methods

void Waiter::set() {
    std::cout << "Enter Waiter's name: ";
    Worker::get();
    get(); //now calling our protected method
}

void Waiter::show() const {
    std::cout << "Category: waiter\n";
    Worker::data();
    data(); //the same: calling our protected method
}

void Waiter::get() {
    std::cout << "Enter waiter's rating: ";
    std::cin >> rating;
    while (std::cin.get() != '\n') continue;
}

void Waiter::data() const {
    std::cout << "Waiter's rating: " << rating << std::endl;
}
//---------- Singer methods
static const char* pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::set() {
    std::cout << "Enter Singer's name: ";
    Worker::get();
    get();
}

void Singer::show() const {
    std::cout << "Category: singer" << std::endl;
    Worker::data();
    data();
}

void Singer::get() {
    std::cout << "Enter number for singer's vocal range:" << std::endl;
    int i{};
    for (i = 0; i < kVtypes; i++) {
        std::cout << i << ":" << pv[i] << " ";
        if ( i % 4 == 3) std::cout << std::endl;
    }

    if (i % 4 != 0) std::cout << std::endl;
    while (std::cin >> voice && (voice < 0 || voice >= kVtypes)) {
        std::cout << "Please enter a value >= 0 and < "
                  << kVtypes << std::endl;
    }
    while (std::cin.get() != '\n') continue;
}

void Singer::data() const {
    std::cout << "Vocal range: " << pv[voice] << std::endl;
}

//---------- SingingWaiter methods
void SingingWaiter::data() const {
    Singer::data();
    Waiter::data();
}

void SingingWaiter::get() {
    Waiter::get();
    Singer::get();
}

void SingingWaiter::set() {
    std::cout << "Enter singing waiter's name: ";
    Worker::get();
    get();
}

void SingingWaiter::show() const {
    std::cout << "Category: singing waiter" << std::endl;
    Worker::data();
    data();
}
}
