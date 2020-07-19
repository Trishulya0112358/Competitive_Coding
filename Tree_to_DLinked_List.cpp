struct Node* rec(Node *root,Node *prev)
{
    if(root==NULL){return prev;}
    struct Node *cprev=rec(root->left,prev);
    if(root!=cprev)
    {
    struct Node *nno=new Node();
    nno->data=root->data;
    cprev->right=nno;
    nno->left=cprev;
    cprev=nno;
    }
    cprev=rec(root->right,cprev);
    
    return cprev;
}
Node * bToDLL(Node *root)
{
    struct Node *temp=root;
    while(temp->left!=NULL){temp=temp->left;}
    
    struct Node *head=new Node();
    head->data=temp->data;
    struct Node *prev=head;
    
    rec(root,prev);
    temp=head;
    head=head->right;
    head->left=NULL;
    return head;
    // your code here
}
