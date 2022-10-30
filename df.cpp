#include<iostream>
#include<ctype.h>
using namespace std;
class DFS
{
	int n,adj[10][10];
	public:void read_matrix();
	void dfs(int u,int s[]);
	void reach();
	int connectivity();
};
void DFS::read_matrix()
{
	int i,j;
	cout<<"enter thr number of nodes:"<<endl;
	cin>>n;
	cout<<"enter the adjacency matrix:"<<endl;
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	      cin>>adj[i][j];
}
void DFS::dfs(int u,int s[])
{
	int v;
	s[u]=1;
	for(v=0;v<n;v++)
	 if(adj[u][v]==1&&s[v]==0)
	 dfs(v,s);
}
void DFS::reach()
{
	int i,source,s[10];
	for(i=0;i<n;i++)
	  s[i]=0;
	  cout<<"enter the source node"<<endl;
	  cin>>source;
	  dfs(source,s);
	  for(i=0;i<n;i++)
	  {
	  	if(s[i]==0)
	  	   cout<<"Node"<<i<<"is not reachable"<<endl;
	  	else
	  	    cout<<"Node"<<i<<"is reachable"<<endl;
	  }
}
int DFS::connectivity()
{
	int i,j,flag,s[10];
	for(j=0;j<n;j++)
  {
	for(i=0;i<n;i++)
	 s[i]=0;
	 dfs(j,s);
	 flag=0;
	for(i=0;i<n;i++)
	if(s[i]==0)
	   flag=1;
	if(flag==0)
	 return 1;
  }
  return 0;
}
int main()
{
	DFS d;
	d.read_matrix() ;
	d.reach();
	int flag=d.connectivity();
	if(flag==1) 
        cout<<"the graph is connected"<<endl;
	else
	   cout<<"the grap is not connected"<<endl;
}