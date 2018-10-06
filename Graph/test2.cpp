#include "test.h"

int main(){

	Graphmtx<int,int> G(255,5);
	input(G);
	Prime(G,0);
	return 0;
}