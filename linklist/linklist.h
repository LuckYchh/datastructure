#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include <stdio.h>
using namespace std;

struct LinkNode {	 	//链表结点类的定义
	int data;			//数据域
	LinkNode *link;     //链指针域
    LinkNode() { link = NULL; }     //构造函数
	LinkNode(int item, LinkNode *ptr = NULL)
    { data = item;  link = ptr; }     //构造函数
};

class List{
protected:
	LinkNode *first;	 //表头指针
public:
	List() { first = new LinkNode; }  //构造函数
	List(int x) { first = new LinkNode(x); }
	~List(){ }   				//析构函数
	void inputFront (int val);
	LinkNode *Search(int x);	//搜索含x元素
	LinkNode *Locate(int i);    //返回第i个元素地址
	bool Insert (int i, int x); //在第i元素后插入
	bool Remove(int i, int& x);	//删除第i个元素
    bool IsEmpty() const 		//判表空否
    { return first->link == NULL ? true : false; }
    void show();
};

#endif