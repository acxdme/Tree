/*
::Optimized approach ::
Diameter of a tree can be calculated by only using the height function, because the diameter of a tree 
is nothing but maximum value of (left_height + right_height + 1) for each node. 
So we need to calculate this value (left_height + right_height + 1) for each node and update the result.

Time : O(N)
Space :O(n) is of call stack.
*/

/* Function to find height of a tree */
int height(Node* root, int& ans) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_height = height(root->left, ans); 
  
    int right_height = height(root->right, ans); 
  
    // update the answer, because diameter of a 
    // tree is nothing but maximum value of 
    // (left_height + right_height + 1) for each node 
    ans = max(ans, 1 + left_height + right_height); 
  
    return 1 + max(left_height, right_height); 
} 
  
/* Computes the diameter of binary tree with given root. */
int diameter(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; // This will store the final answer 
    int height_of_tree = height(root, ans); 
    return ans; 
} 


// another style of writing inspired by aditya verma
int helper(Node* root, int& result)
{ 
    if(root==NULL) return 0;
    
    int l = helper(root->left,result);
    int r = helper(root->right,result);
    
    int temp = 1+ max(l,r);
    
    int ans =  max(temp,1+l+r);
    
    result = max(ans,result);
    
    return temp;
}
int diameter(Node* node)
{
    int  result=INT_MIN;
    if(node==NULL) return 0;
    helper(node,result);
    
    return result;
}

