#include<bits/stdc++.h>
using namespace std;

int visited[10][10];


int rec(string s,vector <char> B[],int N,int M,int x,int y,int ind,int l)
{
    int f=0;
    if(x-1>=0 && visited[x-1][y]==0 && s[ind]==B[x-1][y])
    {
        visited[x-1][y]=1;
        if(ind==l-1){return 1;}
        f=rec(s,B,N,M,x-1,y,ind+1,l);
    if(f==1){return 1;}
    else{visited[x-1][y]=0;}    
    }
    
    if(x-1>=0 && y-1>=0 && s[ind]==B[x-1][y-1] && visited[x-1][y-1]==0)
    {
        visited[x-1][y-1]=1;
        if(ind==l-1){return 1;}
        f=rec(s,B,N,M,x-1,y-1,ind+1,l);
    if(f==1){return 1;}
    else{visited[x-1][y-1]=0;}
    }
    
    if(y-1>=0 && s[ind]==B[x][y-1] && visited[x][y-1]==0)
    {
        visited[x][y-1]=1;
        if(ind==l-1){return 1;}
        f=rec(s,B,N,M,x,y-1,ind+1,l);
    if(f==1){return 1;}
    else{visited[x][y-1]=0;}
    }
    if(x+1<N && y-1>=0 && s[ind]==B[x+1][y-1] && visited[x+1][y-1]==0)
    {
        visited[x+1][y-1]=1;
        if(ind==l-1){return 1;}
        f=rec(s,B,N,M,x+1,y-1,ind+1,l);
    if(f==1){return 1;}
    else{visited[x+1][y-1]=0;}
    }
    if(x+1<N && s[ind]==B[x+1][y] && visited[x+1][y]==0)
    {
        visited[x+1][y]=1;
        if(ind==l-1){return 1;}
        f=rec(s,B,N,M,x+1,y,ind+1,l);
    if(f==1){return 1;}
    else{visited[x+1][y]=0;}
    }
    if(x+1<N && y+1<M && s[ind]==B[x+1][y+1] && visited[x+1][y+1]==0)
    {
        visited[x+1][y+1]=1;
        if(ind==l-1){return 1;}
        f=rec(s,B,N,M,x+1,y+1,ind+1,l);
    if(f==1){return 1;}
    else{visited[x+1][y+1]=0;}
    }
    if(y+1<M && s[ind]==B[x][y+1] && visited[x][y+1]==0)
    {
        visited[x][y+1]=1;
        if(ind==l-1){return 1;}
        f=rec(s,B,N,M,x,y+1,ind+1,l);
    if(f==1){return 1;}
    else{visited[x][y+1]=0;}
    }
    if(x-1>=0 && y+1<M && s[ind]==B[x-1][y+1] && visited[x-1][y+1]==0)
    {
        visited[x-1][y+1]=1;
        if(ind==l-1){return 1;}
        f=rec(s,B,N,M,x-1,y+1,ind+1,l);
    if(f==1){return 1;}
    else{visited[x-1][y+1]=0;}
    }
    return 0;
    
}


void clv()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            visited[i][j]=0;
        }
    }
}

int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	clv();
	int x;
	cin>>x;
	string S[x];
	for(int i=0;i<x;i++)
	{
	    cin>>S[i];
	}
	sort(S,S+x);
	int N,M;
	cin>>N>>M;
 	vector <char> B[N];
	for(int i=0;i<N;i++)
	{
	    for(int j=0;j<M;j++)
	    {
	        char temp;
	        cin>>temp;
	        B[i].push_back(temp);
	    }
	}
	
	int C[x];
	
	for(int i=0;i<x;i++)
	{
	    int tx=0,ty=0,f=0;
	    for(int io=0;io<N;io++)
	    {
	        for(int oo=0;oo<M;oo++)
	        {
	            if(B[io][oo]==S[i][0])
	            {
	                if(S[i].length()==1){f=1;}
	                else{
	                clv();
	                visited[io][oo]=1;
	                f=rec(S[i],B,N,M,io,oo,1,S[i].length());
	                }
	            }
	            if(f==1){break;}
	        }
	            if(f==1){break;}
	    }
	    
	    C[i]=f;
	}
	int t=0;
    for(int itr=0;itr<x;itr++)
    {
        if(C[itr]!=0){t=1;break;}
    }
    if(t==0){cout<<"-1";}
    else{
    vector <string> Ans;
    for(int itr=0;itr<x;itr++)
    {
        if(C[itr]!=0 && !count(Ans.begin(),Ans.end(),S[itr]))
        {
            Ans.push_back(S[itr]);
        }
    }
    sort(Ans.begin(),Ans.end());
    for(int vei=0;vei<Ans.size();vei++)
    {
        cout<<Ans[vei]<<" ";
    }
    }
    cout<<endl;
	}
	return 0;
}
