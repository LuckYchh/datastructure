#include "UFset.h"

int main()
{
	UFSets S(10);
	S.Union(0,6);
	S.Union(0,7);
	S.Union(0,8);
	S.Union(1,4);
	S.Union(1,9);
	S.Union(2,3);
	S.Union(2,5);

	int x=0;
	x=S.Find(8);
	cout<<x<<endl;
	x=S.Find(9);
	cout<<x<<endl;
	x=S.Find(3);
	cout<<x<<endl;

	return 0;
}