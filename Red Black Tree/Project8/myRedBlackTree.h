#include"Node.h"
#include <iostream>
using namespace std;
template <class T>
class myRedBlackTree
{
private:
	Node<T>* root;
	void inorderRBT(Node<T>* root)
	{
		if (root == nullptr)
		{
			return;
		}
		inorderRBT(root->left);
		cout << root->data << "(" << root->colour << ")" << "  ";
		inorderRBT(root->right);
	}
	void preorderRBT(Node<T>* root)
	{
		if (root == nullptr)
		{
			return;
		}
		cout << root->data << "(" << root->colour << ")" << "  ";
		preorderRBT(root->left);
		preorderRBT(root->right);
	}
	void postorderRBT(Node<T>* root)
	{
		if (root == nullptr)
		{
			return;
		}
		postorderRBT(root->left);
		postorderRBT(root->right);
		cout << root->data << "(" << root->colour << ")" << "  ";

	}
	int RBTheight(Node<T>* root)
	{
		int height = 0;
		int leftHeight = 0;
		int rightHeight = 0;
		int maximum = 0;

		Node<T>* current = root;
		if (current != NULL)
		{
			leftHeight = RBTheight(current->left);
			rightHeight = RBTheight(current->right);
			if (leftHeight >= rightHeight)
			{
				maximum = leftHeight;
			}
			else
			{
				maximum = rightHeight;
			}
			height = maximum + 1;
		}
		return height;
	}
	int countLeafNodesRBT(Node <T>* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->right == NULL && root->left == NULL)
		{
			return 1;
		}

		return countLeafNodesRBT(root->right) + countLeafNodesRBT(root->left);
	}
	void insertRBT(Node <T>* newNode)
	{
		while (newNode->parent->colour == 'r')
		{
			Node<T>* grandparent = newNode->parent->parent;
			Node<T>* uncle = root;
			if (newNode->parent->data >= grandparent->data)
			{
				uncle = grandparent->left;
				if (uncle == nullptr)
				{
					uncle = root;
				}
			}
			else
			{
				uncle = grandparent->right;
				if (uncle == nullptr)
				{
					uncle = root;
				}
			}



			if (uncle->colour == 'r')   //CASE 1 uncle and parent is red
			{
				uncle->colour = 'b';
				newNode->parent->colour = 'b';
				if (grandparent != root)
				{
					grandparent->colour = 'r';
					newNode = grandparent;
				}
				else
				{
					break;
				}
			}

			else if ((newNode->parent->data < grandparent->data) && (newNode->data < newNode->parent->data)) //left-left rotation
			{
				rightRotate(grandparent);
				char c = grandparent->colour;
				grandparent->colour = grandparent->right->colour;
				grandparent->right->colour = c;
				if (grandparent->data == root->data)
				{
					break;
				}
				newNode = grandparent->parent;
				if (newNode->data == root->data)
				{
					break;
				}
			}
			else if ((newNode->parent->data < grandparent->data) && (newNode->data >= newNode->parent->data)) //left-right rotation
			{
				leftRotate(newNode->parent);  //right-rotate new node parent
				rightRotate(grandparent);   //left-left rotation
				char c = grandparent->colour;
				grandparent->colour = grandparent->right->colour;
				grandparent->right->colour = c;
				if (grandparent->data == root->data)
				{
					break;
				}
				newNode = grandparent->parent;
				if (newNode->data == root->data)
				{
					break;
				}
			}

			else if ((newNode->parent->data >= grandparent->data) && (newNode->data >= newNode->parent->data)) //right-right rotation
			{
				leftRotate(grandparent);
				char c = grandparent->colour;
				grandparent->colour = grandparent->left->colour;
				grandparent->left->colour = c;
				if (grandparent->data == root->data)
				{
					break;
				}
				newNode = grandparent->parent;
				if (newNode->data == root->data)
				{
					break;
				}

			}

			else if ((newNode->parent->data >= grandparent->data) && (newNode->data < newNode->parent->data)) //right-left rotation
			{
				rightRotate(newNode->parent); //left-rotate new-node parent
				leftRotate(grandparent);   //right right rotation
				char c = grandparent->colour;
				grandparent->colour = grandparent->left->colour;
				grandparent->left->colour = c;
				if (grandparent->data == root->data)
				{
					break;
				}
				newNode = grandparent->parent;
				if (newNode->data == root->data)
				{
					break;
				}

			}

		}
	}
	void rightRotate(Node <T>* current)
	{
		Node <T>* temp = new Node<T>();
		if (current->left != nullptr)
		{
			if (current->left->right != nullptr)
			{
				temp->left = current->left->right;
			}
		}


		temp->right = current->right;
		temp->data = current->data;
		temp->colour = current->colour;

		current->data = current->left->data;
		current->colour = current->left->colour;

		current->right = temp;
		if (temp->left != nullptr)
		{
			temp->left->parent = temp;
		}
		if (temp->right != nullptr)
		{
			temp->right->parent = temp;
		}
		temp->parent = current;
		if (current->left->left)
		{
			current->left = current->left->left;
		}
		else
		{
			current->left = nullptr;
		}
		if (current->left)
		{
			current->left->parent = current;
		}
	}
	void leftRotate(Node <T>* current)
	{
		Node <T>* temp = new Node<T>();
		if (current->right->left)
		{
			temp->right = current->right->left;
		}
		temp->left = current->left;
		temp->data = current->data;
		temp->colour = current->colour;
		current->data = current->right->data;
		current->colour = current->right->colour;
		current->left = temp;
		if (temp->left != nullptr)
		{
			temp->left->parent = temp;
		}
		if (temp->right != nullptr)
		{
			temp->right->parent = temp;
		}
		temp->parent = current;
		if (current->right->right)
		{
			current->right = current->right->right;
		}
		else
		{
			current->right = nullptr;
		}
		if (current->right)
		{
			current->right->parent = current;
		}
	}
	void check(Node<T>* newNode)
	{
		if (newNode == nullptr)
		{
			return;
		}
		else
		{
			check(newNode->left);
			check(newNode->right);
			insertRBT(newNode);
			return; 
		}
	}
