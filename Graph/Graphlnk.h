#ifndef GRAPHLNK_H
#define GRAPHLNK_H

#include <iostream>
using namespace std;

template <class T, class E>
struct Edge {			  //边结点的定义
  int dest;				  //边的另一顶点位置
  E cost;				    //边上的权值
  Edge<T, E> *link;	//下一条边链指针
  Edge () {}				//构造函数
  Edge (int num, E weight) 	   //构造函数
    : dest (num), cost (weight), link (NULL) { }
};

template <class T, class E>
struct Vertex {		 //顶点的定义
  T data;				   //顶点的名字
	Edge<T, E> *adj; //边链表的头指针
};

template <class T, class E>
class Graphlnk {
private:
  Vertex<T, E> *NodeTable;//顶点表 (各边链表的头结点)
 	
public:
  int numVertices;
  int maxVertices;
  int numEdges;
  Graphlnk (int sz = 30);  //构造函数
  ~Graphlnk();	
	E getWeight (int v1, int v2);	     //取边(v1,v2)权值
	bool insertVertex (const T& vertex);
  bool removeVertex (int v);
  bool insertEdge (int v1, int v2, E cost);
	bool removeEdge (int v1, int v2);
  int getFirstNeighbor (int v);
  int getNextNeighbor (int v, int w);	
  int getVertexPos (const T vertx) {  
        //给出顶点vertex在图中的位置
      for (int i = 0; i < numVertices; i++)
          if (NodeTable[i].data == vertx) return i;
      return -1; 
  }
  T getValue (int i) {         //取顶点 i 的值
      return (i >= 0 && i < numVertices) ? 
             NodeTable[i].data : 0;
  }
};

template <class T, class E>
Graphlnk<T, E>::Graphlnk (int sz) {
//构造函数：建立一个空的邻接表
  maxVertices = sz;
  numVertices = 0;  numEdges = 0;
  NodeTable = new Vertex<T, E>[maxVertices];		//创建顶点表数组
  if (NodeTable == NULL) 
      { cerr << "存储分配错！" << endl;  return; }
  for (int i = 0; i < maxVertices; i++) 
      NodeTable[i].adj = NULL;
}

template <class T, class E>
Graphlnk<T, E>::~Graphlnk() {	
//析构函数：删除一个邻接表
  for (int i = 0; i < numVertices; i++ ) {
    Edge<T, E> *p = NodeTable[i].adj;
      while (p != NULL) {				
          NodeTable[i].adj = p->link;
          delete p;  p = NodeTable[i].adj;
      }
 	} 
 	delete [ ]NodeTable;  		     //删除顶点表数组
}

//给出顶点位置为 v 的第一个邻接顶点的位置, 
//如果找不到, 则函数返回-1
template <class T, class E>
int Graphlnk<T, E>::getFirstNeighbor (int v) {
  if (v != -1) {			//顶点v存在
    Edge<T, E> *p = NodeTable[v].adj;			//对应边链表第一个边结点
	if (p != NULL) return p->dest;				//存在, 返回第一个邻接顶点
   }
   	return -1;		//第一个邻接顶点不存在
}

//给出顶点v的邻接顶点w的下一个邻接顶点的位置,
//若没有下一个邻接顶点, 则函数返回-1
template <class T, class E>
int Graphlnk<T, E>::getNextNeighbor (int v, int w) {
  if (v != -1) {				//顶点v存在
      Edge<T, E> *p = NodeTable[v].adj;
      while (p != NULL && p->dest != w)
          p = p->link;
    if (p != NULL && p->link != NULL) 
          return p->link->dest; 	//返回下一个邻接顶点
 	}
 	return -1; 			//下一邻接顶点不存在
}


#endif



















