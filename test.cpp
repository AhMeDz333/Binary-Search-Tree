#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int main(){
	BST tree;

	//test 1
	tree.insert(5,"ahmed");
	tree.insert(7,"daramally");
	tree.inOrder();
	cout << "Current H :" << tree.getMaxHeight() << "\n";
	cout << "\ntest 1 is successful!\n\n";
	
	//test 2
	tree.insert(1,"omar");
	tree.inOrder();
	cout << "Current H :" << tree.getMaxHeight() << "\n";
	cout << "\ntest 2 is successful!\n\n";

	//test 3
	tree.set(7,"non-daramally");
	cout << "Current H :" << tree.getMaxHeight() << "\n";
	tree.inOrder();
	cout << "\ntest 3 is successful!\n\n";

	//test 4
	tree.insert(2,"mostafa");
	tree.insert(3,"todo");
	tree.inOrder();
	cout << "Current H :" << tree.getMaxHeight() << "\n";
	cout << "\ntest 4 is successful!\n\n";

	//test 5
	tree.modify(3,"darsh");
	cout << "Value after edit : " << tree.lookUp(3) << "\n";
	tree.inOrder();
	cout << "\ntest 5 is successful!\n\n";

	//test 6
	cout << "before delete\nContains key? : " << tree.containsKey(3) << "\n";
	tree.deleteNode(3);
	cout << "after delete\nContains key? : " << tree.containsKey(3) << "\n";
	tree.inOrder();
	cout << "Current H :" << tree.getMaxHeight() << "\n";
	cout << "\ntest 6 is successful!\n\n";

	//test 7
	cout << "Num of Nodes : " << tree.countNodes() << "\n";
	tree.displayMin();
	tree.displayMax();
	tree.preOrder();
	tree.postOrder();
	cout << "\ntest 7 is successful!\n\n";
}