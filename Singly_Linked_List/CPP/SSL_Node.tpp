#include "../SSL_Node.h"

/*--------------------------- Constructor --------------------------------*/
template<class T>
Node<T>::Node(){
    set_info(NULL);
    set_next(NULL);
}

template<class T>
Node<T>::Node(T i, Node* next_node){
    set_info(i);
    set_next(next_node);
}
/*------------------------- Guard functions ------------------------------*/
/*---------------------------- Getter ------------------------------------*/
template<class T>
T Node<T>::get_info(){
    return this->info;
}

template<class T>
Node<T>* Node<T>::get_next(){
    return this->next;
}
/*---------------------------- Setter ------------------------------------*/
template<class T>
void Node<T>::set_info(T new_info){
    this->info = new_info;
}
template<class T>
void Node<T>::set_next(Node* new_node){
    this->next = new_node;
}
/*---------------------- Overload functions ------------------------------*/
template<class T>
ostream& operator<<(ostream& out, const Node<T>& node){
    cout << node.get_info() << endl;
    return out;
}
template<class T>
istream& operator>>(istream& in, const Node<T>& node){
    T obj;
    Node<T>* next_node;
    in >> obj >> next_node;
    node.set_info(obj);
    node.set_next(next_node);
    
    return in;
}
