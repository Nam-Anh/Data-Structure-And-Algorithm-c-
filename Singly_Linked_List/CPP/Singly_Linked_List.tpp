#include "../Singly_Linked_List.h"

/*------------------------- Constructor ----------------------------------*/
template<class T>
SSL<T>::SSL() {
    this->head = NULL;
    this->tail = NULL;
}

template<class T>
SSL<T>::SSL(Node<T> head_node, Node<T> tail_node) {
    this->head = head_node;
    this->tail = tail_node;
}

/*----------------------- DeConstructor ----------------------------------*/
template<class T>
SSL<T>::~SSL() {
    for (Node<T>* p; !isEmpty();) {
        p = this->head;
        this->head = NULL;
        this->head = p;
    }
}

/*--------------------- Modification Functions ---------------------------*/
template<class T>
int SSL<T>::isEmpty() {
    return (this->head == NULL);
}

template<class T>
int SSL<T>::length() {
    int count = 0;
    Node<T>* current_n = this->head;
    while (current_n != NULL) {
        current_n = current_n->get_next();
        count++;
    }
    return count;
}

template<class T>
void SSL<T>::insertNode(int pos, Node<T> node) {
    /*------------------ Input position is negative --------------------------*/
    if (pos < 0) {
        cout << "Input position must be positive number\n";
        return;
    }
    /*--------------- Input position is in right format ----------------------*/
    /*---------------------- Create new node ---------------------------------*/
    Node<T>* n = new Node<T>;
    n->set_info(node.get_info());
    n->set_next(node.get_next());
    //Case 1: the list is empty
    if (isEmpty()) {
        this->head = n;
        this->tail = n;
        return;
    }
    //Case 2: position to insert is 0<=> head of list
    if (pos == 0) {
        Node<T> t;
        t.set_info(n->get_info());
        t.set_next(n->get_next());
        insertToHead(t);
        cout << "Insert sucessfully to the head of list\n";
        return;
    }
    //Case 3: postion to insert is the end of list<=> tail of list
    if (pos == length()) {
        Node<T> t;
        t.set_info(n->get_info());
        t.set_next(n->get_next());
        insertToTail(t);
        cout << "Insert sucessfully to the tail of list\n";
        return;
    }
    //Case 4: postion to insert if >= 1, any other nodes
    int count = 0;
    bool found = false;

    Node<T>* previous_n = NULL;
    Node<T>* current_n = this->head;
    //Loop for all element in the list to find the suitable position
    while (current_n != NULL) {
        if (count == pos) {
            //Find the true position
            found = true;
            break;
        }
        previous_n = current_n;
        current_n = current_n->get_next();
        count++;
    }
    //If find the suitable position 
    if (found) {
        previous_n->set_next(n);
        n->set_next(current_n);
        //Inform successful insertion 
        cout << "Successful Insertion\n";
    } else {
        //Inform not find any suitable position 
        cout << "There is no suitable pos\n";
        return;
    }
}

template<class T>
void SSL<T>::insertToHead(Node<T> node) {
    Node<T>* t = new Node<T>;
    t->set_info(node.get_info());
    t->set_next(node.get_next());

    if (isEmpty()) {
        //There is no node in the list
        this->head = t;
        this->tail = t;
    } else {
        //There is sth in the list
        t->set_next(this->head);
        this->head = t;
    }
}

template<class T>
void SSL<T>::insertToTail(Node<T> node) {
    Node<T>* t = new Node<T>;
    t->set_info(node.get_info());
    t->set_next(node.get_next());

    if (isEmpty()) {
        //There is no node in the list
        this->head = t;
        this->tail = t;
    } else {
        //There is sth in the list
        this->tail->set_next(t);
        this->tail = this->tail->get_next();
    }
}