public:
	myRedBlackTree()
	{
		root = nullptr;
	}
	void insert(T val)
	{
		if (root == nullptr)
		{
			Node<T> * newnode = new Node<T>();
			newnode->data = val;
			newnode->left = nullptr;
			newnode->right = nullptr;
			newnode->parent = nullptr;
			newnode->colour = 'b';
			root = newnode;
			return;
		}
		else
		{
			Node<T> * temp = root;
			Node<T> * newnode = new Node<T>();
			newnode->data = val;
			newnode->colour = 'r';
			while (temp != nullptr)
			{
				if (temp->data > val)
				{
					if (temp->left == nullptr)
					{
						temp->left = newnode;
						newnode->colour = 'r';
						newnode->parent = temp;
						break;
					}
					else
					{
						temp =temp->left;
					}
				}

				else
				{
					if (temp->right == nullptr)
					{
						temp->right = newnode;
						newnode->colour = 'r';
						newnode->parent = temp;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
			}
			insertRBT(newnode);
		}
	}
	void inorder()
	{

		inorderRBT(root);
	}
	void preorder()
	{

		preorderRBT(root);
	}
	void postorder()
	{

		postorderRBT(root);
	}
	int height()
	{
		int h = RBTheight(root);

		return h;
	}
	int countLeafNodes()
	{
		return countLeafNodesRBT(root);
	}
	void remove(int val) 
	{
		Node<T>* it = nullptr;
		Node<T>* branch = nullptr;
		it = root;
		while (true)
		{
			if (val > it->data)
			{
				it = it->right;
			}
			else if (val < it->data)
			{
				it = it->left;
			}
			if (val == it->data)
			{
				break;
			}
		}
		Node<T>* pit = it->parent;
		if (it->left == nullptr && it->right == nullptr)
		{
			delete_fix(it);
			if (root->data == val && root->left == nullptr && root->right == nullptr)
			{
				delete root;
				root = nullptr;
				return;
			}
			pit = it->parent;
			if (pit->left == it)
			{
				pit->left = nullptr;
			}
			else if (pit->right == it)
			{
				pit->right = nullptr;
			}
			delete it;
			return;
		}
		else if (it->left == nullptr)
		{
			branch = it->right;
			if (pit->left == it)
			{
				pit->left = branch;
			}
			else if (pit->right == it)
			{
				pit->right = branch;
			}
			branch->parent = pit;
		}
		else if (it->right == nullptr)
		{
			branch = it->left;
			if (pit->left == it)
			{
				pit->left = branch;
			}
			else if (pit->right == it)
			{
				pit->right = branch;
			}
			branch->parent = pit;
		}
		else
		{
			Node<T>* temp = it->right;
			pit = it;
			while (true)
			{
				if (temp->left == nullptr)
				{
					break;
				}
				else
				{
					pit = temp;
					temp = temp->left;
				}
			}
			it->data = temp->data;
			temp->data = val;
			it = temp;
			pit = it->parent;
			branch = temp->right;
			if (pit->left == it)
			{
				pit->left = branch;
			}
			else if (pit->right == it)
			{
				pit->right = branch;
			}
		}
		if (it->colour == 'b' && branch != nullptr)
		{
			delete_fix(branch);
		}
		delete it;
	}
	void delete_fix(Node<T>* itr) {
		Node<T>* check = root;
		Node<T>* temp;
		while (itr != check && itr->colour == 'b') {
			temp = itr->parent;
			if (itr == temp->left) {
				Node<T>* sibling = temp->right;
				if (sibling != nullptr && sibling->colour == 'r') {
					sibling->colour = 'b';
					temp->colour = 'r';
					leftRotate( itr->parent);
					check = root;
					sibling = temp->right;
				}
				if ((sibling->left == nullptr && sibling->right == nullptr) || (sibling->left->colour == 'b' && sibling->right->colour == 'b')) {
					sibling->colour = 'r';
					itr = itr->parent;
				}
				else {
					if (sibling->right == nullptr || sibling->right->colour == 'b') {
						if (sibling->left != nullptr)
						{
							sibling->left->colour = 'b';
						}
						sibling->colour = 'r';
						rightRotate( sibling);
						check = root;
						sibling = itr->parent->right;
					}
					sibling->colour = itr->parent->colour;
					itr->parent->colour = 'b';
					if (sibling->right != nullptr)
					{
						sibling->right->colour = 'b';
					}
					leftRotate( itr->parent);
					check = root;
					itr = check;
				}
			}
			else {
				Node<T>* sibling = itr->parent->left;
				if (sibling != nullptr && sibling->colour == 'r') {
					sibling->colour = 'b';
					itr->parent->colour = 'r';
					rightRotate( itr->parent);
					check = root;
					sibling = itr->parent->left;
				}
				if ((sibling->left == nullptr && sibling->right == nullptr) || (sibling->left->colour == 'b' && sibling->right->colour == 'b')) {
					sibling->colour = 'r';
					itr = itr->parent;
				}
				else {
					if (sibling->left == nullptr || sibling->left->colour == 'b') {
						if (sibling->right != nullptr)
						{
							sibling->right->colour = 'b';
						}
						sibling->colour = 'r';
						leftRotate( sibling);
						check = root;
						sibling = itr->parent->left;
					}
					sibling->colour = itr->parent->colour;
					itr->parent->colour = 'b';
					if (sibling->left != nullptr)
					{
						sibling->left->colour = 'b';
					}
					rightRotate( itr->parent);
					check = root;
					itr = check;
				}
			}
		}
		itr->colour = 'b';
	}
};