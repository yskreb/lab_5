//
// Created by sonic on 04.05.19.
//

#ifndef LAB5_BASEOBJECT_H
#define LAB5_BASEOBJECT_H


class BaseObject {
public:
    virtual const char *classname() = 0;

    virtual unsigned int size() = 0;
};


#endif //LAB5_BASEOBJECT_H
