## Trees
Solving three different problems involving trees
# Post Order Traversal
Given the root of the tree, returns a list containing the postorder traversal of the tree
- in **Main()**, build a tree and call **postOrder()** to print postorder traversal

# Merge BST
Given two binary search trees, returns the elements of both trees sorted in increasing order
- in **Main()** create two BSTs and call **Merge()** to print the sorted elements of both trees
- **Merge()** takes the root of both BSTs and returns the BST in a sorted order. Does this by merging the two trees, and then outputs an array of integers denoting the node values using breadth-first traversal

# BST to AVL
Given a binary search tree (may be unbalanced), convert it to an AVL tree with minimum possible height
- in **Main()** create a BST and output if it is balanced or not. If it is not, convert it into an AVL tree and output an array of integers denoting the node values of the AVL tree using preorder traversal. If it is balanced, output the list containing the preorder traversal of the tree
- Use **isBalanced()** to determine if the tree is balanced. Takes root node as parameter and returns a boolean value to show if it is balanced
