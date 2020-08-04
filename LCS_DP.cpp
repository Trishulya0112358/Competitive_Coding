#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	int l1,l2;
	cin>>l1>>l2;
	string S1,S2;
	cin>>S1>>S2;
	
	vector <vector <int>> A,Cache;
	
	
	for(int i=0;i<l1;i++)
	{
	    vector <int> temp;
	    vector <int> tempc;
	    
	    for(int j=0;j<l2;j++)
	    {
	        if(S1[i]==S2[j]){temp.push_back(1);}
	        else{temp.push_back(0);}
	        tempc.push_back(-1);
	    }
	    A.push_back(temp);
	    Cache.push_back(tempc);
	}
	
	
    for(int itr1=l1-1;itr1>=0;itr1--)
    {
        for(int itr2=l2-1;itr2>=0;itr2--)
        {
            if(itr1==l1-1 && itr2==l2-1){Cache[itr1][itr2]=A[itr1][itr2];continue;}
            int cmp1=0,cmp2=0,cmp3=0;
            if(itr1+1<l1){cmp1=Cache[itr1+1][itr2];}
            if(itr2+1<l2){cmp2=Cache[itr1][itr2+1];}
            if(itr1+1<l1 && itr2+1<l2){cmp3=Cache[itr1+1][itr2+1];}
            
            if(A[itr1][itr2]==0)
            {
                Cache[itr1][itr2]=max(cmp1,cmp2);
            }
            else
            {
                int t1=max(cmp1,cmp2);
                int t2=A[itr1][itr2]+cmp3;
                Cache[itr1][itr2]=max(t1,t2);
            }
            
            
        }
    }
    
    cout<<Cache[0][0]<<endl;
//   	for(int i=0;i<l1;i++)
// 	{
// 	    for(int j=0;j<l2;j++)
// 	    {
// 	        cout<<Cache[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
   
	}
	return 0;
}
