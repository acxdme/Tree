/*
Time complexity : O(N)
Space complexity : O(1) ignoring recursion stack.
My approach :
*/
int traverse(Node* root, int& answer)
{
    if(root == NULL ) return INT_MAX;
    if(!root->left and !root->right) return root->data;
    
    int l = traverse(root->left,answer);
    int r = traverse(root->right,answer);
    
    answer = max(answer,max(root->data - l,root->data - r));
    
    return min(root->data,min(l,r));
}
int maxDiff(Node* root)
{
    int answer = INT_MIN;

    traverse(root,answer);
    
    return answer;
}
