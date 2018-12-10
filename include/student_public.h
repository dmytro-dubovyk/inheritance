#ifndef STUDENT_PUBLIC_H
#define STUDENT_PUBLIC_H

#include <iostream>
#include <string>
#include <valarray>

class Student {
private:
    using ArrayDbT = std::valarray<double>;
    static constexpr auto kDefaultName = "Anonymous";

    std::string name_;
    ArrayDbT scores_;

    std::ostream& arrOut(std::ostream& os) const;

public:
    Student() : name_(kDefaultName), scores_() {}
    explicit Student(const std::string& s)
      : name_(s), scores_() {}
    explicit Student(int n) : name_(kDefaultName), scores_(n) {}
    Student(const std::string& s, int n)
      : name_(s), scores_(n) {}
    Student(const std::string& s, const ArrayDbT& a)
      : name_(s), scores_(a) {}
    Student(const char* str, const double* pd, int n)
      : name_(str), scores_(pd, n) {}
    ~Student() {}

    double average() const;
    double& operator[] (int i);
    double operator[] (int i) const;
    const std::string& name() const;

    friend std::istream& operator>>(std::istream& is, Student& st);
    friend std::istream& getline(std::istream& is, Student& st);
    friend std::ostream& operator<<(std::ostream& os, const Student& st);
};

#endif
