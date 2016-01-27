#include <bits/stdc++.h>
using namespace std;

Node::Node(int key,string data){
	this->key = key;
	this->data = data;
	left = right = NULL;
}
void Node::insert(int x,string s){
	if (x < key){
		if (!left)
			left = new Node(x,s);
		else
			left->insert(x,s);
	}else{
		if (!right)
			right = new Node(x,s);
		else
			right->insert(x,s);
	}
}
bool Node::containsKey(int key){
	if (this->key == key)
		return true;

	if (key < this->key){
		if (left && left->containsKey(key))
			return true;
	}else{
		if (right && right->containsKey(key))
			return true;
	}

	return false;
}
string Node::lookUp(int key){
	if (this->key == key)
		return data;

	if (key < this->key){
		if (left)
			return left->lookUp(key);
	}else{
		if (right)
			return right->lookUp(key);
	}
}
void Node::modify(int key,string data){
	if (this->key == key){
		this->data = data;
		return;
	}

	if (key < this->key){
		if (left)
			left->modify(key,data);
	}else{
		if (right)
			right->modify(key,data);
	}
}
void Node::inOrder(){
	char c = '"';

	printf("[");
	if (left){
		left->inOrder();
		printf(", ");
	}

	printf("%d:%c%s%c",key,c,data.c_str(),c);

	if (right){
		printf(", ");
		right->inOrder();
	}
	printf("]");
}
void Node::preOrder(){
	char c = '"';

	printf("[");
	printf("%d:%c%s%c",key,c,data.c_str(),c);
	
	if (left){
		printf(", ");
		left->preOrder();
	}

	if (right){
		printf(", ");
		right->preOrder();
	}
	printf("]");
}
void Node::postOrder(){
	char c = '"';

	printf("[");
	if (left){
		left->postOrder();
		printf(", ");
	}

	if (right){
		right->postOrder();
		printf(", ");
	}

	printf("%d:%c%s%c",key,c,data.c_str(),c);
	printf("]");
}
int Node::countNodes(){
	int ans = 1;
	if (left)
		ans += left->countNodes();
	if (right)
		ans += right->countNodes();
	
	return ans;
}
Node* Node::minValueNode(){
	return left? left->minValueNode() : this;
}
Node* Node::maxValueNode(){
	return right? right->maxValueNode() : this;
}
Node* Node::deleteNode(int key,Node* parent){
	if (key > this->key)
		return right? right->deleteNode(key,this) : right;

	else if (key < this->key)
		return left? left->deleteNode(key,this) : left;

	else{ //got it
		if (left && right){//if it has 2 children
			Node* tmp = right->minValueNode();
			this->key = tmp->key;
			this->data = tmp->data;
			return right->deleteNode(this->key,this);

		//if it has only 1 child, replace it with it.
		} else if (parent->left == this){
			parent->left = (left) ? left : right;
			return this;

		}else if (parent->right == this){
			parent->right = (left) ? left : right;
			return this;
		}
	}
}
int Node::getH(){
	int l = 0,r = 0;

	if (left)
		l = left->getH();

	if (right)
		r = right->getH();

	return 1 + max(l,r);
}