#include <iostream>
#include <vector>

#include "circle.h"
#include "mybaseclass.h"
#include "student_private.h"
#include "student_public.h"

int main() {
// Block #2

    Student student("Vassily Poupkine", 10);
    std::cout << student;
    student = Student(5);
    std::cout << student;

    StudentPrivate st("Homer Simpson", 5);
    std::cout << st;
    st = StudentPrivate(10);
    std::cout << st;

// Block #3

    CircleInherited circle1(10.0f);
    circle1.setRadius(12.0);
    std::cout << "Radius #1 = " << circle1.getRadius()
              << ", Major radius = " << circle1.getMajorRadius() << std::endl;
    circle1.getMajorRadius();

    CircleComposed circle2(11.0f);
    circle2.setRadius(13.0);
    std::cout << "Radius #2 = " << circle2.getRadius() << std::endl;

    Derived d;
    d.processData();

    return 0;
}
