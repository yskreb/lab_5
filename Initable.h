//
// Created by sonic on 04.05.19.
//

#ifndef LAB5_INITABLE_H
#define LAB5_INITABLE_H

#include <vector>
#include <string>

class Initable {
    virtual void initFromDialog(std::vector<std::string> args) = 0;
};


#endif //LAB5_INITABLE_H
