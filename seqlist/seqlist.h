/*
*
**/

#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>
using namespace std;

class SeqList{
protected:
	int *data;   //存放数组
	int maxSize; //最大可容纳表项的项数
	int n;       //当前已存表项数
public:
	SeqList(int sz);     //构造函数
	~SeqList() {delete[ ] data;}	   //析构函数
	void input();
	int Search(int x) const;	//搜索x在表中位置，返回表项序号
	bool Insert(int i, int x);  //插入
	bool Remove(int i, int& x); //删除
	void show();
};
#endif