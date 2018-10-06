#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "linkstack.h"
using namespace std;

template <class E>
struct AVLNode{
//AVL树结点的类定义  
	E data;				    //数据域
    AVLNode<E> *left, *right;  //左子女和右子女
    int bf;
	AVLNode() { left = NULL; right = NULL; bf = 0; }
	AVLNode (E d, AVLNode<E> *l = NULL,  
            AVLNode<E> *r = NULL) 
		{ data = d;  left = l;  right = r;  bf = 0; }
};

template <class E>
class AVLTree{
public:
    AVLTree() { root = NULL; }
    AVLTree (E value);
    bool Insert (AVLNode<E>*& ptr, E& e1);
    void RotateL (AVLNode<E>*& ptr); 	  //左单旋
    void RotateR (AVLNode<E>*& ptr);	  //右单旋
    void RotateLR (AVLNode<E>*& ptr);		//先左后右双旋
    void RotateRL (AVLNode<E>*& ptr);		//先右后左双旋
protected:
	AVLNode<E> *root;
};

template <class E> 
void AVLTree<E>::
RotateL (AVLNode<E> *& ptr) {
//右子树比左子树高: 做左单旋转后新根在ptr
AVLNode<E> *subL = ptr;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL; 
	ptr->bf = subL->bf = 0;
}

template <class E>
void AVLTree<E>::
RotateR (AVLNode<E> *& ptr) { 
    AVLNode<E> *subR = ptr;   //要右旋转的结点
    ptr = subR->left;
    subR->left = ptr->right;	      //转移ptr右边负载
    ptr->right = subR;		      //ptr成为新根
    ptr->bf = subR->bf = 0;
}


template <class E>
void AVLTree<E>:: RotateLR (AVLNode<E> *& ptr) {
    AVLNode<E> *subR = ptr;
    AVLNode<E> *subL = subR->left;
    ptr = subL->right;
    subL->right = ptr->left;
    ptr->left = subL;
    if (ptr->bf <= 0) subL->bf = 0;
    else subL->bf = -1;
    subR->left = ptr->right;
    ptr->right = subR;	
    if (ptr->bf == -1) subR->bf = 1;
    else subR->bf = 0;
	ptr->bf = 0;
}

template <class E>
void AVLTree<E>::
RotateRL (AVLNode<E> *& ptr) {
    AVLNode<E> *subL = ptr;
	AVLNode<E> *subR = subL->right;
    ptr = subR->left;
    subR->left = ptr->right; 
    ptr->right = subR;
    if (ptr->bf >= 0) subR->bf = 0;
    else subR->bf = 1;
    subL->right = ptr->left;
    ptr->left = subL;
    if (ptr->bf == 1) subL->bf = -1;
    else subL->bf = 0;
    ptr->bf = 0;
}

template<class E>
bool AVLTree<E>::Insert(AVLNode<E> *& ptr,E& e1){
    AVLNode<E> * pr = NULL, *p = ptr,*q;int d;
    LinkedStack<AVLNode<E> *> st;
    while(p!=NULL){
        if(e1 == ptr->data ) return false;
        pr = p;st.Push(pr);
        if(e1<ptr->data) ptr=ptr->left;
        else ptr=ptr->right;
    }
    p=new AVLNode<E>(e1);
    if(p==NULL){cerr<<"存储不足"<<endl;return;}
    if(ptr==NULL){p=ptr;pr=p;return true;}
    //插入结点
    if(e1<ptr->data) ptr->left=p;
    else ptr->right=p;
    while(st.IsEmpty()==false){
        st.Pop(pr);
        //插入一个结点，调整bf，左-右+
        if(p==ptr->left) pr->bf--;
        else pr->bf++;
        //bf=0 平衡，不处理
        if(pr->bf==0) break;
        //|bf|=1 当前分支平衡，上层可能不平衡，做回溯处理
        if(pr->bf==1||pr->bf==-1) p=pr;
        //直接|bf|>1 不平衡
        else{
            d=(pr->bf<0)?-1:1;
            if(p->bf==d){
                if(d==-1) RotateR(pr);
                else RotateL(pr);
            }
            else{
                if(d==-1) RotateLR(pr);
                else RotateRL(pr);
            }
            break;
        }
    }
    //调整根结点
    if(st.IsEmpty()==true) ptr = pr;
    else{
        st.getTop(q);
        if(q->data>pr->data) q->left = pr;
        else q->right = pr;
    }
    return true;
}    
#endif


















