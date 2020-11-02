/*
 Time complexity : O(N)
 Space complexity : O(N) 
 MY approach : for each path we take during the recursive calling from root to leaf , store that path in the path vector and when we reach a leaf node check
               that pathlength-k-1 >=0 and visited of pathlength-k-1== false  ,if true increase the cost and mark this as false .
              
*/

void dfs(Node* root, vector<int> path ,bool visited[],int& count, int k,int pathlength)
{
    if(root==NULL) return ;
    
    path[pathlength] = root->data;
    visited[pathlength]=false;
    pathlength++;
    
     if (root->left == NULL && root->right == NULL && pathlength - k - 1 >= 0 && visited[pathlength - k - 1] == false)
     {
         count++;
         visited[pathlength-k-1]=true;
         return;
     }
     dfs(root->left,path,visited,count,k,pathlength);
     dfs(root->right,path,visited,count,k,pathlength);
}
int printKDistantfromLeaf(Node* root, int k)
{

    vector<int> path (1000);
	int count=0;
	bool visited[100000];
	memset(visited,false,sizeof(visited));
	dfs(root,path,visited,count,k,0);
	return count;
	
}
