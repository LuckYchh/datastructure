#include "seqlist.h"

int main()
{
	SeqList L(10);
	L.Insert(1,9);
	L.Insert(2,10);
	L.Insert(3,7);
	L.Insert(4,1);
	L.Insert(5,8);
	L.Insert(6,-2);
	L.Insert(7,-5);
	L.Insert(8,-7);
	L.show();
	cout<<"---------------"<<endl;
	int c = L.Search(7);
	cout<<c<<endl;
	int a;
	L.Remove(4,a);
	cout<<a<<endl;
	cout<<"---------------"<<endl;	
	L.show();

	return 0;
}