#include <iostream>
#include "myRedBlackTree.h"
using namespace std;
int main()
{
	myRedBlackTree<int> ob;
	ob.insert(100);
	ob.insert(30);
	ob.insert(200);
	ob.insert(300);
	ob.insert(25);
	ob.insert(45);
	ob.insert(60);
	ob.inorder();
	ob.remove(200);
	cout << endl << endl;
	ob.inorder();
}