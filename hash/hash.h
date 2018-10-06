#ifndef HASH_H
#define HASH_H

#include <iostream>
using namespace std;

const int DefaultSize = 100;
enum KindOfStatus {Active, Empty, Deleted};//元素分类 (活动/空/删)

template <class E, class K>
class HashTable {		     //散列表类定义
public:
    HashTable (const int d, int sz = DefaultSize);
    ~HashTable() { delete []ht;  delete []info; }
    bool Search (K k1, E& e1); //搜索k1
	bool Insert (E e1);		 //插入e1
    bool Remove (K k1,E& e1);	     //删除e1
    void makeEmpty ();			     //置表空
private:
    int divitor;		//散列函数的除数
    int n, TableSize;	//当前桶数及最大桶数
	E *ht;				//散列表存储数组
    KindOfStatus *info;	//状态数组
    int FindPos (K k1);	//查找位置
};

template<class E, class K>		
HashTable<E, K>::HashTable (int d, int sz) {
    divitor = d;				//除数
    TableSize = sz;  n = 0;		//表长
    ht = new E[TableSize];		//表存储空间
    info = new KindOfStatus[TableSize];
	for (int i = 0; i < TableSize; i++) info[i] = Empty;
}

//搜索在一个散列表中关键码与k1匹配的元素，
//搜索成功，则函数返回该元素的位置，否则返回
//插入点（如果有足够的空间）
template <class E, class K>
int HashTable<E, K>::FindPos (K k1){
    int i = k1 % divitor;	        //计算初始桶号
    int j = i;			            //j是检测下一空桶下标
	do {
        if (info[j] == Empty || info[j] == Active &&
              ht[j] == k1) return j;//找到初始桶号
        j = (j+1) % TableSize;		//找下一个空桶 
    } while (j != i);
    return j;	      //转一圈回到开始点, 表已满, 失败
}

//使用线性探查法在散列表ht(每个桶容纳一个元素)
//中搜索k1
template <class E, class K>
bool HashTable<E, K>::Search (K k1, E& e1) {
    int i = FindPos (k1);  		//搜索
	if (info[i] != Active || ht[i] != k1) return false;
	e1 = ht[i];  
	return true;
}


//在ht表中搜索k1。若找到则不再插入, 若未找到, 
//但找到位置的标志是Empty或Deleted, x插入 
template <class E, class K>
bool HashTable<E, K>::Insert (E e1) {
	K k1 = e1;
    int i = FindPos (k1);	    //用散列函数计算桶号
    if (info[i] != Active) {	    //该桶空,存放新元素
        ht[i] = e1;   info[i] = Active;
        n++;   return true;
    }
    if (info[i] == Active && ht[i] == e1) 
        cout << "表中已有此元素，不能插入！\n";   
    else cout << "表已满，不能插入！\n";
    return false;
}

    //在ht表中删除元素key, 并在引用参数e1中得到它
template <class E, class K>
bool HashTable<E, K>::Remove (K k1, E& e1) {
    int i = FindPos (k1);
    if (info[i] == Active) {//找到要删元素, 且是活动元素
        info[i] = Deleted;  n--; 	//做逻辑删除标志, 并不真正物理删除
        return true;
    }
	else return false;
}

#endif