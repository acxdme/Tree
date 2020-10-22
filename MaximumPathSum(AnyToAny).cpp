/*
Time complexity :
Space complexity :
My approach :  (Go watch this-> https://www.youtube.com/watch?v=Osz-Vwer6rw&list=PL_z_8CaSLPWfxJPz2-YKqL9gXWdgrhvdn&index=4&ab_channel=AdityaVerma)
*/

class Solution 
{
public:
    
    int helper(TreeNode* root,int& result)
    {
        if(root==NULL) return 0;
        
        int l = helper(root->left,result);
        int r = helper(root->right,result);
        
        int temp = max(max(l,r)+root->val,root->val);
        
        int answer = max(temp,l+r+root->val);
        
        result = max(answer,result);
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int result = INT_MIN;
        helper(root,result);
        
        return result;
        
    }
};
