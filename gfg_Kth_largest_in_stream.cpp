#include<bits/stdc++.h>
using namespace std;

struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i+1);}
    int right(int i){return (2*i+2);}
};

int MinHeap::extractMin() {
    if(heap_size==0){return -1;}
    int tmp=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    int ind=0;
    while(1)
    {
        if(left(ind)<heap_size && right(ind)<heap_size)
        {
        if(harr[ind]<harr[left(ind)] && harr[ind]<harr[right(ind)]){break;}
        int smallest=ind;
        if(harr[ind]>harr[left(ind)])
        {
            smallest=left(ind);
        }
        if(harr[smallest]>harr[right(ind)])
        {
            smallest=right(ind);
        }
        if(smallest==ind){break;}
        int temp=harr[ind];
        harr[ind]=harr[smallest];
        harr[smallest]=temp;
        ind=smallest;
        }
        else
        {
            if(left(ind)<heap_size)
            {
                if(harr[ind]>harr[left(ind)])
                {
                    int temp=harr[ind];
                    harr[ind]=harr[left(ind)];
                    harr[left(ind)]=temp;
                }
                break;
            }
            else{break;}
        }    
    }
    return tmp;
}
void MinHeap::deleteKey(int i) {
    if(i>=heap_size){return;}
    harr[i]=-INT_MAX;
    int ind=i;
    while(ind>0 && harr[ind]<harr[parent(ind)])
    {
        int temp=harr[ind];
        harr[ind]=harr[parent(ind)];
        harr[parent(ind)]=temp;
        ind=parent(ind);
    }
    extractMin();
    return;
}
void MinHeap::insertKey(int k) {
    heap_size++;
    harr[heap_size-1]=k;
    int ind=heap_size-1;
    while(ind>0 && harr[ind]<harr[parent(ind)])
    {
        int temp=harr[ind];
        harr[ind]=harr[parent(ind)];
        harr[parent(ind)]=temp;
        ind=parent(ind);
    }
    return;
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	int K,N;
	cin>>K>>N;
	if(K>1)
	{
	MinHeap h(N);
	MinHeap h2(K);
	
	for(int i=0;i<K-1;i++)
	{
	    int temp;
	    cin>>temp;
	    cout<<"-1 ";
	    h.insertKey(-temp);
	}
    int temp;
    cin>>temp;
    h.insertKey(-temp);

	    for(int i=0;i<K-1;i++)
	    {
	        h2.insertKey(-h.extractMin());
	    }
    cout<<(-h.harr[0])<<" ";
	for(int i=K;i<N;i++)
	{
	    int temp;
	    cin>>temp;
	    if(temp>h2.harr[0])
	    {
	        h.insertKey(-h2.extractMin());
	        h2.insertKey(temp);
	    }
	    else{h.insertKey(-temp);}
	    
        int ans=h.harr[0];
        cout<<-ans<<" ";
	}
	cout<<endl;
	
	    
	}
	else
	{
	    MinHeap h(N);
	    for(int i=0;i<N;i++)
	    {
	        int temp;
	        cin>>temp;
	        h.insertKey(-temp);
	        cout<<-h.harr[0]<<" ";
	    }
	    cout<<endl;
	}
	}
	return 0;
}
