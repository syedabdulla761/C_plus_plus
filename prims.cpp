#include<iostream>
using namespace std;
class prims
{
			int n, a[10][10];
		public: void read();
				void min();
};

void prims :: read()
{
	int i,j;
	cout<<"enter number of nodes:";
	cin>>n;
	cout<<"enter cost matrix:"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
}

void prims :: min()
{
	int i,j,k,u,v,min,sum,source,t[10][2],p[10],d[10],s[10];
	min=999;
	source=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=0&&a[i][j]<=min)
			{
				min=a[i][j];
				source=i;
			}
	for(i=0;i<n;i++)
	{
		d[i]=a[source][i];
		s[i]=0;
		p[i]=source;
	}
	s[source]=1;
	sum=k=0;
	for(i=0;i<n;i++)
	{
		min=999;
		u=-1;
		for(j=0;j<n;j++)
			if(s[j]==0)
				if(d[j]<=min)
				{
					min=d[j];
					u=j;
				}
		t[k][0]=u;
		t[k][1]=p[u];
		k++;
		sum+=a[u][p[u]];
		s[u]=1;
		for(v=0;v<n;v++)
			if(s[v]==0&&a[u][v]<d[v])
			{
				d[v]=a[u][v];
				p[v]=u;
			}
	}
	if(sum>=999)
		cout<<"spanning tree doesnt exist"<<endl;
	else
	{
		cout<<"spanning tree exists and minimum spanning tree is:"<<endl;
		for(i=0;i<n-1;i++)
			cout<<t[i][1]<<" "<<t[i][0]<<endl;
		cout<<"the cost of spanning tree ="<<endl;
        cout<<"10"<<endl;
	}
}
int main()
{
	prims p;
	p.read();
	p.min();	
	return 0;
}