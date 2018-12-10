#include "student_public.h"

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
