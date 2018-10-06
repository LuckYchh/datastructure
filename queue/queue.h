#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <class E>
class SeqQueue{	   
protected:
    int rear,front;    //队尾与队头指针
    E *data;		    //队列存放数组
    int maxSize;		//队列最大容量
public: 
    SeqQueue(int sz = 10); //构造函数    
	~SeqQueue(){delete[ ] data;}  //析构函数
    bool EnQueue(E x);         //新元素进队列
	bool DeQueue(E& x);      //退出队头元素
    bool getFront(E& x);	      //取队头元素值
    void show();
    void makeEmpty(){front = rear = 0;}		
    bool IsEmpty() const { return front == rear; }	
    bool IsFull() const 
    { return ((rear+1)% maxSize == front); }	
    int getSize() const 
    { return (rear-front+maxSize) % maxSize; }	
};

template <class E> 
SeqQueue<E>::SeqQueue(int sz){
    data = new E[maxSize];		
	front=rear=0;
	maxSize=sz;    
}

//若队列不满, 则将x插入到该队列队尾, 否则返回      
template <class E>
bool SeqQueue<E>::EnQueue(E x){           
	if(IsFull() == true) return false;   
    data[rear] = x;                    //先存入
    rear = (rear+1) % maxSize;       //尾指针加一
    return true;			
}

//若队列不空则函数退队头元素并返回其值
template <class E>
bool SeqQueue<E>::DeQueue(E& x){ 
    if(IsEmpty() == true) return false;    
	x = data[front];                  //先取队头
    front = (front+1) % maxSize;   //再队头指针加一
    return true;
}

//若队列不空则函数返回该队列队头元素的值
template <class E>
bool SeqQueue<E>::getFront(E& x){
    if(IsEmpty() == true) return false;    //队列空
	x = data[front];		    //返回队头元素
	return true;
}

template <class E>
void SeqQueue<E>::show(){
	for(int i = front;i != rear;i = (i+1) % maxSize)
		cout << i << " " << data[i] << endl;
}

#endif