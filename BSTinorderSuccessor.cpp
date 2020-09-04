/* 
Time complexity : O(h)
Space complexity : O(1)
(We have been given the root node and the target node whose inorder successor is to find )
Algorithtm :  

*/

//attempt-1 ( code can be much cleaner)

Node * inOrderSuccessor(Node *root, Node *x)
{
    if(root==NULL)
     return root;
    Node* curr = x;
    if(curr->right)
    {
     curr=curr->right;   
     while( curr and curr->left )
      curr= curr->left;
     return curr;
    }
    else
    {
        Node* succ= NULL;
        Node* anc =root;
        while(anc != curr)
        {
            if(curr->data < anc->data )
              {
                  succ = anc;
                  anc=anc->left;
                  
              }
            else
            {
                anc= anc->right;
            }
        }
        return succ;
    }
}
