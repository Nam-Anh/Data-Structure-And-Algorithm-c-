#ifndef SSL_NODE_H
#define SSL_NODE_H

/*----------------------- Singly Linked List Object --------------------------*/
//                  This List is used to store object of one list
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Node {
private:
    T info;
    Node* next;
protected:
public:
    /*--------------------------- Constructor --------------------------------*/
    Node();
    Node(T i, Node* next_node);
    /*------------------------- Guard functions ------------------------------*/
    /*---------------------------- Getter ------------------------------------*/
    T get_info();
    Node*  get_next();
    /*---------------------------- Setter ------------------------------------*/
    void set_info(T new_info);
    void set_next(Node* new_node);
    /*---------------------- Overload functions ------------------------------*/
    friend ostream& operator<< (ostream& out, const Node<T>& node);
    friend istream& operator>> (istream& in, const Node<T>& node);
};
#include "CPP/SSL_Node.tpp"
#endif /* SSL_NODE_H */

