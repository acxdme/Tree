/*
 A binary tree is a valid BST when the left subtree is lesser in value to the node and the right subtree is greater in value to the node.
 The simple method which checks that the right child is smaller than root and left child is larger than root is wrong since ,we have to check the whole subtee and not just it's
 immediate children.
 The method where we compare  the min and max  values (updated with respect of the whole tree) with the nodes is efficient and good but the range of min and max can create problems.
 
 So the next method is to make a In-order traversal of the tree and store the oreder in an array ,  the array must be in ascending order for a tree to be BST.
 
*/
