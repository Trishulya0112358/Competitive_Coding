#include<bits/stdc++.h>
using namespace std;

int main()
{

int n;
cin>>n;

int A[n];
int B[1000000]={};

for(int i=0;i<n;i++)
{
cin>>A[i];
B[A[i]]--;
}

int Ans[n+10];

int i=0;
while(B[i]!=0)
{
i++;
}


for(int j=0;j<n;j++)
{

if(j>0 && B[A[j-1]]==0)
{
Ans[j]=A[j-1];
B[A[j-1]]++;
}
else{
Ans[j]=i;
B[i]++;
}

while(B[i]!=0)
{
i++;
}
B[A[j]]++;

/*
for(int itr=0;itr<n;itr++)
{
cout<<B[itr]<<" ";
}
cout<<endl;
*/

}

for(int itr=0;itr<n;itr++)
{
cout<<Ans[itr]<<" ";
}
cout<<endl;

/*
for(int itr=0;itr<n;itr++)
{
cout<<Ans[itr]<<" ";
}
cout<<endl;
*/
return 0;
}
