#ifndef VEHICLE_H
#define VEHICLE_H

class Engine {
public:
    explicit Engine(int cylinders);
    Engine() = delete;
    virtual ~Engine() = default;

    int getCylinders() const;
    void start() const;

protected:
    int mCylinders;
};

class Car : protected Engine {
public:
    explicit Car(int nc = 4);
    virtual ~Car() = default;

    void start() const;
};

class BigCar final : protected Car {
public:
    BigCar(int nc = 8);
    ~BigCar() = default;

    void start() const;
};

#endif // VEHICLE_H
