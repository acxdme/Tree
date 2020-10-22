/*
Time complexity : O(N)
Space complexity :
My approach :
*/

int helper(struct Node *root , int &res) 
{ 
    
    if (root==NULL) return 0; 
    if (!root->left && !root->right) return root->data; 
  
   
    int ls = helper(root->left, res); 
    int rs = helper(root->right, res); 
   
    if (root->left && root->right) 
    { 
        
        res = max(res, ls + rs + root->data); 
  
        
        return max(ls, rs) + root->data; 
    } 
  
    return (root->left==false)? rs + root->data :   ls + root->data;
    
} 

int maxPathSum(Node* root)
{ 
    if(root==NULL) return 0;
     int result=INT_MIN;
     helper(root,result);
     
     return result;
    
   
}
