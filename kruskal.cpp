#include<iostream>
using namespace std;
class krusk
{
			int n,m, c[10][10];
		public: void read();
				void kr();
				int find(int,int[]);
				void uni(int,int,int[]);
};

void krusk :: uni(int i,int j, int p[])
{
	if(i<j)
		p[j]=i;
	else
		p[i]=j;
}

int krusk :: find(int v, int p[])
{

	while(p[v]!=v)
		v=p[v];
	return v;
}
void krusk :: read()
{
	int i,j,k;
	cout<<"enter number of nodes:";
	cin>>n;

	cout<<"enter cost matrix:"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			{ 
				cin>>k;
				if(k==0)
					c[i][j]=999;
				else
					c[i][j]=k;
			}
}

void krusk :: kr()
{
	int i,j,k,u,v,min,sum,t[10][2],p[10],co;
	co=0;
	k=0;
	sum=0;
	for(i=0;i<n;i++)
		p[i]=i;
	while(co<n)
	{
		min=999;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(c[i][j]<min)
				{
					min=c[i][j];
					u=i;
					v=j;
				}
		if(min==999)
			break;
		i=find(u,p);
		j=find(v,p);
		if(i!=j)
		{
			t[k][0]=u;
			t[k][1]=v;
			k++;
			co++;

			sum=sum+min;
			uni(i,j,p);
		}
		c[u][v]=c[v][u]=999;
	}
	if(co!=n-1)
		cout<<"spanning tree doesnt exist"<<endl;
	else
	{
		cout<<"spanning tree exists and minimum spanning tree is:"<<endl;
		for(i=0;i<n-1;i++)
			cout<<t[i][0]<<"-> "<<t[i][1]<<endl;
		cout<<"the cost of spanning tree ="<<sum;
	}
}

int main()
{
	krusk k;
	k.read();
	k.kr();	
	return 0;
}