#include<iostream>
#include<ctype.h>
using namespace std;
class dijkstra
{
	int n,cost[10][10],p[10],visited[10],d[10];
	public:void read_matrix();
	void shortpath(int);
	void display(int);
};
void dijkstra::read_matrix()
{
	int i,j;
	cout<<"enter the number of vertices:"<<endl;
	cin>>n;
	cout<<"enter the cost adjacency matrix:"<<endl;
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	    cin>>cost[i][j];
}
void dijkstra::shortpath(int src)
{
  int i,j,min,u,v;
  for(i=0;i<n;i++)
  {
  	d[i]=cost[src][i];
  	visited[i]=0;
  	p[i]=src;
  }
  visited[src]=1;
  for(i=0;i<n;i++)
  {
  	min=999;
  	u=0;
  	for(j=0;j<n;j++)
  	{
  		if(!visited[j])
  		   if(d[j]<min)
  		   {
  		   	min=d[j];
  		   	u=j;
		  }
	}
	visited[u]=1;
	for(v=0;v<n;v++)
	  if(!visited[v]&&(d[u]+cost[u][v]<d[v]))
	  {
	  	d[v]=d[u]+cost[u][v];
	  	p[v]=u;
	  }
  }
}
void dijkstra::display(int src)
{
	int i,k,parent;
	for(i=0;i<n;i++)
	{
		if(i==src)
		  continue;
		cout<<endl<<"the shortest path from:"<<src<<":to"<<i<<":is";
		k=i;
		cout<<k<<"<---";
		while(p[k]!=src)
		{
			cout<<p[k]<<"<---";
			k=p[k];
		}
		cout<<src;
		cout<<"and the cost is"<<d[i]<<endl;  
	}
}
int main()
{
	int source;
	dijkstra dij;
	dij.read_matrix();
	cout<<endl<<"enter the source"<<endl;
	cin>>source;
	dij.shortpath(source);
	dij.display(source);
}