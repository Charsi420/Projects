#include "myRedBlackTree.h"
#include<iostream>
using namespace std;
int main()
{
	myRedBlackTree<int> * obj = new myRedBlackTree<int>();
	obj->insert(10);
	obj->insert(18);
	obj->insert(7);
	obj->insert(15);
	obj->insert(16);
	obj->insert(30);
	obj->insert(35);
	obj->insert(20);
	obj->insert(19);
	
	
	cout << endl << obj->countLeafNodes() << endl;

	
	
}