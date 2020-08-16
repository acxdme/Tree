/*
Time complexity : O(n) , each node of the binary tree is visited once
Space complexity : O(n) ,  linear space is used to maintain queue.
Algo: Create a queue of TreeNode* type and push the root node.
      while the queue is not empty do below
         iterate over the queue length ,pop the queue front and put its val in vector
         during iteration push the immediate children into queue.
      return the final answer as vector<vector<int>> answer.
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
       
        vector<vector<int>> answer;
         if(!root)
            return answer;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
           int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                TreeNode *p =q.front();
                  q.pop();
                v.push_back(p->val);
                if(p->left!=NULL)
                    q.push(p->left);
                if(p->right!=NULL)
                    q.push(p->right);
            }
            answer.push_back(v);
   
        }
        return answer;
    }
};
