#include "queue.h"

SeqQueue::SeqQueue(int sz){
    data = new E[maxSize];		
	front=rear=0;
	maxSize=sz;    
}

//若队列不满, 则将x插入到该队列队尾, 否则返回      
bool SeqQueue::EnQueue(E x){           
	if(IsFull() == true) return false;   
    data[rear] = x;                    //先存入
    rear = (rear+1) % maxSize;       //尾指针加一
    return true;			
}

//若队列不空则函数退队头元素并返回其值
bool SeqQueue::DeQueue(E& x){ 
    if(IsEmpty() == true) return false;    
	x = data[front];                  //先取队头
    front = (front+1) % maxSize;   //再队头指针加一
    return true;
}

//若队列不空则函数返回该队列队头元素的值
bool SeqQueue::getFront(E& x){
    if(IsEmpty() == true) return false;    //队列空
	x = data[front];		    //返回队头元素
	return true;
}

void SeqQueue::show(){
	for(int i = front;i != rear;i = (i+1) % maxSize)
		cout << i << " " << data[i] << endl;
}