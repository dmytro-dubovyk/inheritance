#ifndef WORKER_H
#define WORKER_H

#include <string>
namespace Workers {

class Worker {
private:
    std::string fullname{};
    long id{};

public:
    Worker();
    Worker(const std::string& s, long n);
    virtual ~Worker() = 0;

    virtual void set();
    virtual void show() const;
};

class Waiter : public Worker {
private:
    int rating{};

public:
    Waiter();
    Waiter(const std:: string& s, long n, int p = 0);
    Waiter(const Worker& wk, int p = 0);

    void set();
    void show() const;
    void data() const;
};

class Singer : public Worker {
protected:
    enum class Voices { other, alto, contralto, soprano, bass, baritone, tenor };

private:
    int voice;

public:
    Singer();
    Singer(const std::string& s, long n, int v = static_cast<int>(Voices::other));
    Singer(const Worker& wk, int v = static_cast<int>(Voices::other));
    void set();
    void show() const;
    void data() const;
};

class SingingWaiter : public Waiter, public Singer {
protected:
    void data() const;
    void get ();

public:
    SingingWaiter() = default;
    SingingWaiter(const std::string& s, long n, int p = 0, int v = static_cast<int>(Voices::other));

    void set();
    void show() const;
};

}
#endif
