//
// Created by sonic on 04.05.19.
//

#include <iostream>
#include "Circle.h"

using namespace std;

double Circle::square() {
    return PI * radius * radius;
};

double Circle::perimeter() {
    return 2. * PI * radius;
};

const char *Circle::classname() {
    return name;
};

unsigned int Circle::size() {
    return sizeof(Circle);
};

void Circle::draw() {
    cout << "Classname =\t\t" << classname() << "\n";
    cout << classname() << " centre= \t\t(" << x << ", " << y << ")\n";
    cout << classname() << " radius= \t\t" << radius << "\n";
    cout << classname() << " square= \t\t" << square() << "\n";
    cout << classname() << " perimeter= \t" << perimeter() << "\n";
    cout << classname() << " mass(gold)= \t\t" << mass() << " grams\n";

    cout << "\n" << classname() << " size= \t\t" << size() << " bytes\n";
};

void Circle::initFromDialog(vector<string> args) {
    x = atof(args[1].c_str());
    y = atof(args[2].c_str());
    radius = atoi(args[3].c_str());
};

double Circle::mass() {
    return square() * height * DENSITY;
};

Vector2D Circle::position() {
    return Vector2D();
};

bool Circle::operator==(const Circle &obj) const {
    const Circle *o = dynamic_cast<const Circle *>(&obj);
    if (o == nullptr)
        return false;
    else
        return (radius == o->radius);
};

bool Circle::operator<(const Circle &obj) const {
    const Circle *o = dynamic_cast<const Circle *>(&obj);
    if (o == nullptr)
        return false;
    else
        return (radius < o->radius);
};