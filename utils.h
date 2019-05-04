//
// Created by sonic on 04.05.19.
//

#ifndef LAB5_UTILS_H
#define LAB5_UTILS_H
#include <string>
#include <vector>
#include <sstream>
#include "Rectangle.h"
#include "Circle.h"

namespace utils {
    template<typename Out>
    void split(const std::string &s, char delim, Out result) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            *(result++) = item;
        }
    }

    inline std::vector<std::string> split(std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, std::back_inserter(elems));
        return elems;
    }

    bool comparator_circle(Circle &lhs, Circle &rhs) {
        return (lhs.mass() < rhs.mass());
    }


    bool comparator_rectangle(Rectangle &lhs, Rectangle &rhs) {
        return (lhs.mass() < rhs.mass());
    }
}

#endif //LAB5_UTILS_H
