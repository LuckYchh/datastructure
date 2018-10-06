#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <iostream>
using namespace std;

template <class T>
struct QueueNode {                   
public: 
    T data;			          
    QueueNode<T> *link;          
public:
    QueueNode(T d = 0, QueueNode<T>
      *next = NULL) : data(d), link(next) { }
};  

template <class T>
class LinkedQueue {	
public: 
    QueueNode<T> *front, *rear;   
public:
    LinkedQueue();
    ~LinkedQueue(){ MakeEmpty();};					
    bool EnQueue(T x);
    bool DeQueue(T& x);			
    bool GetFront(T& x);			
    void MakeEmpty();           
    bool IsEmpty() const { return front == NULL; }
};

template <class T>
LinkedQueue<T>::LinkedQueue(){
    front=rear=new QueueNode<T>;
    front=NULL;
    rear=NULL;
}

template <class T>
void LinkedQueue<T>::MakeEmpty() {    
    QueueNode<T> *p;
    while (front != NULL) {              
        p = front;  front = front->link;  delete p;
    }
}

template <class T> 
bool LinkedQueue<T>::EnQueue(T x) {
    if (front == NULL)  {              
	    front = rear = new QueueNode<T> (x);
        if (front == NULL) return false; 
	}	
    else {                                      
        rear->link = new QueueNode<T> (x);
        if (rear->link == NULL) return false; 
        rear = rear->link;
    }
    return true;
}

template <class T>
bool LinkedQueue<T>::DeQueue(T& x) {
    if (IsEmpty() == true) return false;        
    QueueNode<T> *p = front;		
    x = front->data;  front = front->link;   
    delete p;   return true;				
}

template <class T> 
bool LinkedQueue<T>::GetFront(T& x) {
    if (IsEmpty() == true) return false; 	
    x = front->data;  return true;
}

#endif



