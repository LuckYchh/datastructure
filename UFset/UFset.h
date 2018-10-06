#ifndef UFSET_H
#define UFSET_H

#include <iostream>
using namespace std;

class UFSets {
public:
    UFSets (int sz = 0);	//构造函数
	~UFSets() { delete []parent; }	//析构函数
    void Union(int Root1,int Root2);//子集合并
	void WeightedUnion(int Root1, int Root2);
    int Find (int x);				//查找x的根
	int CollapsingFind (int i);
private:
	int *parent;		  //集合元素数组(双亲表示)
    int size;			  //集合元素的数目
};

//构造函数：sz 是集合元素个数，双亲数组的范围
//为parent[0]～parent[size-1]。
UFSets::UFSets (int sz) {	
    size = sz;			     //集合元素个数
    parent = new int[size];  //创建双亲数组
    for (int i = 0; i < size; i++) 
		parent[i] = -1;	     //每个自成单元素集合
}

//函数搜索并返回包含元素x的树的根。
int UFSets::Find (int x) {
    if (parent[x] < 0) return x;   //根的parent[]值小于0  
    else return (Find (parent[x]));
}

//求两个不相交集合Root1与Root2的并
void UFSets::Union (int Root1, int Root2) {
	//将Root2连接到Root1下面
	//两个根结点所带结点数累加后给Root1，Root1称为新根。
    parent[Root1] += parent[Root2];
    parent[Root2] = Root1;
}

//按Union的加权规则改进的算法
void UFSets :: WeightedUnion (int Root1, int Root2) {
    int temp = parent[Root1] + parent[Root2];
    if (parent[Root2] < parent[Root1]) {
        parent[Root1] = Root2;     //Root2中结点数多
        parent[Root2] = temp;      //Root1指向Root2
    }
    else {  
        parent[Root2] = Root1;    //Root1中结点数多
        parent[Root1] = temp;      //Root2指向Root1
    }
}

//使用折叠规则的搜索算法
int UFSets::CollapsingFind (int i) {
	int j;
    //让 j 循双亲指针走到根
    for (j = i; parent[j] >= 0; j = parent[j]);
    while (i!=j) {     //换 parent[i] 到 j
        int temp = parent[i];  
        parent[i] = j;  i = temp; 
    }
    return j;
}	


#endif