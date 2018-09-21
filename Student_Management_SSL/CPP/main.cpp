#include <iostream>
#include <fstream>
#include "../Header/Control_list.h"
#include "../Header/Singly_Linked_List.h"
#include "../Header/Class.h"
#include "../Header/Student.h"

using namespace std;
/*-------------------------- Prototypes --------------------------------------*/
/*Insert one new node to all passed-in lists. Here are: Student_list and Class_List*/
void Control_insert_node(Node<Student>& stu, Control_list<Student>& stu_array,
        Control_list<Student>& class_array);

/*Insert one new Student_List to all passed-in lists. Here are: Student_list and Class_List*/
void Control_insert_list(SSL<Student> stu_list, Control_list<Student>& stu_array,
        Control_list<Student>& class_array);
/*Delete one node in all passed-in lists. Here are: Student_list and Class_List*/
void Control_delete_node(Node<Student>& stu, Control_list<Student>& stu_array,
        Control_list<Student>& class_array);

/*Delete one list in all passed-in lists. Here are: Student_list and Class_List*/
void Control_delete_list(SSL<Student> stu_list, Control_list<Student>& stu_array,
        Control_list<Student>& class_array);

int main(int argc, char** argv) {
    //List to contain lists of students
    Control_list<Student> stu_array;
    //List to contain lists of classes
    Control_list<Student> class_array;
    
    
    return 0;
}

/*--------------------------- Details ----------------------------------------*/
/*Insert one new node to all passed-in lists
 Here are: Student_list and Class_List*/
void Control_insert_node(Node<Student>& stu, Control_list<Student>& stu_array,
        Control_list<Student>& class_array){
    //Add gradually to each Control list
    stu_array.insert_node_by_stu_id(stu);
    class_array.insert_node_by_class_id(stu);
}

/*Insert one new Student_List to all passed-in lists
 Here are: Student_list and Class_List*/
void Control_insert_list(SSL<Student> stu_list, Control_list<Student>& stu_array,
        Control_list<Student>& class_array){
    int length = stu_list.length();
    int count = 0;
    Node<Student>* stu = stu_list.head;
    
    /*Loop through all element in the inserted list and add each node to
      Control list*/
    while(count < length){
        /*The insert function pass-by-reference -> create a normal node*/
        Node<Student> stu_clone;
        stu_clone.set_info(stu->get_info());
        stu_clone.set_next(stu->get_next());
        /*Insert node*/
        stu_array.insert_node_by_stu_id(stu_clone);
        class_array.insert_node_by_class_id(stu_clone);
        
        stu = stu->get_next();
        count++;
    }
}
/*Delete one node in all passed-in lists
 Here are: Student_list and Class_List*/
void Control_delete_node(Node<Student>& stu, Control_list<Student>& stu_array,
        Control_list<Student>& class_array){
    //Delete gradually from each Control list
    stu_array.delete_node_by_stu_id(stu);
    class_array.delete_node_by_class_id(stu);
}

/*Delete one list in all passed-in lists
 Here are: Student_list and Class_List*/
void Control_delete_list(SSL<Student> stu_list, Control_list<Student>& stu_array,
        Control_list<Student>& class_array){
    int length = stu_list.length();
    int count = 0;
    Node<Student>* stu = stu_list.head;
    
    /*Loop through all element in the inserted list and add each node to
      Control list*/
    while(count < length){
        /*The insert function pass-by-reference -> create a normal node*/
        Node<Student> stu_clone;
        stu_clone.set_info(stu->get_info());
        stu_clone.set_next(stu->get_next());
        /*Delete node*/
        stu_array.delete_node_by_stu_id(stu_clone);
        class_array.delete_node_by_class_id(stu_clone);
        
        stu = stu->get_next();
        count++;
    }
}

