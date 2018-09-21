#include <vector>

#include "../Header/Control_list.h"

/*------------------------------- Constructor --------------------------------*/
template<class T>
Control_list<T>::Control_list() {
}

template<class T>
Control_list<T>::Control_list(int id, string name, vector<SSL<T> > lists) {
    this->id = id;
    this->name = name;
    this->lists = lists;
}

/*Check if list is empty*/
template<class T>
bool Control_list<T>::is_empty() {
    return (this->lists.size() > 0);
}

/*Check list length*/
template<class T>
int Control_list<T>::length() {
    return this->lists.size();
}

/*Insert Student node to the container according to Student id*/
template<class T>
void Control_list<T>::insert_node_by_stu_id(Node<T>& node) {
    /*Check if the list with that id is existing*/
    bool existed = false;
    int index_existed = -1;
    Student stu = node.get_info();
    //Loop through all element to find the existing index
    for (int i = 0; i < this->lists.size(); i++) {//check by student id
        if (stu.get_student_id() == this->lists[i].id) {
            existed = true;
            index_existed = i;
            break;
        }
    }

    /*Case1: Existed*/
    if (existed) {
        this->lists[index_existed].insertToTail(node);
        return;
    }

    /*Case2: Non Existed*/
    if (!existed) {
        SSL<Student> l;
        l.id = node.get_info().get_student_id();
        l.head = &node;
        l.tail = &node;
        //Push the list to vector container <-> insert the node the the Control list
        this->lists.push_back(l);
        return;
    }
}

/*Insert Student node to the container according to Class id*/
template<class T>
void Control_list<T>::insert_node_by_class_id(Node<T>& node) {
    /*Check if the list with that id is existing*/
    bool existed = false;
    int index_existed = -1;
    Student stu = node.get_info();
    //Loop through all element to find the existing index
    for (int i = 0; i < this->lists.size(); i++) {
        if (stu.get_class_id() == this->lists[i].id) {//check by class id
            existed = true;
            index_existed = i;
            break;
        }
    }

    /*Case1: Existed*/
    if (existed) {
        this->lists[index_existed].insertToTail(node);
        return;
    }

    /*Case2: Non Existed*/
    if (!existed) {
        SSL<Student> l;
        l.id = node.get_info().get_student_id();
        l.head = &node;
        l.tail = &node;
        //Push the list to vector container <-> insert the node the the Control list
        this->lists.push_back(l);
        return;
    }
}

/*Delete one list from the container list by Student id*/
template<class T>
void Control_list<T>::delete_node_by_stu_id(Node<T> node) {
    /*Check if the list with that id is existing*/
    bool existed = false;
    int index_existed = -1;
    Student stu = node.get_info();
    //Loop through all element to find the existing index
    for (int i = 0; i < this->lists.size(); i++) {
        if (stu.get_student_id() == this->lists[i].id) {//check by student id
            existed = true;
            index_existed = i;
            break;
        }
    }
    /*Case1: The node need deleting is existed*/
    if(existed){
        this->lists[index_existed].deleteNode(node);
        return;
    }else{
        /*Case2: The node need deleting is not existed*/
        cout << "The node need deleting is not found\n";
        return;
    }
}

/*Delete one list from the container list by Class id*/
template<class T>
void Control_list<T>::delete_node_by_class_id(Node<T> node) {
    /*Check if the list with that id is existing*/
    bool existed = false;
    int index_existed = -1;
    Student stu = node.get_info();
    //Loop through all element to find the existing index
    for (int i = 0; i < this->lists.size(); i++) {
        if (stu.get_class_id() == this->lists[i].id) {//check by class id
            existed = true;
            index_existed = i;
            break;
        }
    }
    /*Case1: The node need deleting is existed*/
    if(existed){
        this->lists[index_existed].deleteNode(node);
        return;
    }else{
        /*Case2: The node need deleting is not existed*/
        cout << "The node need deleting is not found\n";
        return;
    }
}
//Show data in the list
template<class T>
void Control_list<T>::show(){
    for(int i = 0; i < this->lists.size(); i++){
        SSL<Student> l = lists[i];
        l.show();
    }
}