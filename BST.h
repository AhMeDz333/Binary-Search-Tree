#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

class BST{
private:
	Node* root;
	Node* maxValueNode();
	Node* minValueNode();
	void destroy(Node*);
public:
	BST(){root = NULL;}
	~BST();
	bool containsKey(int);
	string lookUp(int);
	void insert(int,string);
	void modify(int,string);
	void set(int,string);
	void inOrder();
	void preOrder();
	void postOrder();
	int countNodes();
	void displayMax();
	void displayMin();
	void deleteNode(int);
	int getMaxHeight();
	void buildFromArray(int*,string*,int);
};

#include "BST.cpp"