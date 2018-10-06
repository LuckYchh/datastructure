#include "stack.h"

Stack::Stack(int sz){
	data = new int(sz);
	if(data == NULL) return;
	maxSize = sz;
	top = -1;
}

//若栈不满, 则将元素x插入该栈栈顶
void Stack::Push(int x) {   
	if(IsFull() == true){
		cout<<"栈满"<<endl;
		return;
	}
	data[++top] = x; //栈顶指针先加1, 再进栈
} 

//函数退出栈顶元素并返回栈顶元素的值给x
void Stack::Pop(int& x) {
	if(IsEmpty() == true){
		cout<<"栈空"<<endl;
		return;
	}
	x = data[top--]; //栈顶指针退1
}	 

//若栈不空则函数返回该栈栈顶元素给x
void Stack::GetTop(int& x) {
	if (IsEmpty() == true) return;
	x = data[top];
}

void Stack::show()
{
	if (IsEmpty() == true) return;
	for(int i=0;i<=top;i++)
		cout<<data[i]<<endl;
}
