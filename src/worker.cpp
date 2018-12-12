#include "worker.h"

#include <iostream>

namespace Workers {

Worker::~Worker() { std::cout << "destroying Worker object" << std::endl; }

void Worker::set() {
    std::cout << "Enter worker's name: ";
    std::getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n') continue;
}

void Worker::show() const {
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}

void Waiter::set() {
    Worker::set();
    std::cout << "Enter waiter's rating: ";
    std::cin >> rating;
    while (std::cin.get() != '\n') continue;
}

void Waiter::show() const {
    std::cout << "Category: waiter\n";
    Worker::show();
    std::cout << "Waiter's rating: " << rating << std::endl;
}

static const char* pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::set() {
    Worker::set();
    std::cout << "Enter number for singer's vocal range:\n";
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

void Singer::show() const {
    std::cout << "Category: singer\n";
    Worker::show();
    std::cout << "Vocal range: " << pv[voice] << std::endl;
}

}
