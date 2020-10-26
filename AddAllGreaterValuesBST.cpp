/*
Time complexity : O(n)
Space complexity : O(1) ignoring recursion stack.
My approach : Use traverse the tree also acculate and modify the sum of the nodes values.
*/
void modifyBSTUtil(Node* root, int& sum) 
{ 

    if (root == NULL) 
        return; 
  
    modifyBSTUtil(root->right, sum); 
  
 
    sum = sum + root->data; 
    root->data = sum; 
  
    modifyBSTUtil(root->left, sum); 
} 
  

Node* modify(Node* root) 
{ 
    int sum = 0; 
    modifyBSTUtil(root, sum); 
    
    return root;
} 
