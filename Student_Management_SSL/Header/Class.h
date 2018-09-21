#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <fstream>

using namespace std;

class Class {
private:
    int class_id;
public:
    /*------------------------- Constructor ----------------------------------*/
    Class();
    Class(int id);
    /*-------------------- Guarding functions --------------------------------*/
    /*Setter*/
    void set_class_id(int id);

    /*Getter*/
    int get_class_id();
};

#endif /* CLASS_H */

