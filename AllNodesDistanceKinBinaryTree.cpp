/*
Time complexity : 
Space complexity :
My approach : maintain a visited array of nodes and a child,parent map of the nodes perform level order traversal k times to find the nodes .
*/

class Solution {
public:
    
    void child_parent ( unordered_map<TreeNode*,TreeNode*>& mp, TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n =q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right)
                {
                    mp[temp->right] = temp;
                    q.push(temp->right);
                }
                if(temp->left)
                {
                    mp[temp->left] = temp;
                    q.push(temp->left);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> answer;
        if(root == NULL) return answer;
        unordered_map<TreeNode*,TreeNode*> mp;
        child_parent(mp,root);
        
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, int> visited;
        
        while(!q.empty() and K>0)
        {
            K--;
            int n= q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] =1;
                if(temp->left and visited.find(temp->left)== visited.end())
                {
                    q.push(temp->left);
                    
                }
                if(temp->right and visited.find(temp->right)== visited.end())
                {
                    q.push(temp->right);
                }
                if(mp.find(temp)!= mp.end() and visited.find(mp[temp]) == visited.end())
                {
                    q.push(mp[temp]);
                }
            }
            
        }
        
        while(!q.empty())
        {
            TreeNode* temp1 = q.front();
            answer.push_back(temp1->val);
            q.pop();
        }
        
        return answer;
        
    }
};
