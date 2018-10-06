/**
*日期；		 2018-10-5
*微信公众号：嵌入式图像处理
*参考：      数据结构第二版，殷人昆，清华大学出版社
*/

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

#define N 10

template <class E>
struct BSTNode  {			//二叉树结点类
    E data;				    //数据域
    BSTNode<E> *left, *right;  //左子女和右子女
	BSTNode() { left = NULL; right = NULL; }
       //构造函数
    BSTNode (E d, BSTNode<E> *L = NULL, 
          BSTNode<E> *R = NULL)
        { data = d; left = L; right = R;}
};

template <class E>
class BST {				  //二叉搜索树类定义
public:
    BST(){root=NULL;}	//构造函数
    BST(E value);			//构造函数
    ~BST() {};	
    BSTNode<E> * 		//递归：搜索
        Search (E x, BSTNode<E> *ptr);
    BSTNode<E> *         //递归：搜索
        Search2 (E x, BSTNode<E> *ptr);
    void createBSTree(BSTNode<E> *ptr,E arr[]);
    void Inorder (BSTNode<E> *ptr);	//递归：打印
	bool Insert (E e1, BSTNode<E>* ptr);	//递归：插入
    bool Remove (E x, BSTNode<E>*& ptr);	//递归：删除
protected: 
    BSTNode<E> *root;	//根指针
};

template <class E>
BST<E>::BST (E value) {
//输入一个元素序列, 建立一棵二叉搜索树
    E x;  
    root = NULL;        //置空树
    cin >> x;                        //输入数据
    while ( x!= value) {                //RefValue是一个输入结束标志
         Insert (x, root);  cin >> x;      //插入，再输入数据
    }
};


template <class E>
void BST<E>::createBSTree(BSTNode<E> *ptr,E arr[]){
    ptr = new BSTNode<E>;  
    ptr->left = NULL;
    ptr->right = NULL;
    for(int i=0;i<N;i++){  
        Insert(arr[i],ptr);
    }
}


template <class E>
void BST<E>::Inorder(BSTNode<E> *ptr){
    if(ptr!=NULL){
        Inorder(ptr->left);
        cout<<ptr->data<<endl;
        Inorder(ptr->right);
    }
}

//在以ptr为根的二叉搜索树中搜索含x的结点。
//若找到，则函数返回该结点的地址，否则函数返回NULL值。
template<class E>
BSTNode<E>* BST<E>::
Search (E x, BSTNode<E> *ptr) {
    if (ptr == NULL) return NULL; 
    else if (x < ptr->data) return Search(x, ptr->left);
    else if (x > ptr->data) return Search(x, ptr->right);
    else return ptr;				//搜索成功
}

//非递归函数：作为对比，在当前以ptr为根的二
//叉搜索树中搜索含x的结点。若找到，则函数返
//回该结点的地址，否则函数返回NULL值。
template<class E>
BSTNode<E>* BST<E>::
Search2 (E x, BSTNode<E> *ptr) {
    if (ptr == NULL) return NULL; 
    BSTNode<E>* temp = ptr;
    while (temp != NULL) {
        if (x == temp->data) return temp;
        if (x < temp->data) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}

//在以ptr为根的二叉搜索树中插入值为
//e1的结点。若在树中已有含e1的结点则不插入
template <class E>
bool BST<E>::Insert (E e1, BSTNode<E> * ptr) {	   
    if (ptr == NULL) {	   
        ptr = new BSTNode<E>(e1);	  //创建新结点
        if (ptr == NULL)
            { cerr << "Out of space" << endl;  return false; }
	    return true;
    }
    else if (e1 < ptr->data) Insert (e1, ptr->left);	 		//左子树插入
		 else if (e1 > ptr->data) Insert (e1, ptr->right);		//右子树插入
		 else return false;	      //x已在树中,不再插入
}

//在以 ptr 为根的二叉搜索树中删除含 x 的结点
template <class E>
bool BST<E>::Remove (E x, BSTNode<E> *& ptr) {
    BSTNode<E> *temp;
    if (ptr != NULL) {
         if (x < ptr->data) Remove (x, ptr->left);	
                                           //在左子树中执行删除
	     else if (x > ptr->data) Remove (x, ptr->right);
					  //在右子树中执行删除
	else if (ptr->left != NULL && ptr->right != NULL)
        {       //ptr指示关键码为x的结点，它有两个子女
             temp = ptr->right;  
                 //到右子树搜寻中序下第一个结点
             while (temp->left != NULL) 
                 temp = temp->left;
             ptr->data = temp->data;
 		       //用该结点数据代替根结点数据
		   Remove (ptr->data, ptr->right);
        }
	    else {	//ptr指示关键码为x的结点有一个子女
			temp = ptr;
			if (ptr->left == NULL) ptr = ptr->right;
            else ptr = ptr->left;
            delete temp;
            return true;
        }
	}
	return false;
}

#endif