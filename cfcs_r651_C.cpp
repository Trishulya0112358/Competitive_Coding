#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
	
	if(n<=3)
		return true;	
		
  int l=sqrt(n);
    // Check from 2 to n-1 
    for (int i = 2; i < l+10; i++) 
        if (i<n && n % i == 0) 
            return false; 
  
    return true; 
} 


int main()
{
int T;
cin>>T;
while(T--)
{
int n;
cin>>n;

if(n==1){cout<<"FastestFinger"<<endl;continue;}
if(n==2){cout<<"Ashishgup"<<endl;continue;}

if(n%2==1){cout<<"Ashishgup"<<endl;continue;}

int logv=log2(n);
if(pow(2,logv)==n){cout<<"FastestFinger"<<endl;continue;}

if(n%4==0){cout<<"Ashishgup"<<endl;continue;}

bool f=isPrime(n/2);
if(f)
{cout<<"FastestFinger"<<endl;continue;}
else
{cout<<"Ashishgup"<<endl;continue;}

}



return 0;
}
