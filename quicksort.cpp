#include<iostream>
#include<ctype.h>
#include<time.h>
using namespace std;
class quick
{
	int temp,high,low;
	public:
	 int partition(int*,int,int);
	 void qsort(int*,int,int);
};
int quick::partition(int a[],int low,int high)
{
	int left,right,key;
    key=a[low];
	left=low;
    right=high;
	while(left<right)
	{
		while(left<high && a[left]<=key)
			left++;
		while(right>=low && a[right]>key)
			right--;
		if(left<right)
		{ 
			int temp;
    		temp=a[left];
    		a[left]=a[right];
   			a[right]=temp;
		}
		else
		{ 
			int temp;
   			temp=a[low];
    		a[low]=a[right];
    		a[right]=temp;
		    return right;
		}
	}
}
void quick::qsort(int a[],int low,int high)
{
	if(low<high)
	{
		int j=partition(a,low,high);
		qsort(a,low,j-1);
		qsort(a,j+1,high);
	}
}
int main()
{
	int *a,n,i;
	clock_t start,stop;
	quick q;
	cout<<"enter the number of elements:"<<endl;
	cin>>n;
	a=new int[n];

	for(i=0;i<n;i++)
	  a[i]=rand();
	 start=clock();
	 q.qsort(a,0,n-1);
	 stop=clock();
	 cout<<"sorted elements are:"<<endl;
	 for(i=0;i<n;i++)
	   cout<<a[i]<<endl;
	   cout<<fixed<<"time taken="<<(float)(stop-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	   cout<<"space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(q)<<"bytes";
}