#include<bits/stdc++.h>
using namespace std;

int getsum(int *st,int ss,int se,int qs,int qe,int si)
    {
        if(qs<=ss && qe>=se){return st[si];}
        if(qs>se || qe<ss){return 0;}
        
        int mid=(ss+se)/2;
        return getsum(st,ss,mid,qs,qe,2*si+1)+getsum(st,mid+1,se,qs,qe,2*si+2);
        
    }

int cutil(int arr[],int *st,int ss,int se,int si)
    {
        if(ss==se)
        {
            st[si]=arr[ss];
            return st[si];    
        }
        
        int mid=(ss+se)/2;
        
        st[si]=cutil(arr,st,ss,mid,2*si+1)+cutil(arr,st,mid+1,se,2*si+2);
        return st[si];
        
    }

int * constST(int arr[],int n)
{
    int size=pow(2,log2(n)+4)-1;
    int *st=new int[size];
    
    cutil(arr,st,0,n-1,0);
    return st;
}

int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	int N;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++)
	{
	    cin>>A[i];
	}
	
	int *ST=constST(A,N);
	int Q;
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
	    int l,r;
	    cin>>l>>r;
	    cout<<getsum(ST,0,N-1,l-1,r-1,0)<<" ";
	}
	cout<<endl;
	}
	return 0;
}
