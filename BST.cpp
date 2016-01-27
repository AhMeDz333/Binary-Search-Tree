#include <bits/stdc++.h>
using namespace std;

bool BST::containsKey(int key){
	return root? root->containsKey(key) : 0;
}
string BST::lookUp(int key){
	if (!containsKey(key))
		throw invalid_argument("Key isn't there!");

	return root->lookUp(key);
}
void BST::insert(int key,string data){
	if (containsKey(key))
		throw invalid_argument("Key is already there!");

	if (!root)
		root = new Node(key,data);
	else
		root->insert(key,data);
}
void BST::modify(int key,string data){
	if (!containsKey(key))
		throw invalid_argument("Key isn't there!");

	root->modify(key,data);
}
void BST::set(int key,string data){
	if (containsKey(key))
		modify(key,data);
	else
		insert(key,data);
}
void BST::inOrder(){
	if (!root){
		cout << "BST is Empty!\n";
		return;
	}

	cout << "In-Order traversal result..\n";
	printf("[");
	root->inOrder();
	printf("]\n");
}
void BST::preOrder(){
	if (!root){
		cout << "BST is Empty!\n";
		return;
	}

	cout << "Pre-Order traversal result..\n";
	printf("[");
	root->preOrder();
	printf("]\n");
}
void BST::postOrder(){
	if (!root){
		cout << "BST is Empty!\n";
		return;
	}

	cout << "Post-Order traversal result..\n";
	printf("[");
	root->postOrder();
	printf("]\n");
}
int  BST::countNodes(){
	return root? root->countNodes() : 0;
}
Node* BST::maxValueNode(){
	return root? root->maxValueNode() : NULL;
}
void BST::displayMax(){
	Node* tmp = maxValueNode();
	
	if (tmp)
		cout << "Maximum key pair : (" << tmp->key << ":" << tmp->data << ")\n";
	else
		cout << "BST is Empty!\n";
}
Node* BST::minValueNode(){
	return root? root->minValueNode() : NULL;
}
void BST::displayMin(){
	Node* tmp = minValueNode();

	if (tmp)
		cout << "Minimum key pair : (" << tmp->key << ":" << tmp->data << ")\n";
	else
		cout << "BST is Empty!\n";
}
void BST::deleteNode(int key){
	if (!containsKey(key))
		throw invalid_argument("Key already isn't there!");

	Node* removedNode;

	//root needs to be deleted.
	if (root->key == key){ 
		Node tmpRoot(0,""); //dummy root
		tmpRoot.left = root;
		removedNode = root->deleteNode(key,&tmpRoot);
		root = tmpRoot.left;

	}else{
		removedNode = root->deleteNode(key,NULL);
	}

	//remove the returned node.
	if (removedNode)
		delete removedNode;
}
int  BST::getMaxHeight(){
	return root? root->getH() - 1 : 0; //height = degree - 1.
}
void BST::buildFromArray(int* keys,string* values,int n){
	for (int i = 0; i < n; i++)
		set(keys[i],values[i]);
}

BST::~BST(){
	destroy(root);
}

void BST::destroy(Node* node){
	if (!node)
		return;

	destroy(node->left);
	destroy(node->right);
	delete node;
}