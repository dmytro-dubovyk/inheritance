#ifndef UNDEFINED_H
#define UNDEFINED_H

#include <iostream>

class B {
public:
    short f1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class C : virtual public B {
public:
    long f1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    int f2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class D : public C{};

class E : virtual public B {
private:
    int omg() {{ std::cout << __PRETTY_FUNCTION__ << std::endl; }}
};

class F: public D, public E{};

#endif
