#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack{
private:
    int top;	      //栈顶指针
    T *data;	  //栈元素数组
    int maxSize;	  //栈最大容量
public:
    Stack (int sz = 10); //构造函数    
    ~Stack ( ) { delete [ ] data; }
    void Push (T x);   //进栈    
    void Pop (T& x);   //出栈
    void GetTop (T& x); //取栈顶
    void show();
    void MakeEmpty ( ) { top = -1; } //置空栈
    int IsEmpty ( ) const { return top == -1; } 
    int IsFull ( ) const 
    { return top == maxSize-1; }	
};

template <class T>
Stack<T>::Stack(int sz){
    data = new T(sz);
    if(data == NULL) return;
    maxSize = sz;
    top = -1;
}

//若栈不满, 则将元素x插入该栈栈顶
template <class T>
void Stack<T>::Push(T x) {   
    if(IsFull() == true){
        cout<<"栈满"<<endl;
        return;
    }
    data[++top] = x; //栈顶指针先加1, 再进栈
} 

//函数退出栈顶元素并返回栈顶元素的值给x
template <class T>
void Stack<T>::Pop(T& x) {
    if(IsEmpty() == true){
        cout<<"栈空"<<endl;
        return;
    }
    x = data[top--]; //栈顶指针退1
}    

//若栈不空则函数返回该栈栈顶元素给x
template <class T>
void Stack<T>::GetTop(T& x) {
    if (IsEmpty() == true) return;
    x = data[top];
}

template <class T>
void Stack<T>::show()
{
    if (IsEmpty() == true) return;
    for(int i=0;i<=top;i++)
        cout<<data[i]<<endl;
}


#endif