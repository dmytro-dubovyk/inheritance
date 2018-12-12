#ifndef WORKER_H
#define WORKER_H

#include <string>
namespace Workers {

class Worker {
private:
    std::string fullname{};
    long id{};

public:
    Worker() : fullname("Anonymous"), id(0L) {}
    Worker(const std::string& s, long n)
      : fullname(s), id(n) {}
    virtual ~Worker() = 0;

    virtual void set();
    virtual void show() const;
};

class Waiter : public Worker {
private:
    int rating{};

public:
    Waiter() : Worker(), rating(0) {}
    Waiter(const std:: string& s, long n, int p = 0)
      : Worker(s, n), rating(p) {}
    Waiter(const Worker& wk, int p = 0)
      : Worker(wk), rating(p) {}
    void set();
    void show() const;
};

class Singer : public Worker {
protected:
    enum class Voices { other, alto, contralto, soprano, bass, baritone, tenor };
    static constexpr auto kVtypes = 7; //number of items in enum

private:
    int voice;

public:
    Singer() : Worker(), voice(static_cast<int>(Voices::other)) {}
    Singer(const std::string& s, long n, int v = static_cast<int>(Voices::other))
      : Worker(s, n), voice(v) {}
    Singer(const Worker& wk, int v = static_cast<int>(Voices::other))
      : Worker(wk), voice(v) {}
    void set();
    void show() const;
};

}
#endif
