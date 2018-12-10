#ifndef STUDENT_PRIVATE_H
#define STUDENT_PRIVATE_H

#include <iostream>
#include <string>
#include <valarray>

class StudentPrivate : private std::string, private std::valarray<double> {
private:
    using ArrayDbT = std::valarray<double>;
    static constexpr auto kDefaultName = "Anonymous";
    std::ostream& arrOut(std::ostream& os) const;

public:
    StudentPrivate() : std::string(kDefaultName), ArrayDbT() {}
    explicit StudentPrivate(const std::string& s)
      : std::string(s), ArrayDbT() {}
    explicit StudentPrivate(int n) : std::string(kDefaultName), ArrayDbT(n) {}
    StudentPrivate(const std::string& s, int n)
      : std::string(s), ArrayDbT(n) {}
    StudentPrivate(const std::string& s, const ArrayDbT& a)
      : std::string(s), ArrayDbT(a) {}
    StudentPrivate(const char* str, const double* pd, int n)
      : std::string(str), ArrayDbT(pd, n) {}
    ~StudentPrivate() {}

    double average() const;
    double& operator[] (int i);
    double operator[] (int i) const;
    const std::string& name() const;

    friend std::istream& operator>>(std::istream& is, StudentPrivate& st);
    friend std::istream& getline(std::istream& is, StudentPrivate& st);
    friend std::ostream& operator<<(std::ostream& os, const StudentPrivate& st);
};

#endif
