#ifndef GRAPHMTX_H
#define GRAPHMTX_H

#include <iostream>
#include "linkqueue.h"
#include "linkstack.h"
using namespace std;

template <class T, class E>
class Graphmtx{
private:
    T *VerticesList; 	//顶点表
   	E **Edge;			//邻接矩阵
public:  
	E maxWeight;
	int numVertices;
	int numEdges;
	int maxVertices;
	Graphmtx();
	Graphmtx (E maxW ,int sz = 30);     
    ~Graphmtx ()		   
    { delete [ ]VerticesList;  delete [ ]Edge; }
	//取顶点 v 的第一个邻接顶点
    int getFirstNeighbor (int v); 
	//取 v 的邻接顶点 w 的下一邻接顶点
	int getNextNeighbor (int v, int w);
	//插入顶点vertex
   	bool insertVertex (const T vertex);
	//插入边(v1, v2),权值为cost
   	bool insertEdge (int v1, int v2, E cost);
   	bool insertEdge2 (int v1, int v2, E cost);
	//删去顶点 v 和所有与它相关联的边
   	bool removeVertex (int v);
	//在图中删去边(v1,v2)
   	bool removeEdge (int v1, int v2);
	
	//取顶点 i 的值, i 不合理返回0
	T getValue (int i) {        
 	    return VerticesList[i]; 
    }
	//取边(v1,v2)上权值
   	E getWeight (int v1, int v2) {  
 	    return  Edge[v1][v2];
    }
	//给出顶点vertex在图中的位置
	int getVertexPos (T Vertex) {	
			for (int i = 0; i < numVertices; i++)
				if (VerticesList[i] == Vertex) return i;
			return -1; 
	}
	int NumberOfVertices(){return numVertices;}
	int NumberOfEdges(){return numEdges;}
};

template <class T, class E>  
Graphmtx<T, E>::Graphmtx(E maxW,int sz) {      
    maxWeight = maxW;
    maxVertices = sz;  
    numVertices = 0;  numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices];  //创建顶点表
    Edge = (E **) new E *[maxVertices];
	for (i = 0; i < maxVertices; i++)
	    Edge[i] = new int[maxVertices];   //邻接矩阵 
   	for (i = 0; i < maxVertices; i++)        //矩阵初始化
	    for (j = 0; j < maxVertices; j++)
		  Edge[i][j] = (i == j) ? 0 : maxWeight; 
}


template <class T, class E>
int Graphmtx<T, E>::getFirstNeighbor (int v) {
//给出顶点位置为v的第一个邻接顶点的位置, 
//如果找不到, 则函数返回-1
    if (v != -1) {
 	   for (int col = 0; col < numVertices; col++)
           if (Edge[v][col] && Edge[v][col] < maxWeight)   
               return col;
   	}
   	return -1;
}

template <class T, class E>
int Graphmtx<T, E>::getNextNeighbor (int v, int w) {
//给出顶点 v 的某邻接顶点 w 的下一个邻接顶点 
    if (v != -1 && w != -1) {
	   for (int col = w+1; col < numVertices; col++) 
          if (Edge[v][col] && Edge[v][col] < maxWeight)  
              return col; 
   	}
   	return -1;
};

template <class T, class E>
//插入顶点vertex
bool Graphmtx<T, E>::insertVertex (const T vertex){
	if(numVertices==maxVertices) return false;
	VerticesList[numVertices++] = vertex;
	return true;
}


template <class T, class E>
//插入边(v1, v2),权值为cost
bool Graphmtx<T, E>::insertEdge (int v1, int v2, E cost){
	if( v1 > -1 && v1 < numVertices && v2 > -1 && v2 < numVertices 
			&& Edge[v1][v2] == maxWeight ){
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++; return true;
	}
	else return false;
}

template <class T, class E>
//插入边(v1, v2),权值为cost
bool Graphmtx<T, E>::insertEdge2 (int v1, int v2, E cost){
	if( v1 > -1 && v1 < numVertices && v2 > -1 && v2 < numVertices 
			&& Edge[v1][v2] == maxWeight ){
		Edge[v1][v2] = cost;
		numEdges++; return true;
	}
	else return false;
}

template <class T, class E>
void input(Graphmtx<T,E>& G,int flag = 0){
	int i,j,k,n,m; T e1,e2; E w;
	cout<<"顶点数,边数:";
	cin >> n >> m;
	cout<<endl;
	cout<<"顶点";
	for(i=0;i<n;i++){		
		cin>>e1;
		G.insertVertex(e1);
	}
	cout<<endl;
	i=0;
	cout<<"顶点1,顶点2,权值"<<endl;
	while(i<m){
		cin>>e1>>e2>>w;
		j=G.getVertexPos(e1);k=G.getVertexPos(e2);
		if(j==-1||k==-1)
			cout<<"边端点信息有误"<<endl;
			else{
				if(flag == 0)
					G.insertEdge(j,k,w);
				else if(flag == 1)
					G.insertEdge2(j,k,w);
				i++;
			}
	}
}

template <class T, class E>
void output(Graphmtx<T,E>& G){
	int i,j,k,n,m; T e1,e2; E w;
	n = G.NumberOfVertices();	m = G.NumberOfEdges();
	cout<<"顶点数："<<n<<" "<<"边数："<<m<<endl;
	for( i = 0; i < n; i++ )
		for( j = 0;j < n;j++){
			w = G.getWeight(i,j);
			e1 = G.getValue(i);
			e2 = G.getValue(j);
			cout<<"("<<e1<<","<<e2<<")"<<"权值"<<w<<endl;
		}
}

#endif