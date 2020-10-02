/*
Time complexity : O(N^2)
Space complexity : O(1) is we dont count the space taken up by the call stack.
My approach : Starting from every node of the Original node , check if  both trees are identical or not.
*/

bool isIdentical(Node* t ,Node* s)
{
    if(t==NULL and s==NULL) return true;
    if(t==NULL or s==NULL) return false;
    
     return (t->data==s->data and isIdentical(t->left,s->left) and isIdentical(t->right,s->right));
}
bool isSubTree(Node* T, Node* S) {
   if(S==NULL) return true;
   if(T==NULL ) return false;
   
     
     if(isIdentical(T,S)) 
     return true;
    
    return isSubTree(T->left,S)|| isSubTree(T->right,S) ;
    
}
