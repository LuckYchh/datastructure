#include "Graphmtx.h"


template<class T,class E>
void PrintPath(Graphmtx<T, E>& G,int v,E dist[],int path[]);
//Graphmtx是一个带权有向图。dist[j], 0≤j<n, 是当前
//求到的从顶点v到顶点j的最短路径长度, path[j],
//0≤j<n, 存放求到的最短路径
template<class T,class E>
void dijkstra (Graphmtx<T, E>& G, T v) {
    int n = G.NumberOfVertices();
    E *dist = new E[n];
    int *path = new int[n];
    bool *S = new bool[n]; 
    int i, j, k;  E w, min;
    //三个数组初始化
	for (i = 0; i < n; i++) {
	    dist[i] = G.getWeight(v, i); 
		S[i] = false;
        if (i != v && dist[i] < 255) path[i] = v;
        else path[i] = -1;
    }
    S[v] = true;  dist[v] = 0;     	//顶点v加入顶点集合
    for (i = 0; i < n-1; i++) {       //求解各顶点最短路径
        min = 255;  int u = v; 				//选不在S中具有最短路径的顶点u
        for (j = 0; j < n; j++)		
            if (!S[j] && dist[j] < min) 
                { u = j; min = dist[j];}
        S[u] = true;	               	//将顶点u加入集合S
		
		for (k = 0; k < n; k++) {       	//修改
            w = G.getWeight(u, k);
            if (!S[k] && w < 255 && 
                    dist[u]+w < dist[k]) {       //顶点k未加入S                
                dist[k] = dist[u]+w; 
                path[k] = u;     		//修改到k的最短路径
            }    
        }
    }
    PrintPath(G,3,dist,path);
}


template<class T,class E>
void PrintPath(Graphmtx<T, E>& G,int v,E dist[],int path[]){
	cout<<"顶点"<<G.getValue(v)<<"到其他各顶点最短路径为："<<endl;
	int i,j,k,n=G.NumberOfVertices();
	int *d = new int[n];
	for(i=0;i<n;i++)
		if(i!=v){
			j=i;k=0;
			while(j!=v&&j>-1){
				d[k++]=j;j=path[j];}
			cout<<"到顶点"<<G.getValue(i)<<"的最短路径为："<<G.getValue(v)<<" ";
			while(k>0){cout<<G.getValue(d[--k])<<" ";}
			cout<<"最短路径长度："<<dist[i]<<endl;
		}
	delete [] d;
}