/*
Time complexity : O(N)
Space complexity : O(1) , ignoring recursion stack.
My approach :  (gfg) https://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
*/


Node* makeTree(int n, int pre[], char preLN[],int& index )
{
    int k = index;
    if( k==n) return NULL;
    
    Node* temp =  new Node(pre[k]);
    index++;
    
     if(preLN[k]=='N' )
    {
       temp->left = makeTree(n,pre,preLN,index);
       temp->right = makeTree(n,pre,preLN,index);
    }
    
    return temp;  
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
     int  index = 0;
     
     return makeTree(n, pre, preLN,index);
}
