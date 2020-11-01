/*
Time complexity : O(N) 
Space complexity : O(1) , ignoring recursive stack.
My appraoch :  bottom down build up the sum.
Watch this approach : https://www.youtube.com/watch?v=FxgpgxH2k8o&ab_channel=CodingSimplified
*/
int pathsumHelper(Node* root, int& sum)
{
    if(root == NULL) return 0;
    if(!root->left and !root->right ) return root->data;
    
    int l = pathsumHelper(root->left,sum);
    
    int r = pathsumHelper(root->right,sum);
    
    if( root->left and root->right )
    {
        if( root->data + l + r > sum)
         sum = root->data + l + r;
         
         return   max(l,r) + root->data  ;
    }
    
     return  (!root->left)? r + root->data :  l + root->data;
}

int maxPathSum(Node* root)
{ 
    int sum = INT_MIN;
    if(root == NULL) return sum;
    pathsumHelper(root,sum);
    return sum;
}
