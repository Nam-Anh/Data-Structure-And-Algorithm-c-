#ifndef CONTROL_LIST_H
#define CONTROL_LIST_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include "SSL_Node.h"
#include "Singly_Linked_List.h"
#include "Student.h"

using namespace std;

template<class T>
class Control_list {
public:
    /*------------------------------- Properties -----------------------------*/
    int id;
    string name;
    vector<SSL<T> > lists;
    /*-------------------------------- Functions -----------------------------*/
    /*Constructor*/
    Control_list();
    Control_list(int id, string name, vector<SSL<T> > lists);
    
    //Check if list is empty   
    bool is_empty();
    //Check list length
    int length();   
    //Insert new node to the vector container by student id
    void insert_node_by_stu_id(Node<T>& node);
    
    //Insert new node to the vector container by class id
    void insert_node_by_class_id(Node<T>& node);
    
    //Delete one node from the container list by student id
    void delete_node_by_stu_id(Node<T> node);
    
    //Delete one node from the container list by class id
    void delete_node_by_class_id(Node<T> node);
    
    //Show data in the list
    void show();
};

#include "../CPP/Control_list.tpp"
#endif /* CONTROL_LIST_H */

