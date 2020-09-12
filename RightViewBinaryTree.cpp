/*
Time complexity : O(N)
Space complexity : O(h)
My approach : rightmost node at each level  is the right view.
*/

void leftView_helper(Node* root, int level, int &lastlevel)
{
    if(root==NULL)
       return ;
       
     if(level > lastlevel)
     {
         
         cout<<root->data<<" ";
         lastlevel= level;
     }
     
     leftView_helper(root->right,level+1,lastlevel);
     leftView_helper(root->left,level+1,lastlevel);
     
     
}
void rightView(Node *root)
{
   int last_level =0;
   leftView_helper(root,1,last_level);
}
