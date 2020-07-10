#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *prev;
	Node *next;
	};


int main()
{

int t;
cin>>t;

while(t--)
{
int n;
cin>>n;

struct Node *head=new(Node);
struct Node *p=head;
p->prev=NULL;
p->next=NULL;
cin>>p->val;

for(int i=1;i<n;i++)
{
struct Node *temp=new(Node);
temp->prev=p;
p->next=temp;
temp->next=NULL;
cin>>temp->val;
p=temp;
}

p=head;
p=p->next;

while(p->next!=NULL)
{
int temp1=abs((p->next->val)-(p->val))+abs((p->val)-(p->prev->val));
int temp2=abs((p->next->val)-(p->prev->val));

if(temp2>=temp1)
{
p->prev->next=p->next;
p->next->prev=p->prev;
}

p=p->next;

}

int A[n],i=0;
p=head;
while(p!=NULL)
{
A[i]=p->val;
i++;
p=p->next;
}

cout<<i<<endl;
for(int itr=0;itr<i;itr++)
{
cout<<A[itr]<<" ";
}
cout<<endl;


}


return 0;
}
