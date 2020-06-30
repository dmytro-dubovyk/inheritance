#ifndef VIRTUAL_WORKER_H
#define VIRTUAL_WORKER_H

#include <string>
namespace VirtualWorkers {

class Worker {
private:
    std::string fullname{};
    long id{};

protected:
    virtual void data() const;
    virtual void get();

public:
    Worker()
      : fullname("Anonymous"), id(0L) {}
    Worker(const std::string& s, long n)
      : fullname(s), id(n) {}
    virtual ~Worker() = 0;

    virtual void set() = 0;
    virtual void show() const = 0;
};

class Waiter : virtual public Worker {
private:
    int rating{};

protected:
    virtual void data() const;
    virtual void get();

public:
    Waiter()
      : Worker(), rating(0) {}
    Waiter(const std:: string& s, long n, int p = 0)
      : Worker(s, n), rating(p) {}
    Waiter(const Worker& wk, int p = 0)
      : Worker(wk), rating(p) {}
    void set();
    void show() const;
};

class Singer : public virtual Worker {
protected:
    enum class Voices { other, alto, contralto, soprano, bass, baritone, tenor };

    virtual void data() const;
    virtual void get();

private:
    int voice;

public:
    Singer()
      : Worker(), voice(static_cast<int>(Voices::other)) {}
    Singer(const std::string& s, long n, int v = static_cast<int>(Voices::other))
      : Worker(s, n), voice(v) {}
    Singer(const Worker& wk, int v = static_cast<int>(Voices::other))
      : Worker(wk), voice(v) {}
    void set();
    void show() const;
};

class SingingWaiter final : public Waiter, public Singer {
protected:
    void data() const;
    void get ();

public:
    SingingWaiter() {}
    SingingWaiter(const std::string& s, long n, int p = 0, int v = static_cast<int>(Voices::other))
      : Worker(s,n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter (const Worker& wk, int p = 0, int v = static_cast<int>(Voices::other))
      : Worker(wk), Waiter(wk,p), Singer(wk,v) {}
    SingingWaiter(const Waiter& wt, int v = static_cast<int>(Voices::other))
      : Worker(wt), Waiter(wt), Singer(wt,v) {}
    SingingWaiter(const Singer& wt, int p = 0)
      : Worker(wt), Waiter(wt,p), Singer(wt) {}

    void set();
    void show() const;
};
}

#endif
