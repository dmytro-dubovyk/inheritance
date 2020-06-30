#ifndef UNDEFINED_H
#define UNDEFINED_H

#include <iostream>

class B {
public:
    short f1() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return 0;
    }
};

class C : virtual public B {
public:
    long f1() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return 0;
    }

    int f2() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return 0;
    }
};

class D : public C{};

class E : virtual public B {
protected:
    int f2() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return 0;
    }
};

class F: public D, public E{
public:
    int f2() {
        E::f2();
        return C::f2();
    }
};

#endif
