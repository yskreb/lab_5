//
// Created by sonic on 04.05.19.
//

#ifndef LAB5_RECTANGLE_H
#define LAB5_RECTANGLE_H


#include "Vector2D.h"
#include "GeometryFigure.h"
#include "BaseObject.h"
#include "Printable.h"
#include "PhysObject.h"
#include <vector>
#include <string>

using namespace std;

class Rectangle: PhysObject<Rectangle>, GeometryFigure, BaseObject, Printable, Vector2D  {
private:
    const double DENSITY = 21.5;
    const char *name = "Rectangle";
    const int height = 1;

protected:
    int a, b;
public:
    Rectangle() {};

    Rectangle(int x, int y, int a, int b) : x(x), y(y), a(a), b(b) {};

    ~Rectangle() {};

    Rectangle &operator=(const Rectangle &v) {
        a = v.a;
        b = v.b;
        return *this;
    }

    double x, y;


    double square();

    double perimeter();

    unsigned int size();

    const char *classname();

    void draw();

    void initFromDialog(vector<string> args);

    double mass();

    Vector2D position();

    bool operator==(const Rectangle &obj) const;

    bool operator<(const Rectangle &obj) const;
};


#endif //LAB5_RECTANGLE_H
