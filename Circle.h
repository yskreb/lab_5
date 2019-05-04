//
// Created by sonic on 04.05.19.
//

#ifndef LAB5_CIRCLE_H
#define LAB5_CIRCLE_H


#include "Vector2D.h"
#include <vector>
#include <string>

class Circle {
private:
    const double DENSITY = 21.5;
    const double PI = 3.1415;
    const char *name = "Circle";
    const int height = 1;

protected:
    int radius;
public:

    Circle() {};

    Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {};

    ~Circle() {};

    Circle &operator=(const Circle &v) {
        radius = v.radius;
        return *this;
    }

    double x, y;

    double square();

    double perimeter();

    unsigned int size();

    const char *classname();

    void draw();

    void initFromDialog(std::vector<std::string> args);

    double mass();

    Vector2D position();

    bool operator==(const Circle &obj) const;

    bool operator<(const Circle &obj) const;
};


#endif //LAB5_CIRCLE_H
