#include "student_private.h"

constexpr auto kDefaultName = "Anonymous";

double StudentPrivate::average() const {
    return ArrayDbT::size() > 0 ? ArrayDbT::sum() / ArrayDbT::size() : 0;
}

double& StudentPrivate::operator[] (int i) {
    return ArrayDbT::operator[](i);
}

double StudentPrivate::operator[] (int i) const {
    return ArrayDbT::operator[](i);
}

const std::string& StudentPrivate::name() const {
    return static_cast<const std::string&>(*this);
}

std::ostream& StudentPrivate::arrOut(std::ostream& os) const {
    size_t i{0};
    const auto lim{ArrayDbT::size()};
    if (lim > 0) {
        for (i = 0; i<lim; i++) {
            os << ArrayDbT::operator[](i) << " ";
            if (i % 5 == 4) { os << std::endl; }
        }
        if (i % 5 != 0) os << std::endl;
    } else { os << "We've got empty array!" << std::endl; }
    return os;
}

StudentPrivate::StudentPrivate() : std::string(kDefaultName), ArrayDbT() {}

StudentPrivate::StudentPrivate(const std::string &s)
    : std::string(s)
    , ArrayDbT() {}

StudentPrivate::StudentPrivate(int n) : std::string(kDefaultName), ArrayDbT(n) {}

StudentPrivate::StudentPrivate(const std::string &s, int n)
    : std::string(s)
    , ArrayDbT(n) {}

StudentPrivate::StudentPrivate(const std::string &s, const StudentPrivate::ArrayDbT &a)
    : std::string(s)
    , ArrayDbT(a) {}

StudentPrivate::StudentPrivate(const char *str, const double *pd, int n)
    : std::string(str)
    , ArrayDbT(pd, n) {}

std::istream& operator>>(std::istream& is, StudentPrivate& st) {
    is >> static_cast<std::string&>(st);
    return is;
}
std::istream& getline(std::istream& is, StudentPrivate& st) {
    std::getline(is, static_cast<std::string&>(st));
    return is;
}

std::ostream& operator<<(std::ostream& os, 
                         const StudentPrivate& st) {
    os << "Scores for: " << static_cast<const std::string&>(st) << std::endl;
    st.arrOut(os);
    return os;
}
