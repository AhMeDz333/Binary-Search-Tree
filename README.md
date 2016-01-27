#Binary Search Tree (Un-Balanced) implementation
*#using C++

This code is customized to meet specifications of a Data Structure course project.
It consists mainly of 2 classes, `BST` & `Node` each has it's `.cpp` code & `.h` header files, and then there is the `test.cpp` to provide some tests validating each method's functionality correctness.

###Features :

*Less code :
 used recursion & conditional operators whenever possible, to make the code more understandable & the amount of code less.

*Isolation :
 isolation of methods that shouldn't be directly used by the user as private methods (accessable by friend classes, however).

###Utility Methods

*Constructor :
 Initializes an empty BST.

*Destructor :
 Destroys the tree before the termination  of the program, to free memory.

*insert :
 Takes 2 parameters key and value, inserts them in a node of "(Key,Value)", it raises an invalid argument exception if a node already exists with the given key in the BST.

*containsKey :
 Tests whether a given parameter key is in the BST or not.

*lookUp :
 Returns the data associated with the given parameter key, if there's no such key in the BST, it raises an invalid argument exception.

*modify :
 Modifies the data associated with the given parameter key to equal the given parameter value, it raises an invalid argument exception if there's no such key in the BST.

*set :
 Sets the data associated with the given parameter key to equal to the given parameter value if the key exists, and inserts the pair of given parameters "(Key,Value)" if the key doesn't exist.

*inOrder :
 Prints the BST in "in-order" manner, using specific traversal order.

*preOrder :
 Prints the BST in "pre-order" manner, using specific traversal order.

*postOrder :
 Prints the BST in "post-order" manner, using specific traversal order.

*countNodes :
 Returns the total number of nodes in the BST.

*displayMax :
 Displays the maximum pair node in the BST, if sorted according to the key.

*displayMin :
 Displays the maximum pair node in the BST, if sorted according to the key.

*deleteNode :
 Deletes the node with the given parameter key, if there's no such key in the BST, it raises an invalid argument exception.

*getMaxHeight :
 Returns the maximum height of the BST, through the recursive formula -> `max(leftSubtreeDegree,rightSubtreeDegree)`.

*buildFromArray :
 Builds the BST pairs from 2 parallel arrays of keys & values (works as a bulk insert).
