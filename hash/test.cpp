#include "hash.h"

int main()
{
	HashTable<int,int> H(11,12);
	H.Insert(37);
	H.Insert(25);
	H.Insert(14);
	H.Insert(36);
	H.Insert(49);
	H.Insert(68);
	H.Insert(57);
	H.Insert(11);
	int pos;
	H.Search(25,pos);
	cout<<pos<<endl;
	return 0;
}