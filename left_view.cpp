// A wrapper over leftViewUtil()
int A[101];
int level[101];
int indexv=0;

void lvl(Node *root,int levelval)
{
    if(root==NULL){return;}
    int done=0;
    
    if(level[levelval+1]!=0)
    {
        if(root->left!=NULL){lvl(root->left,levelval+1);}
        else{
            if(root->right!=NULL){lvl(root->right,levelval+1);}
            else{return;}
        }
        return;
    }
    
    if(level[levelval+1]==0 && root->left!=NULL)
    {
        A[indexv]=root->left->data;
        indexv++;
        done=1;
        level[levelval+1]=1;
        lvl(root->left,levelval+1);
    }
    if(level[levelval+1]==0 && done!=1 && root->right!=NULL)
    {
        A[indexv]=root->right->data;
        indexv++;
        done=2;
        level[levelval+1]=1;
        lvl(root->right,levelval+1);
    }
    
    return;
    
}

void leftView(Node *root)
{
    if(root==NULL){return;}
    for(int i=0;i<101;i++)
    {
        A[i]=0;
        level[i]=0;
    }
    A[0]=root->data;
    level[0]=1;
    indexv=1;
    lvl(root,0);
    
    for(int i=0;i<indexv;i++)
    {
        cout<<A[i]<<" ";
    }
    
   // Your code here
}
