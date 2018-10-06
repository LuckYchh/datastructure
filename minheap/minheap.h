#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
using namespace std;

template <class T>
class MinHeap{
public: 
    MinHeap (int sz = 10);			//构造函数
    MinHeap (T arr[], int n);		//构造函数
    ~MinHeap() { delete [ ] heap; }	//析构函数
    bool Insert (T d);		//插入
    bool Remove (T d);		//删除
	bool IsEmpty()const		//判堆空否
       { return currentSize == 0; }
    bool IsFull()const		//判堆满否
 	   { return currentSize == maxHeapSize; }	
	void MakeEmpty () { currentSize = 0; }	//置空堆
	void show();
	void siftDown (int start, int m);	//调整算法
    void siftUp (int start);		    //调整算法
protected: 
    T *heap;			//最小堆元素存储数组
    int currentSize;	//最小堆当前元素个数
    int maxHeapSize;	//最小堆最大容量
};

template <class T>
MinHeap<T>::MinHeap (int sz) {
    maxHeapSize = (10 < sz) ? sz : 10;
    heap = new T[maxHeapSize];  	
    if (heap == NULL) {
        cerr << "堆存储分配失败！" << endl; return;
    }
    for(int i=0;i<maxHeapSize;i++)
    	heap[i] = 0;
    currentSize = 0;				
}

template <class T>
MinHeap<T>::MinHeap (T arr[], int n) {
    maxHeapSize = (10 < n) ? n : 10;
    heap = new T[maxHeapSize]; 
	if (heap == NULL) {
        cerr << "堆存储分配失败！" << endl;  return;
    }
    for (int i = 0; i < n; i++) heap[i] = arr[i];
    currentSize = n;	       
	int currentPos = (currentSize-2)/2;	
	while (currentPos >= 0) {	    	
        siftDown (currentPos, currentSize-1);
        currentPos--;
    }					
}

template <class T>
void MinHeap<T>::siftDown (int start, int m ) {
	int i = start,   j = 2*i+1; 
	T temp = heap[i]; 			
	while (j <= m) {			
		if ( j < m && heap[j] > heap[j+1] ) j++;
		if ( temp <= heap[j] ) break;	
		else { 
			heap[i] = heap[j];  i = j; j = 2*j+1; 
		}
	 }
	 heap[i] = temp;	      
}

template <class T>
bool MinHeap<T>::Insert (T x )  {
    if ( currentSize == maxHeapSize ) 
        { cerr << "Heap Full" << endl;  return false; }
	heap[currentSize] = x;  		
	siftUp (currentSize);			
	currentSize++;				    
	return true;
}

template <class T>
void MinHeap<T>::siftUp (int start) {
	int j = start,  i = (j-1)/2;   
	T temp = heap[j];
	while (j > 0) {	
	    if (heap[i] <= temp) break;	
		else {                      
			heap[j] = heap[i];  j = i;  i = (i-1)/2; 
		}
	}
	heap[j] = temp;				
}

template <class T>
bool MinHeap<T>::Remove (T x) {
	if ( !currentSize ) {		
	    cout << "Heap empty" << endl;  return false;
    }
	x = heap[0];  
	heap[0] = heap[currentSize-1];
	currentSize--;
	siftDown(0, currentSize-1); 
	return true;				
}

template <class T>
void MinHeap<T>::show(){
	if(heap!=NULL){
		for(int i=0;i<currentSize;i++)
			cout<<heap[i]<<" ";
		cout<<endl;
	}
}


#endif