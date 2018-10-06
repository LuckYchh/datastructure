#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <iostream>
using namespace std;

template <class E>
struct StackNode {                    
public: 
    E data;			          
    StackNode<E> *link;           
    StackNode(E d = 0, StackNode<E> *next = NULL)
         : data(d), link(next) { }
};  

template <class E>
class LinkedStack{    
public:
	StackNode<E> *top;		            
	
    LinkedStack() : top(NULL) {}	   
	~LinkedStack(){ makeEmpty(); };  
	void Push(E x);		             	   
	bool Pop(E& x);
	bool getTop(E& x) const;		 	
    bool IsEmpty() const { return top == NULL; }
    void makeEmpty();
    void show();		
};


template <class E>
void LinkedStack<E>::makeEmpty() {	
    StackNode<E> *p;
	while (top != NULL)	
        { p = top;  top = top->link;  delete p; }
}

template <class E>
void LinkedStack<E>::Push(E x) {
	top = new StackNode<E> (x, top);	
    if(top==NULL) return;
}

template <class E>
bool LinkedStack<E>::Pop(E& x) {
    if (IsEmpty() == true) return false;   
  	StackNode<E> *p = top;		
	top = top->link;			
	x = p->data;   delete p;	
   	return true;	
}

template <class E>
bool LinkedStack<E>::getTop(E& x) const {	
	if (IsEmpty() == true) return false;  
	x = top->data;                       
    return true;
}

template <class E>
void LinkedStack<E>::show(){
	if(IsEmpty()==true) return ;
	while(top!=NULL){
		cout<<top->data<<endl;
		top=top->link;
	}
}

#endif