#include<iostream> 
#include<ctype.h>
#include<time.h>
using namespace std;


class heap
{
	public: void heapify(int *,int);
			void adjust(int *,int,int); 
			void heapsort(int *,int);
};

void heap::heapify(int a[],int n)
{
int key,i,j,k;
for(i=1;i<n;i++)
{
key=a[i];
j=i;
k=(j-1)/2;
while(j>0 && key>a[k])
{
	a[j]=a[k];
	j=k;
	k=(j-1)/2;
}
a[j]=key;
}
}



void heap::adjust(int a[],int n,int p)
{
	int item,i;
	item=a[p];
	i=2*p+1;
	while(i<n)
	{
		if(i+1<n)
			if(a[i]<a[i+1])
				i++;
		if (item<a[i])
		{
			a[p]=a[i];
			p=i;
			i=2*p+1;
		}
		else
			break;
	}
	a[p]=item;
}

void heap::heapsort(int a[], int n)
{
	int i,temp;
	heapify(a,n);
	for(i=n-1;i>0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		adjust(a,i,0);
	}
}

int main()
{
	int *a,n,i;
	clock_t start, stop; 
	heap h;
	cout<<"Enter the number of elements"<<endl;
	cin>>n; 
	a=new int[n];
	cout<<"Enter the elements"<<endl; 
	for(i=0;i<n;i++)
		a[i]=rand();
	start=clock(); 
	h.heapsort(a,n);
	stop=clock();
	cout<<"Sorted elements are\n"<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\nTime taken="<<(float)(stop-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	cout<<"Space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(h)<<" bytes"; 

}