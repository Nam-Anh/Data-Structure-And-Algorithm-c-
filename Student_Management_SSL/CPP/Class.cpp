#include "../Header/Class.h"

/*------------------------- Constructor ----------------------------------*/
Class::Class(){
    
}
Class::Class(int id){
    this->class_id = id;
}

/*Setter*/
void Class::set_class_id(int id) {
    this->class_id = id;
}

/*Getter*/
int Class::get_class_id() {
    return this->class_id;
}