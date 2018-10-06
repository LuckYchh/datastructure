#include "Graphmtx.h"

template <class T, class E> 
struct EN{
    int head;
    int tail;
    E w;
};


int find(int *s,int f){
	while(s[f]!=-1) f=s[f];
	return f;
}

template <class T, class E> 
void sort(EN<T,E> *Ed,int n){
	for(int i=0;i<n;i++)
		for(int j=n-1;j>=i;j--)
			if(Ed[j].w<Ed[j-1].w){
				EN<T,E> temp = Ed[j-1];
				Ed[j-1] = Ed[j];
				Ed[j] = temp;
			}

}

template <class T, class E> 
void kruskal(Graphmtx<T, E>& G) {
	int n = 2*G.NumberOfVertices();
	int i=0;
	int *s = new int[n];
	EN<T,E> *Ed = new EN<T,E>[n];
	for(int u=0;u<n;u++)
		for(int v=u+1;v<n;v++)
			if(G.getWeight(u,v)!=255){
				Ed[i].head=u;Ed[i].tail=v;
				Ed[i].w=G.getWeight(u,v);
				i++;
			}
	for(int j=0;j<n;j++) s[j] = -1;
	sort(Ed,i);
	for(int j=0;j<i;j++)
		cout<<Ed[j].head<<Ed[j].tail<<Ed[j].w<<endl;
	for(int j=0;j<i;j++){
		int x=find(s,Ed[j].head);
		int y=find(s,Ed[j].tail);
		if(x!=y){
			s[x]=y;
			cout<<"("<<Ed[j].head<<" "
				<<Ed[j].tail<<")"<<Ed[j].w<<endl;
		}
	}
}