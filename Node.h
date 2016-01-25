#include <bits/stdc++.h>
using namespace std;

class Node{
	friend class BST;
private:
	Node* minValueNode();
	Node* maxValueNode();
public:
	int key;
	string data;
	Node* left;
	Node* right;

	Node(int,string); //constructor
	void insert(int,string); //insert pair
	bool containsKey(int); //check for key existance
	string lookUp(int); //look for data with key 
	void modify(int,string); //modify existing pair
	void inOrder();
	void preOrder();
	void postOrder();
	int countNodes(); //count of nodes in the BST
	Node* deleteNode(int,Node*);
	int getH();
};

#include "Node.cpp"