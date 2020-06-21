#include "student_public.h"

constexpr auto kDefaultName = "Anonymous";

double Student::average() const {
    return scores_.size() > 0 ? scores_.sum() / scores_.size() : 0;
}

const std::string& Student::name() const {
    return name_;
}

double& Student::operator[] (int i) {
    return scores_[i];
}

double Student::operator[] (int i) const {
    return scores_[i];
}

std::ostream& Student::arrOut(std::ostream& os) const {
    const auto lim{scores_.size()};
    size_t i{0};
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << scores_[i] << " ";
            if (i % 5 == 4) { os << std::endl; }
        }

        if (i % 5 != 0) { os << std::endl; }
    } else { os << "We've got empty array!" << std::endl; }
    return os;
}

Student::Student() : name_(kDefaultName), scores_() {}

Student::Student(const std::string &s)
    : name_(s)
    , scores_() {}

Student::Student(int n) : name_(kDefaultName), scores_(n) {}

Student::Student(const std::string &s, int n)
    : name_(s)
    , scores_(n) {}

Student::Student(const std::string &s, const Student::ArrayDbT &a)
    : name_(s)
    , scores_(a) {}

Student::Student(const char *str, const double *pd, int n)
    : name_(str)
    , scores_(pd, n) {}

std::istream& operator >> (std::istream& is, Student& st) {
    is >> st.name_;
    return is;
}

std::istream& getline(std::istream& is, Student& st) {
    std::getline(is, st.name_);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Student& st) {
    os << "Scores for " << st.name_ << " :\n";
    st.arrOut(os);
    return os;
}
