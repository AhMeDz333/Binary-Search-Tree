#include <bits/stdc++.h>
using namespace std;

bool BST::containsKey(int key){
	if (root == NULL)
		return false;

	return root->containsKey(key);
}
string BST::lookUp(int key){
	if (!containsKey(key))
		throw invalid_argument("Key isn't there!");

	return root->lookUp(key);
}
void BST::insert(int key,string data){
	if (containsKey(key))
		throw invalid_argument("Key is already there!");

	if (root == NULL)
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
	if (root == NULL){
		cout << "BST is Empty!\n";
		return;
	}

	cout << "In-Order traversal result..\n";
	printf("[");
	root->inOrder();
	printf("]\n");
}
void BST::preOrder(){
	if (root == NULL){
		cout << "BST is Empty!\n";
		return;
	}

	cout << "Pre-Order traversal result..\n";
	printf("[");
	root->preOrder();
	printf("]\n");
}
void BST::postOrder(){
	if (root == NULL){
		cout << "BST is Empty!\n";
		return;
	}

	cout << "Post-Order traversal result..\n";
	printf("[");
	root->postOrder();
	printf("]\n");
}
int  BST::countNodes(){
	return root == NULL? 0 : root->countNodes();
}
Node* BST::maxValueNode(){
	return root == NULL? NULL : root->maxValueNode();
}
void BST::displayMax(){
	Node* tmp = maxValueNode();
	cout << "Maximum key pair : " << tmp->key << ":" << tmp->data << "\n";
}
Node* BST::minValueNode(){
	return root == NULL? NULL : root->minValueNode();
}
void BST::displayMin(){
	Node* tmp = minValueNode();
	cout << "Minimum key pair : " << tmp->key << ":" << tmp->data << "\n";
}
void BST::deleteNode(int key){
	if (!containsKey(key))
		throw invalid_argument("Key already isn't there!");

	Node* removedNode;
	if (root->key == key){ //root needs to be deleted.
		Node tmpRoot(0,""); //dummy root
		tmpRoot.left = root;
		removedNode = root->deleteNode(key,&tmpRoot);
		root = tmpRoot.left;
		if (removedNode != NULL)
			delete removedNode;

	}else{
		removedNode = root->deleteNode(key,NULL);
	}

	//remove the returned node.
	if (removedNode != NULL)
		delete removedNode;
}
int  BST::getMaxHeight(){
	if (root == NULL)
		return 0;
	return root->getH() - 1; //height = degree - 1
}
void BST::buildFromArray(int* keys,string* values,int n){
	for (int i = 0; i < n; i++)
		set(keys[i],values[i]);
}

BST::~BST(){
	destroy(root);
}

void BST::destroy(Node* node){
	if (node == NULL)
		return;

	destroy(node->left);
	destroy(node->right);
	delete node;
}