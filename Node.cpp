#include <bits/stdc++.h>
using namespace std;

Node::Node(int key,string data){
	this->key = key;
	this->data = data;
	left = right = NULL;
}
void Node::insert(int x,string s){
	if (x < key){
		if (left == NULL)
			left = new Node(x,s);
		else
			left->insert(x,s);
	}else{
		if (right == NULL)
			right = new Node(x,s);
		else
			right->insert(x,s);
	}
}
bool Node::containsKey(int key){
	if (this->key == key)
		return true;

	if (key < this->key){
		if (left != NULL && left->containsKey(key))
			return true;
	}else{
		if (right != NULL && right->containsKey(key))
			return true;
	}

	return false;
}
string Node::lookUp(int key){
	if (this->key == key)
		return data;

	if (key < this->key){
		if (left != NULL)
			return left->lookUp(key);
	}else{
		if (right != NULL)
			return right->lookUp(key);
	}
}
void Node::modify(int key,string data){
	if (this->key == key){
		this->data = data;
		return;
	}

	if (key < this->key){
		if (left != NULL)
			left->modify(key,data);
	}else{
		if (right != NULL)
			right->modify(key,data);
	}
}
void Node::inOrder(){
	char c = '"';

	printf("[");
	if (left != NULL){
		left->inOrder();
		printf(", ");
	}

	printf("%d:%c%s%c",key,c,data.c_str(),c);

	if (right != NULL){
		printf(", ");
		right->inOrder();
	}
	printf("]");
}
void Node::preOrder(){
	char c = '"';

	printf("[");
	printf("%d:%c%s%c",key,c,data.c_str(),c);
	
	if (left != NULL){
		printf(", ");
		left->preOrder();
	}

	if (right != NULL){
		printf(", ");
		right->preOrder();
	}
	printf("]");
}
void Node::postOrder(){
	char c = '"';

	printf("[");
	if (left != NULL){
		left->postOrder();
		printf(", ");
	}

	if (right != NULL){
		right->postOrder();
		printf(", ");
	}

	printf("%d:%c%s%c",key,c,data.c_str(),c);
	printf("]");
}
int Node::countNodes(){
	int ans = 1;
	if (left != NULL)
		ans += left->countNodes();
	if (right != NULL)
		ans += right->countNodes();
	
	return ans;
}
Node* Node::minValueNode(){
	if (left == NULL)
		return this;
	else
		return left->minValueNode();
}
Node* Node::maxValueNode(){
	if (right == NULL)
		return this;
	else
		return right->maxValueNode();
}
Node* Node::deleteNode(int key,Node* parent){
	if (key > this->key)
		if (right != NULL)
			return right->deleteNode(key,this);
		else
			return NULL;

	else if (key < this->key)
		if (left != NULL)
			left->deleteNode(key,this);
		else
			return NULL;

	else{ //got it
		if (left != NULL && right != NULL){//if it has 2 children
			Node* tmp = right->minValueNode();
			this->key = tmp->key;
			this->data = tmp->data;
			return right->deleteNode(this->key,this);

		//if it has only 1 child, replace it with it.
		} else if (parent->left == this){
			parent->left = (left != NULL) ? left : right;
			return this;

		}else if (parent->right == this){
			parent->right = (left != NULL) ? left : right;
			return this;
		}
	}
}
int Node::getH(){
	int l = 0,r = 0;

	if (left != NULL)
		l = left->getH();

	if (right != NULL)
		r = right->getH();

	return 1 + max(l,r);
}