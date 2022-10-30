#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
using namespace std;
class merge
{
    int low,high;
    public:
        void merge_sort(int *,int,int);
        void s_merge(int *,int ,int,int);
};
void merge::merge_sort(int a[],int low,int high)
{
    if(low<high)
    {
    int mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    s_merge(a,low,mid,high);
    }
}
void merge::s_merge(int a[],int low,int mid,int high)
{
    int x,y,z;
    int c[10000];
    x=low;
    y=mid+1;
    z=low;
    while(x<=mid && y<=high)
    {
        if(a[x]<a[y])
        {
            c[z]=a[x];
            x++;
            z++;
        }
        else
        {
            c[z]=a[y];
            y++;
            z++;
    }
    }
    while(x<=mid)
        c[z++]=a[x++];
    while(y<=high)
        c[z++]=a[y++];
    for(x=low;x<=high;x++)
        a[x]=c[x];
}
int main()
{
    int n,i;
    clock_t start,stop;
    merge m;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        a[i]=rand();
    start=clock();
    m.merge_sort(a,0,n-1);
    stop=clock();
    cout<<"Sorted elements are"<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<fixed<<endl<<"Time taken:- "<<(float)(stop-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    cout<<"space utilized:- "<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(m)<<" bytes"<<endl;
    return 0;
}