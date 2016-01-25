#include <bits/stdc++.h>
using namespace std;

class Node{
	friend class BST; //to grant BST class the access of private functions in Node class.
private:
	Node* minValueNode(); //return min node in this subtree (Node)
	Node* maxValueNode(); //return max node in this subtree (Node)
	Node* deleteNode(int,Node*); //delete node with key in this subtree (Node)
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
	int getH(); //get max height of subtree (Node).
};

#include "Node.cpp"