//
// Created by sonic on 04.05.19.
//

#ifndef LAB5_PHYSOBJECT_H
#define LAB5_PHYSOBJECT_H

#include "Vector2D.h"

template<class T>
class PhysObject {
public:
    // Масса, кг.
    virtual double mass() = 0;

    // Координаты центра масс, м.
    virtual Vector2D position() = 0;

    // Сравнение по массе.
    virtual bool operator==(const T &ob) const = 0;

    // Сравнение по массе.
    virtual bool operator<(const T &ob) const = 0;
};


#endif //LAB5_PHYSOBJECT_H
