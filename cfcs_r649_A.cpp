#include<bits/stdc++.h>
using namespace std;

int main()
{

int t;
cin>>t;

while(t--)
{
int n,x;
cin>>n>>x;

int A[n];
int sum=0;

for(int i=0;i<n;i++)
{
cin>>A[i];
sum+=A[i];
}

if(sum%x!=0)
{cout<<n<<endl;continue;}

int r=0,l=0;


for(int i=0;i<n;i++)
{
if(A[i]%x==0){l++;}
else{break;}
}

if(l==n){cout<<"-1"<<endl;continue;}

for(int i=n-1;i>=0;i--)
{
if(A[i]%x==0){r++;}
else{break;}
}


if(n-l>n-r){cout<<n-l-1<<endl;}
else{cout<<n-r-1<<endl;}


}


return 0;
}
