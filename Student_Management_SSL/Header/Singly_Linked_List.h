#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
/*----------------------- Singly Linked List ---------------------------------*/
//                  This List is used to store object
#include <iostream>
#include <fstream>
#include "SSL_Node.h"
using namespace std; 
 
template<class T>
class SSL {
private:
protected:
public:
    int id;
    Node<T>* head;
    Node<T>* tail;
    /*------------------------- Constructor ----------------------------------*/
    SSL();
    SSL(int id, Node<T> head_node, Node<T> tail_node);
    /*----------------------- DeConstructor ----------------------------------*/
    ~SSL();
    /*--------------------- Modification Functions ---------------------------*/
    int isEmpty();
    int length();
    
    void insertNode(int pos, Node<T> node);
    void insertToHead(Node<T> node);
    void insertToTail(Node<T> node);
    
    void deleteNode(Node<T> node);
    void deletePos(int pos);
    int deleteFromHead();
    int deleteFromTail();
    
    bool isInList(Node<T> node) const;
    void show();
};
#include "../CPP/Singly_Linked_List.tpp"
#endif /* SINGLY_LINKED_LIST_H */

