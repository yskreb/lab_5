//
// Created by sonic on 04.05.19.
//

#include "Rectangle.h"
#include <iostream>

using namespace std;

double Rectangle::square() {
    return a * b;
};

double Rectangle::perimeter() {
    return 2 * a + 2 * b;
};

const char *Rectangle::classname() {
    return name;
};

unsigned int Rectangle::size() {
    return sizeof(Rectangle);
};

void Rectangle::draw() {
    cout << "Classname =\t\t" << classname() << "\n";
    cout << "c= \t\t(" << x << ", " << y << ")\n";
    cout << "s= \t\t" << square() << "\n";
    cout << "p= \t\t" << perimeter() << "\n";
    cout << "M= \t\t" << mass() << " grams\n";

    cout << "\n" << classname() << " size= \t\t" << size() << " bytes\n";
};

void Rectangle::initFromDialog(vector<string> args) {
    x = atof(args[1].c_str());
    y = atof(args[2].c_str());

    a = atoi(args[3].c_str());
    b = atoi(args[4].c_str());

};

double Rectangle::mass() {
    return square() * height * DENSITY;
};

Vector2D Rectangle::position() {
    return Vector2D();
};

bool Rectangle::operator==(const Rectangle &obj) const {
    const Rectangle *o = dynamic_cast<const Rectangle *>(&obj);
    if (o == nullptr)
        return false;
    else
        return (a + b == o->a + b);
};

bool Rectangle::operator<(const Rectangle &obj) const {
    const Rectangle *o = dynamic_cast<const Rectangle *>(&obj);
    return (a + b < o->a + b);
};