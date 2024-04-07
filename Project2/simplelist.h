#include <string.h>

template <typename T> class SimpleList {

    public
        SimpleList(string name){head = nullptr; tail = nullptr; size = 0; list_name = name;}
        string list_name;

        virtual void push(T d) = 0;
        virtual T pop() = 0;
        int get_size() const { return this->size; }

    private:
        string name;
        struct Node {   
            T data;
            Node *next;

            Node(const T &d, Node *n = nullptr ) {
    	        data = d;
    	        next = n; 
            }
    };
    
    protected:
        int insert_front(T d); 
        int insert_end(T d); 
        T rm_front(); 
};

//insert_front adds an element to the front of a list
template <typename T> int SimpleList<T>::insert_front(T d) {
      //creates new node with data d and sets the next node equal to the head
    Node *new_node = new Node(d);
    new_node->next = head;

  //if there's an element in the list it sets the head to the new node
  //otherwise if the list is empty it sets the head and the tail to the new node
    if (head == nullptr){
        
        head = new_node;
        tail = new_node;
    }
    else{
        head = new_node;
    }
    size++;
    return 0;
}

//insert_end adds an element to the end of a list
template <typename T> int SimpleList<T>::insert_end(T d) {

    //creates new node with data d and sets the next node to be null
    Node *new_node = new Node(d);
    new_node->next = nullptr;

    //if there's an element in the list it sets the current tail's next node to the new node
    //otherwise if the list is empty it sets the head and the tail to the new node
    if (tail == nullptr){
        
        head = new_node; 
        tail = new_node;
    }
    else{
        tail->next = new_node
        tail = new_node;
    }
    size++;
    return 0; 
}
template <typename T> T SimpleList<T>::rm_front() {

    Node *tmp = head;
    T data = tmp->data;

    //If the list has more than one node, move the head to the next node
    if (head->next != nullptr){
        head = head->next;
    } 
    else{
        //If removing the head node leaves the list empty, set both head and tail to nullptr
        head = nullptr;
        tail = nullptr;
    }
    size--;
    
    //frees the current head
    delete tmp;

    //returns the popped data value
    return data;
}

//Stack class that inherits the SimpleList class
template <typename T> class Stack : public SimpleList<T> {
    public:
        Stack(string name) : SimpleList<T>(name) {} 
	    void push (T d) {return this-> insert_front(d);}
	    T pop () {return this-> rm_front();}
};

//Queue class that inherits the SimpleList class
template <typename T> class Queue : public SimpleList<T> {
    public:
        Queue(string name) : SimpleList<T>(name) {}
        void push (T d) {return this-> insert_end(d);}
        T pop () {return this-> rm_front();}
};


