/*
Time complexity : O(N)
Space complexity:  O(N) , for using queue in bfs method
My approach : traverse level-order wise and adjust the nextRight pointer for everyNode to the next node in the level order except for the last node for a particular level.
*/

void bfs_connect(Node* p)
{
    queue<Node*> q;
    q.push(p);
    while(!q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            Node* temp = q.front();
            q.pop();
            if( i== n-1)
            {
                temp->nextRight = NULL;
            }
            else
            {
            if(q.size()>0)
             temp->nextRight = q.front();
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void connect(Node *p)
{
    if(p==NULL) return ;
    bfs_connect(p);    
}

