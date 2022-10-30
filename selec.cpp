#include<iostream>
#include<ctype.h>
#include<time.h>
using namespace std;
class selection
{
	int pos,temp;
	public:void sel(int*,int);
};
void selection::sel(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		 if(a[j]<a[pos])
		  pos=j;
		  temp=a[i];
		  a[i]=a[pos];
		  a[pos]=temp;
	}
}
int main()
{
	int i,n;
	selection s;
	clock_t start,stop;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the elements"<<endl;
	for(i=0;i<n;i++)
	  a[i]=rand();
	start=clock();
	s.sel(a,n);
	stop=clock();
	cout<<"sorted elements are"<<endl;
	for(i=0;i<n;i++)
	 cout<<a[i]<<" ";
	 cout<<endl<<"time taken="<<(float)(stop-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	cout<<"space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(s)<<"bytes"<<endl;
}