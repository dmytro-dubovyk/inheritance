#ifndef CIRCLE_H
#define CIRCLE_H

class Ellipse {
public:
    explicit Ellipse(float r1 = 0.0, float r2 = 0.0)
      : majorRadius(r1), minorRadius(r2) {}

    float getMajorRadius() const { return majorRadius; }
    float getMinorRadius() const { return minorRadius; }

    void setMajorRadius(float r) { majorRadius = r; }
    void setMinorRadius(float r) { minorRadius = r; }

private:
    float majorRadius{};
    float minorRadius{};
};

class CircleInherited : private Ellipse {
public:
    explicit CircleInherited(float r) : Ellipse(r, r) {}
    using Ellipse::getMajorRadius;
    using Ellipse::getMinorRadius;

    void setRadius(float r) {
        setMajorRadius(r);
        setMinorRadius(r);
    }

    float getRadius() const { return getMajorRadius(); }
};

class CircleComposed {
public:
    explicit CircleComposed(float r) : ellipse(r, r) {}
    void setRadius(float r) {
        ellipse.setMajorRadius(r);
        ellipse.setMinorRadius(r);
    }

    float getRadius() const { return ellipse.getMajorRadius(); }
private:
    Ellipse ellipse;
};

#endif
