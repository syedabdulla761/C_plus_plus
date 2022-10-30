#include<iostream>
#include<ctype.h>
#include<time.h>
using namespace std;
class insertion
{
	public:void ins(int*,int);
};

void insertion::ins(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
	{ 

        key = arr[i]; 

        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        { 

            arr[j + 1] = arr[j]; 

            j = j - 1; 

        } 
        arr[j + 1] = key; 
    }
}   
int main() 
{ 

    int i,n;
	insertion in;
	clock_t start,stop;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the elements"<<endl;
	for(i=0;i<n;i++)
	  a[i]=rand();
	start=clock();
	in.ins(a,n);
	stop=clock();
	cout<<"sorted elements are\n"<<endl;
	for(i=0;i<n;i++)
	 cout<<a[i]<<"  ";
	 cout<<endl<<"Time taken="<<(float)(stop-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	cout<<"space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(in)<<"bytes"<<endl;
}