template<class T>
void SSL<T>::deleteNode(Node<T> node) {
    //Check if the list is empty or not
    if (isEmpty()) {
        cout << "The List is empty, there is nothing to delete\n";
        return;
    }
    //If the List has >= 1 element, loop through all elements 
    //to find the wanted one
    Node<T> * current_n;
    Node<T> * previous_n;
    previous_n = NULL;
    current_n = this->head;

    bool found = false;

    while (current_n != NULL) {
        if (current_n->get_info() == node.get_info()) {
            found = true;
            break;
        }
        previous_n = current_n;
        current_n = current_n->get_next();
    }
    /*---------------------- DELETING PROCESSING -----------------------------*/
    if (found) {
        //This variable is used to check if the variable is deleted or not
        bool deleted = false;
        //Case1: The deleted node is head not tail
        if ((current_n == this->head) && (current_n != this->tail) 
                && (deleted == false)) {
            this->head = current_n->get_next();
            deleted = true;
        }
        //Case2: The deleted node is tail not head
        if ((current_n != this->head) && (current_n == this->tail)
                && (deleted == false)) {
            previous_n->set_next(NULL);
            this->tail = previous_n;
            deleted = true;
        }
        //Case3: The deleted node is not head and tail
        if ((current_n != this->head) && (current_n != this->tail)
                && (deleted == false)) {
            previous_n->set_next(current_n->get_next());
            deleted = true;
        }
        //Case4: The deleted node is head and tail
        if ((current_n == this->head) && (current_n == this->tail)
                && (deleted == false)) {
            this->head = NULL;
            this->tail = NULL;
            deleted = true;
        }
        cout << "Delete the wanted node successfully\n";
    } else {
        //Case2: Not found suitable node
        cout << "Delete the wanted node successfully\n";
    }
}

template<class T>
void SSL<T>::deletePos(int pos) {
    int count = 0;
    //Check input number
    if (pos < 0) {
        //Position must be positive num
        cout << "Position must be positive num\n";
        return;
    }
    /*------------------- INPUT NUMBER IS IN RIGHT FORMAT --------------------*/
    /*---------------------- Case 1: List is empty ---------------------------*/
    if (isEmpty()) {
        cout << "The list is empty. There is nothing to delete\n";
        return;
    }
    /*--------------------- Case 2: List is not empty ------------------------*/
    //2.1. The position to delete is 0, this means deleting list's head 
    if (pos == 0) {
        //The deleted node is head and not tail <=> list has > 1 node
        if (this->head != this->tail) {
            Node<T>* tmp = this->head->get_next();
            this->head = NULL;
            this->head = tmp;
        }//The deleted node is head and tail <=> list has = 1 node
        else if (this->head == this->tail) {
            this->head = NULL;
            this->tail = NULL;
        }
        //Inform about successful insertion
        cout << "Delete successfully the node at index: " + pos << endl;
    } else {
        /*2.2. List is not empty and The position to delete is >= 1*/
        bool found = false;
        Node<T>* current_n = this->head;
        Node<T>* previous_n;

        //Loop for all element in the list to find the suitable position
        while (current_n->get_next() != NULL) {
            previous_n = current_n;
            current_n = current_n->get_next();
            count++;
            if (count == pos) {
                //Find the true position
                found = true;
                break;
            }
        }

        if (found) {
            //Find the right position
            if (this->tail != current_n) {
                //Case: The deleted node is not list's tail
                Node<T>* tmp;
                tmp = current_n->get_next();
                previous_n->set_next(tmp);
            } else if (this->tail == current_n) {
                //Case: The deleted node is  list's tail
                this->tail = previous_n;
            }
            //Inform about successful insertion
            cout << "Delete successfully the node at index: " << pos << endl;
        } else {
            //Not find the right position
            //This can happen when the wanted position is > the number of
            //node in list
            cout << "This position is out of range\n";
        }
    }
}

template<class T>
int SSL<T>::deleteFromHead() {
    Node<T>* tmp;
    tmp = head->get_next();
    this->head = NULL;
    this->head = tmp;
    //Inform about successful insertion
    cout << "Delete successfully the head" << endl;
}

template<class T>
int SSL<T>::deleteFromTail() {
    //Loop to find the tail's previous node
    Node<T>* current_n = this->head;
    while (current_n->get_next() != this->tail) {
        current_n = current_n->get_next();
    }
    current_n->set_next(NULL);
}

template<class T>
bool SSL<T>::isInList(Node<T> p) const {
    //Loop through all element to find Node<T> p
    Node<T>* current_n = this->head;
    bool found = false;

    while (current_n != this->tail) {
        if (current_n->get_info() == p.get_info()) {
            found = true;
            break;
        }
        current_n = current_n->get_next();
    }
    return found;
}

template<class T>
void SSL<T>::show() {
    Node<T>* node;
    node = this->head;

    while (node != NULL) {
        cout << "Info:" << node->get_info() << endl;
        node = node->get_next();
    }

    cout << "End of list\n";
    return;
}


