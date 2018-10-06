#include "queue.h"

int main()
{
	SeqQueue<int> Q(10);
	Q.EnQueue(2);
	Q.EnQueue(7);
	Q.EnQueue(4);
	Q.EnQueue(3);
	Q.EnQueue(9);
	Q.show();
	cout<<"-----------"<<endl;
	int x;
	Q.DeQueue(x);
	Q.DeQueue(x);
	Q.DeQueue(x);
	Q.show();
	cout<<"-----------"<<endl;
	Q.getFront(x);
	cout<<x<<endl;
	
	return 0;
}