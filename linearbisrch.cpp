#include <iostream>
#include <cstdio>
#include <iomanip>
#include <time.h>
#define SIZE 100;
using namespace std;
class linear
{
    public:
    void ln(int a[],int n,int s);
};
class binary
{
    int low,mid,high;
    public:
    void bn(int a[],int n,int s);
};
void linear::ln(int a[],int n,int s)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            cout<<"Element found at position "<<i+1<<endl;
        }
    }
    if((i+1)<0)
    {
        cout<<"Element not found"<<endl;
    }
}
void binary::bn(int a[],int n,int s)
    {
        int i=0,loc;
        low=0;
        high=n-1;
        mid=(low+high)/2;
        
    while(low<=high)
	{
	if(a[mid]==s)
	{
		loc=mid;
		break;
	}
	else if(a[mid]>s)
	{
        high=mid-1;
    mid=(low+high)/2;
    }
	else 
    low=mid+1;
    mid=(low+high)/2;
    }
    if(loc>=0)
    cout<<"Element found at position "<<loc+1<<endl;
    else
    cout<<"Element not found"<<endl;
}
int main() 
{
    int a[100],i;
    int n,s,ch=1;
    clock_t start,stop;
        cout<<"1.Linear search"<<endl<<"2.Binary search"<<endl;
        cin>>ch;
    switch (ch)
    {
    case 1:
        cout<<"Enter number of elements"<<endl;
        cin>>n;
        cout<<"Enter elements"<<endl;
        for(i=0;i<n;i++)
        { cin>>a[i]; }
        cout<<"Enter the element to be searched"<<endl;
        cin>>s;
        linear Ls;
        start=clock();
        Ls.ln(a,n,s);
        stop=clock();
        cout<<"Time consumed"<<(stop-start)<<" nanoseconds"<<endl;
        cout<<"space consumed"<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(s)+sizeof(Ls)<<" bytes"<<endl;
        break;
    case 2:
        int a[100],mid,low,high;
        cout<<"Enter number of elements"<<endl;
        cin>>n;
        cout<<"Enter elements"<<endl;
        for(i=0;i<n;i++)
        { cin>>a[i]; }
        cout<<"Enter the element to be searched"<<endl;
        cin>>s;
        binary bin;
        start=clock();
        bin.bn(a,n,s);
        stop=clock();
        cout<<"Time consumed"<<(stop-start)<<" nanoseconds"<<endl;
        cout<<"space consumed"<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(s)+sizeof(bin)<<" bytes"<<endl;
        break;
    default:
        cout<<"Invalid input"<<endl;
    }
}
    