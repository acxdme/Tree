/*
Time complexity  : O(N)
Space complexity : O(1) not considering the call stack.
My approach : So, i have used recursion , if the root node is null return NULL (Base case), if root itself is one of the two nodes whose LCA is to be found we return root,otherwise we
      recursively traverse to the left of tree and  to the right of the tree. if the value obtained by l and r are not null this means root is the LCA so we return the root.
      Lastly if l is null and r is not null we return r and if r is null and l is not null we return l.
*/

Node* lca(Node* root ,int n1 ,int n2 )
{
   if(root==NULL) return root;
   if(root->data==n1 or root->data==n2) return root;
   
   Node* l= lca(root->left,n1,n2);
   Node* r= lca(root->right,n1,n2);
   
   if(l!=NULL and r!=NULL) return root;
   
   
   return l==NULL? r: l;
   
   
}


