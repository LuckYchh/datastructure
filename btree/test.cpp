#include "btree.h"

int main()
{
	//-+a##*b##-c##d##/e##f##
	//AB#CD###E#FGH##K###
	BinaryTree<char> BT;
	BinTreeNode<char> *Bnode;
	cout << "创建一颗二叉树,其中A~Z字符代表树的数据,用'#'表示空树:" << endl;
	BT.CreateBtree(Bnode);
	//cout << "PreOrder:";
	BT.PreOrder(Bnode);
	cout<<"-----PreOrder"<<endl;
	BT.InOrder(Bnode);
	cout<<"-----InOrder"<<endl;
	BT.PostOrder(Bnode);
	cout<<"-----PostOrder"<<endl;

	BT.PreOrder2(Bnode);
	cout<<"-----PreOrder2"<<endl;
	BT.LevelOrder(Bnode);
	cout<<"-----LevelOrder"<<endl;

	return 0;
}