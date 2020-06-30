#include "worker.h"

#include <iostream>

namespace Workers {

static constexpr char* pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};
static constexpr auto kVtypes = sizeof(pv)/sizeof(pv[0]); //number of items in enum

Worker::~Worker() { std::cout << "destroying Worker object" << std::endl; }

Worker::Worker()
    : fullname("Anonymous"), id(0L) {}

Worker::Worker(const std::string &s, long n)
    : fullname(s), id(n) {}

void Worker::set() {
    std::cout << "Enter worker's name: ";
    std::getline(std::cin, fullname);
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n') { continue; }
}

void Worker::show() const {
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Employee ID: " << id << std::endl;
}

Waiter::Waiter()
    : Worker(), rating(0) {}

Waiter::Waiter(const std::string &s, long n, int p)
    : Worker(s, n), rating(p) {}

Waiter::Waiter(const Worker &wk, int p)
    : Worker(wk), rating(p) {}

void Waiter::set() {
    Worker::set();
    std::cout << "Enter waiter's rating: ";
    std::cin >> rating;
    while (std::cin.get() != '\n') { continue; }
}

void Waiter::show() const {
    std::cout << "Category: waiter\n";
    Worker::show();
    std::cout << "Waiter's rating: " << rating << std::endl;
}

void Waiter::data() const {
    std::cout << "Waiter's rating: " << rating << std::endl;
}

//------- Singer implementation
Singer::Singer()
    : Worker(), voice(static_cast<int>(Voices::other)) {}

Singer::Singer(const std::string &s, long n, int v)
    : Worker(s, n), voice(v) {}

Singer::Singer(const Worker &wk, int v)
    : Worker(wk), voice(v) {}

void Singer::set() {
    Worker::set();
    std::cout << "Enter number for singer's vocal range:\n";
    int i{};
    for (i = 0; i < kVtypes; i++) {
        std::cout << i << ":" << pv[i] << " ";
        if ( i % 4 == 3) { std::cout << std::endl; }
    }

    if (i % 4 != 0) { std::cout << std::endl; }
    while (std::cin >> voice && (voice < 0 || voice >= kVtypes)) {
        std::cout << "Please enter a value >= 0 and < "
                  << kVtypes << std::endl;
    }
    while (std::cin.get() != '\n') { continue; }
}

void Singer::show() const {
    std::cout << "Category: singer\n";
    Worker::show();
    std::cout << "Vocal range: " << pv[voice] << std::endl;
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
    //Waiter::get();
    //Singer::get();
}

SingingWaiter::SingingWaiter(const std::string &s, long n, int p, int v)
    : Waiter(s, n, p), Singer(s, n, v) {}

void SingingWaiter::set() {
    std::cout << "Enter singing waiter's name: ";
    //Worker::get();
    get();
}

void SingingWaiter::show() const {
    std::cout << "Category: singing waiter" << std::endl;
    data();
}
}
