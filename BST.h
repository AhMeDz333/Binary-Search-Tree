#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

class BST{
private:
	Node* root;
	Node* maxValueNode(); //return max node in BST
	Node* minValueNode(); //return min node in BST
	void destroy(Node*); //recursively delete nodes (called by destructor)
public:
	BST(){root = NULL;} //constructor
	~BST(); //destructor
	void insert(int,string); //insert pair
	bool containsKey(int); //check for key existance
	string lookUp(int); //look for data with key 
	void modify(int,string); //modify existing pair
	void set(int,string); //exists? modify : insert
	void inOrder();
	void preOrder();
	void postOrder();
	int countNodes(); //number of nodes in this BST
	void displayMax();
	void displayMin();
	void deleteNode(int); //delete node with key
	int getMaxHeight();
	void buildFromArray(int*,string*,int); //build the BST with given array values
};

#include "BST.cpp"