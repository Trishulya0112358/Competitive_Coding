/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    if(i.first!=j.first){return i.first>j.first;}
    return i.second < j.second;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,K;
        cin>>N>>K;
        int A[N];
        
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        
        int B[N][32];
        for(int i=0;i<N;i++)
        {
            for (int j = 31;j >= 0; j--) 
            { 
                int k = A[i] >> j; 
                if (k & 1){B[i][j]=1;} 
                else{B[i][j]=0;} 
            }         
        }
        // for(int i=0;i<N;i++)
        // {
        //     for(int j=0;j<32;j++)
        //     {
        //         cout<<B[i][j];
        //     }
        //     cout<<endl;
        // }
        
        pair <int,int> C[32];
        
        for(int i=0;i<32;i++)
        {
            C[i].first=0;
            C[i].second=i;
        }
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<N;j++)
            {
                C[i].first+=pow(2,i)*B[j][i];
            }
        }
        
        // for(int i=0;i<32;i++)
        // {
        //     cout<<C[i].first<<":"<<C[i].second<<" ";
        // }
        // cout<<endl;
        sort(C,C+32,compare);
        // for(int i=0;i<32;i++)
        // {
        //     cout<<C[i].first<<":"<<C[i].second<<" ";
        // }
        
        int X=0;
        for(int i=0;i<K;i++)
        {
            X+=pow(2,C[i].second);
        }
        cout<<X<<endl;
        
        
    }

    return 0;
}
