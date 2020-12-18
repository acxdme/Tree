/*
Time complexity : O(H)
Space complexity : O(1) ignoring call stack.
My approach : the LCA lies between the value of n1 and n2 , if the value is greater than both then move to the left else move right.
*/

Node* LCA(Node *root, int n1, int n2)
{
   if(root==NULL) return NULL;
   
   if(root->data > n1 and root->data > n2)  
     return LCA(root->left,n1,n2);
    
   if(root->data < n1 and root->data < n2)
      return LCA(root->right,n1,n2);
     
 
   
   return root;
}
