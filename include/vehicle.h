#include <iostream>

class Vehicle {
  public:
    Vehicle() { std::cout << "This is a Vehicle" << std::endl; }
    Vehicle(const std::string& name) {
        mName = name;
        std::cout << "This is a Vehicle named " << mName << std::endl;
    }
    ~Vehicle() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    virtual void drive() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
    virtual void stop() = 0;

private:
    std::string mName{};
};

class FourWheeler {
  public:
    FourWheeler() {
      std::cout << "This is a 4 wheeler Vehicle" << std::endl;
    }
    ~FourWheeler() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void drive() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
    virtual void stop() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
};

class Car: public Vehicle {
public:
    Car() { std::cout << "This is a Car" << std::endl; }
    Car(const std::string& name)
      : Vehicle(name) {
        std::cout << "This is a Car named " << name << std::endl;
    }

    ~Car() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    void drive() override { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
    void stop() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
};

class FourWheelerCar : public Vehicle, public FourWheeler {
public:
    FourWheelerCar() { 
        std::cout << "This is a Four Wheeler Car" << std::endl;
    }

    void drive() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
    void stop() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
};

class Bus : public Vehicle {
public:
    Bus() { std::cout << "This is a Bus" << std::endl; }
    ~Bus() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    virtual void drive() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
    virtual void stop() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
};

class Diesel {
public:
    Diesel() { std::cout<<"Diesel engine of a Vehicle" << std::endl; }
    ~Diesel() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class DieselBus : public Bus, Diesel {
public:
    DieselBus() { std::cout<<"Here's the bus with diesel engine" << std:: endl; }
    ~DieselBus() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    virtual void drive() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
    virtual void stop() { std::cout << "calling " << __PRETTY_FUNCTION__ << std::endl; }
};
