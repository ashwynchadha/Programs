Implementation of a Binary Search Tree ADT.
• The header file a3_binary_search_tree.hpp, which is included below, provides the
structure of the BinarySearchTree class with declarations of member functions.
• Implement all of the public member functions listed in binary_search_tree.hpp
and place them into binary_search_tree.cpp.
• Note that this tree does not have to be balanced.
The details of the header file a3_binary_search_tree.hpp are as follows:
• DataType defines the kind of data that the tree will contain. Being public, it can be
accessed directly as BinarySearchTree::DataType.
• Member variables:
1. Node: This is a structure declaration. Node contains following member variables:
Node(DataType newval): Sets the left and right children to NULL,
and initializes val.
val: Value of the node.
left: Pointer to the left node.
right: Pointer to the right node.
2. root_: Pointer to the root node of the tree.
3. size_: Number of nodes in the tree.

• Constructor and Destructor:
1. BinarySearchTree(): Default constructor to initialize the root.
2. ~BinarySearchTree(): Destructor of the class BinarySearchTree. It
deallocates the memory space allocated for the binary search tree.

• Constant member functions:
1. int size() const: Returns the number of nodes in the tree.
2. DataItem max() const: Returns the maximum value of a node in the tree.
You can assume that this function will never be called on an empty tree.
3. DataItem min() const: Returns the minimum value of a node in the tree.
You can assume that this function will never be called on an empty tree.
4. unsigned int depth() const: Returns the maximum depth of the tree. A
tree with only the root node has a depth of 0. You can assume that this function
will never be called on an empty tree.
5. void print() const: You can print the tree in whatever order you prefer.
However, methods such as in-order or level-order traversal could be the most
useful for debugging.
6. bool exists(DataType val) const: Returns true if a node with the
value val exists in the tree; otherwise, it returns false.

• Non-constant member functions:
1. bool insert(DataType val): Inserts the value val into the tree. Returns
false if val already exists in the tree, and true otherwise.
2. bool remove(DataType val): Removes the node with the value val from
the tree. Returns true if successful, and false otherwise.
