#ifndef MY_BASE_CLASS_H
#define MY_BASE_CLASS_H

#include <iostream>

class BaseClass {
public:
    void processData() {
        // Pre-processing...
        processDataStep1();  // call into the future - call the derived class
        processDataStep2();  // optionally the future - this one isn't pure virtual
        // Post-processing...
    }
private:
    virtual void processDataStep1() = 0;
    virtual void processDataStep2() {
        // this is "default" code - it can optionally be customized by a derived class
        std::cout << "Running step #2 in base class" << std::endl;
    }
};

class Derived : public BaseClass {
    void processDataStep1() {
        // "future" code
        std::cout << "Running step #1 in derived class" << std::endl;
    }
};

#endif
