#include "linklist.h"

int main()
{
	List L;
	int a;
	L.inputFront(2);
	L.inputFront(3);
	L.inputFront(6);
	L.inputFront(9);
	L.inputFront(1);
	L.show();
	cout<<"--------------"<<endl;
	L.Insert(4,10);
	L.show();
	cout<<"--------------"<<endl;
	L.Remove(2,a);
	cout<<"a:"<<a<<endl;
	L.show();
	cout<<"--------------"<<endl;
	LinkNode *node = L.Search(9);
	cout<<node->data<<endl;

	return 0;
}