#ifndef TEST_H
#define TEST_H

#include "Graphmtx.h"

template<class T, class E> 
void DFS (Graphmtx<T, E>& G, const T& v) {
    int i, loc, n = G.NumberOfVertices();   
    bool *visited = new bool[n];          
   	//记录是否访问过，初始全没访问过。
	for (i = 0; i < n; i++) visited [i] = false;	
	loc = G.getVertexPos(v); //获取顶点位置
    DFS (G, loc, visited); 	//从顶点V开始深度优先搜索
   	delete [] visited;	    //释放visited
};


template<class T, class E>
void DFS (Graphmtx<T, E>& G, int v, bool visited[]) {
    cout << G.getValue(v) << ' ';  //访问顶点v
    visited[v] = true;	 	       //标记一下表示访问过
    int w = G.getFirstNeighbor(v); //获取V第一个邻接顶点
   	while (w != -1) {			   //若邻接顶点w存在
 	    if ( !visited[w] )
			//若w未访问过, 递归访问顶点w。
			DFS(G, w, visited);	
        w = G.getNextNeighbor (v, w); //下一个邻接顶点
    }
};


template <class T, class E> 
void DFS2 (Graphmtx<T, E>& G, const T& v) {
    int i, w, n = G.NumberOfVertices(); 
    bool *visited = new bool[n];	
    for (i = 0; i < n; i++) visited[i] = false;	
    int loc = G.getVertexPos (v);		//取顶点号
    LinkedStack<int> S;
    S.Push(loc);
    visited[loc] = true; 	            //做已访问标记      
    while(!S.IsEmpty())	{		
		S.Pop(loc);	
		cout << G.getValue (loc) << ' '; 	//访问顶点v
		w = G.getFirstNeighbor(loc);
		while(w != -1){
			if(!visited[w]){					
				visited[w] = true;				
				S.Push(w);	
			}
			w = G.getNextNeighbor(loc , w);					
		}			
	}
	delete [] visited;	
}


template <class T, class E> 
void BFS (Graphmtx<T, E>& G, const T& v) {
    int i, w, n = G.NumberOfVertices(); 	
	bool *visited = new bool[n];	
    for (i = 0; i < n; i++) visited[i] = false;
    int loc = G.getVertexPos (v);		//取顶点号
    cout << G.getValue (loc) << ' '; 	//访问顶点v
    visited[loc] = true; 	            //做已访问标记       
    LinkedQueue<int> Q;  Q.EnQueue (loc); 	//顶点进队列, 实现分层访问
    while (!Q.IsEmpty() ) {				//循环, 访问所有结点
        Q.DeQueue (loc);
        w = G.getFirstNeighbor (loc);  	//第一个邻接顶点
        while (w != -1) {				//若邻接顶点w存在
            if (!visited[w]) {			//若未访问过
				cout << G.getValue (w) << ' ';	//访问
                visited[w] = true; 		
                Q.EnQueue (w); 			//顶点w进队列
            }
            w = G.getNextNeighbor (loc, w); //找顶点loc的下一个邻接顶点
        }
    }		   //外层循环，判队列空否
    delete [] visited;
}


template <class T, class E> 
void Prime (Graphmtx<T, E>& G, T v) {
    int sum = 0, min = 0;
    int n = G.NumberOfVertices();
    E *cost = new E[n];
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        cost[i] = G.getWeight(v,i);
        visited[i] = false;
    }
    visited[v] = true; 

    for(int i=0;i<n-1;i++){
        min =255; int k;
        for(int j=0;j<n;j++)
            if(visited[j]==false&&cost[j]<min){
                min=cost[j];k=j;
            }
        visited[k]=true;
        sum+=min;
        v=k;

        for(int j=0;j<n;j++){
            if(visited[j]==false&&G.getWeight(v,j)<cost[j])
                cost[j]=G.getWeight(v,j);
        }
    }
    cout<<"sum: "<<sum<<endl;
}


#endif