#include "linklist.h"

void List::inputFront (int val) {
	LinkNode *newNode = new LinkNode;
	if(newNode==NULL) return;
    newNode = new LinkNode(val);
    newNode->link = first->link;	  //插在表前端
    first->link = newNode;
}; 


bool List::Insert (int i, int x) {
//将新元素 x 插入在链表中第 i 个结点之后。
    LinkNode *current = Locate(i);
	if (current == NULL) return false;	 //无插入位置
	LinkNode *newNode = new LinkNode(x); //创建新结点
    newNode->link = current->link;       //链入
    current->link = newNode;			
	return true; 				
};


bool List::Remove (int i, int& x ) {
//删除链表第i个元素, 通过引用参数x返回元素值
    LinkNode *current = Locate(i-1);
	if ( current == NULL || current->link == NULL)   
         return false; 	//删除不成功 	
    LinkNode *del = current->link; 
    current->link = del->link;
	x = del->data;	
	delete del;	
    return true;
};

LinkNode *List::Search(int x) {
//在表中搜索含数据x的结点, 搜索成功时函数返
//该结点地址; 否则返回NULL。
	 LinkNode *current = first->link;
 	 while ( current != NULL && current->data != x ) 		
		current = current->link;  	//沿着链找含x结点
 	 return current;
};

LinkNode *List::Locate(int i)
{
	int k=0;
	if(i<0) return NULL;
	LinkNode *current = first->link;
	while( current != NULL && k<i )
	{
		current=current->link;
		k++;
	}
	return current;
}

void List::show()
{
	LinkNode *current = first->link;
	while(current!=NULL)
	{
		cout << current->data <<endl;
		current=current->link;
	}
}