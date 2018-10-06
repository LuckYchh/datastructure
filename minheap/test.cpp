#include "minheap.h"

int main()
{
	int a[10]={34,24,5,17,13,29,67,1,7,41};
	MinHeap<int> heap(a,10);
	int x;
	heap.Remove(x);
	heap.Remove(x);
	heap.Remove(x);
	heap.show();

	MinHeap<int> heap1(10);
	heap1.Insert(34);
	heap1.Insert(56);
	heap1.Insert(78);
	heap1.Insert(23);
	heap1.Insert(5);
	heap1.Insert(12);
	heap1.Insert(4);
	heap1.Insert(45);

	heap1.Remove(x);
	heap1.Remove(x);
	heap1.show();

	return 0;
}