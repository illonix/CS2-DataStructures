#include <iostream>

#ifndef OBJ_CONSTRUCTION_HPP_
#define OBJ_CONSTRUCTION_HPP_

class Object {
public:
     Object();  //Default ctor
    ~Object();  //dtor
     Object(const Object&); //copy ctor
     Object operator=(const Object&); //Assignment
     
private:

};




#endif