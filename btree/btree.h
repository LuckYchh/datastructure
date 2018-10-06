#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "linkstack.h"
#include "linkqueue.h"
using namespace std;

template <class T> 
struct BinTreeNode {	
    T data;	 		  
	BinTreeNode<T> *leftChild, *rightChild;
    BinTreeNode ()                //构造函数
    { leftChild = NULL;  rightChild = NULL; }
	BinTreeNode (T x, BinTreeNode<T> *l = NULL,  
					BinTreeNode<T> *r = NULL)
    { data = x;  leftChild = l;  rightChild = r; }
};

template <class T> 
class BinaryTree {		
protected:
    BinTreeNode<T> *root;         //二叉树的根指针
public:
    BinaryTree () {root=NULL;}	  //构造函数
    BinaryTree (T value){ }       //构造函数
    ~BinaryTree () { }	          //析构函数
    void CreateBtree(BinTreeNode<T> *&subTree);
    bool IsEmpty () { return root == NULL;}  //判二叉树空否
	void PreOrder(BinTreeNode<T> * subTree); //前序遍历
    void InOrder(BinTreeNode<T> * subTree);  //中序遍历
    void PostOrder(BinTreeNode<T> * subTree);//后序遍历
    void LevelOrder(BinTreeNode<T> *subTree);						 //层次序遍历
	void PreOrder2(BinTreeNode<T> *subTree);						 //前序非递归遍历
	int Insert (const T item);	       		 //插入	
    BinTreeNode<T> *Find (T item) const;	 //搜索
};

template <class T> 
void BinaryTree<T>::CreateBtree(BinTreeNode<T> *&subTree)
{
    T data;
    cin>>data;
    if(data=='#') 
        subTree=NULL;
    else{
       subTree = new BinTreeNode<T>(data); //创建根结点
       if(NULL == subTree) return ;
       CreateBtree(subTree->leftChild);    //创建左子树	
       CreateBtree(subTree->rightChild);   //创建右子树
   }
    
}


template <class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> * subTree){
    if (subTree != NULL) {
        InOrder(subTree->leftChild); //遍历左子树                                           
        cout<<subTree->data;	 //访问根结点
        InOrder(subTree->rightChild);//遍历右子树
	}
}

template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> * subTree){
    if(subTree != NULL) {
		cout<<subTree->data;	   //访问根结点
		PreOrder(subTree->leftChild);  //遍历左子树
		PreOrder(subTree->rightChild); //遍历右子树
	}
}

template <class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> * subTree){
    if(subTree != NULL ) {
        PostOrder(subTree->leftChild);	 //遍历左子树                                                 
		PostOrder(subTree->rightChild); //遍历右子树
		cout<<subTree->data;	     //访问根结点
	}
}


template <class T> 
void BinaryTree<T>::PreOrder2 (BinTreeNode<T> *subTree) {
    LinkedStack<BinTreeNode<T>*> S;
    BinTreeNode<T> *p; 
    S.Push (subTree);
	while(!S.IsEmpty()) {
        S.Pop(p);
        cout<<p->data;	   //访问结点
 	    if (p->rightChild != NULL)
            S.Push(p->rightChild);//预留右指针在栈中
        if (p->leftChild != NULL) 
            S.Push(p->leftChild);	   //进左子树
    }
}


template <class T>
void BinaryTree<T>::LevelOrder(BinTreeNode<T> *subTree){
    if(subTree == NULL) return;
    LinkedQueue<BinTreeNode<T>*> Q;
    BinTreeNode<T> *p = subTree;   
    cout<<p->data;  
	Q.EnQueue(p); 	
    while(!Q.IsEmpty()){
        Q.DeQueue(p);
        if (p->leftChild != NULL) {              
            cout<<p->leftChild->data;
            Q.EnQueue(p->leftChild);
        }
        if (p->rightChild != NULL) {
            cout<<p->rightChild->data;
            Q.EnQueue(p->rightChild);
        }
    }
}

#endif