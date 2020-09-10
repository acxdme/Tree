/*
Time complexity : O(Nlogn)
Space complexity : No extra space required except for making the tree.
My approach : Carefully observe the given postOrder and inOrder arrays.
*/
Node *buildTree_rec(int in[],int i1,int i2,int post[],int p1,int p2)
{
    if(i1 >=i2 or p1 >=p2)
    return NULL;
    Node* root = new Node(post[p2-1]);
    // int it=0;
    // for(int i=i1;i<i2;i++)
    // {
    //     if(in[i]==post[p2-1])
    //     {
    //         it=i;
    //         break;
    //     }
    // }
     int *it ;
     it = find(in+i1,in+i2,post[p2-1]);
     
    int diff =  it-(in+i1);
    root->left=buildTree_rec(in,i1,i1+diff,post,p1,p1+diff);
    root->right = buildTree_rec(in,i1+diff+1,i2,post,p1+diff,p2-1);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
     if(n==0) return nullptr;
     
     return buildTree_rec(in,0,n,post,0,n);
}
