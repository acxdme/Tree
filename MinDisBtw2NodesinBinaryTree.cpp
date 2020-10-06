/*
Time complexity : O(N)
Space complexity : O(1) ,ignoring recursion stack.
My approach : Use of formula->  node1's distance from root + node2's distance from root - 2 * LCA's distance from root.
*/

int dis(Node* root, int x)
 {
    
      if (root == NULL) 
      return -1; 
  
    // Initialize distance 
    int dist = -1; 
  

    if ((root->data == x) || (dist = dis(root->left, x)) >= 0 || (dist = dis(root->right, x)) >= 0) 
        return dist + 1; 
  
    return dist; 
   
 }
  Node* lca(Node* root,int a,int b)
  {
      if(root==NULL) return NULL;
      if(root->data==a or root->data==b) return root;
      
      Node* l= lca(root->left,a,b);
      Node* r = lca (root->right,a,b);
      
      if(l!=NULL and r!=NULL) return root;
      
      return  l==NULL? r: l;
  }
int findDist(Node* root, int a, int b)
{
    
    int i=dis(root,a);
    int j= dis(root,b);
     Node* k=lca(root,a,b);
    int l= dis(root,k->data);
    // cout<<i<<" "<<j<<" "<<l<<" "<<endl;
    return (i+j-2*l);
    
}
