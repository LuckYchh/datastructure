#include "seqlist.h"

SeqList::SeqList(int sz){ 
	if(sz > 0){
        maxSize = sz;  n = 0;
	 	data = new int[maxSize];	   //创建表存储数组
 	    if(data == NULL){		   //动态分配失败
			cerr << "存储分配错误！" << endl;  
			return ; 
		}
   	}
}

void SeqList::input(){
	cout<<"input the size:";
	while(1){
		cin >> n;
		if(n<=maxSize) break;
		cout<<"the size is bigger than"<<maxSize-1<<":";
	}
	for(int i=0;i<=n;i++){
		cin>>data[i];
		cout<<i+1<<endl;
	}

}

int SeqList::Search(int x) const{
//在表中顺序搜索与给定值 x 匹配的表项，找到则
//函数返回该表项是第几个元素，否则函数返回0
    for(int i = 1; i <= n; i++) //顺序搜索
        if(data[i-1] == x) 
			return i; //表项序号和表项位置差1
	return 0;		    //搜索失败
}

bool SeqList::Insert(int i, int x){
//将新元素x插入到表中第i (1≤i≤n+1) 个表项位
//置。函数返回插入成功的信息
    if(n == maxSize) 
		return false;     //表满
	if(i < 1 || i > n+1) 
		return false;	  //参数i不合理
    for(int j = n; j >= i; j--)  //依次后移
        data[j] = data[j-1]; 
    data[i-1] = x;	      //插入(第 i 表项在data[i-1]处)
	n++;   
	return true;
}

bool SeqList::Remove (int i, int& x) {
//从表中删除第 i (1≤i≤n) 个表项，通过引用型参
//数 x 返回被删元素。函数返回删除成功信息
	if (n == 0) 
		return false;	 //表空
    if (i < 1 || i > n) 
		return false;	 //参数i不合理
    x = data[i-1];  

    for(int j = i; j <= n-1; j++) //依次前移，填补
        data[j-1] = data[j];

  	n--;   
	return true; 	
}

void SeqList::show()
{
	if(n!=0)
		for(int i=0;i<n;i++)
			cout<<i+1<<":"<<data[i]<<endl;
}