#include "stack.h"

int main()
{
	Stack<int> seqstack(10);
	seqstack.Push(2);
	seqstack.Push(4);
	seqstack.Push(1);
	seqstack.Push(9);
	seqstack.Push(7);
	seqstack.show();
	cout<<"--------------"<<endl;
	int x;
	seqstack.Pop(x);
	seqstack.Pop(x);
	seqstack.Pop(x);
	seqstack.Pop(x);
	seqstack.show();
	cout<<"--------------"<<endl;
	seqstack.GetTop(x);
	cout<<"x:"<<x<<endl;
	return 0;
}