#include <iostream>
#include<ctype.h>
#include <queue>
#include <vector>
#include <set>
#include<cstdlib>

using namespace std;
class topo{
	int n,a[10][10],indegree[10];
    public:void read_data();
    void find_indegree();
    void topological_sort();};
   
    // member fn
    void topo::read_data() {
      int i,j;
      cout<<"Enter the number of node"<<endl;
      cin>>n;
      cout<<"Enter the adjency matrix"<<endl;
      for(i=0;i<n;i++){
      for(j=0;j<n;j++)
     {
	       cin>>a[i][j];
      }
    
  }
    }

    // member fn
    void topo::find_indegree() {
    	int i,j;
         for(j=0;j<n;j++){
         	int sum=0;
         	for(i=0;i<n;i++){
         		sum=sum+a[i][j];
         		indegree[j]=sum;
         		
			 }
		 }
      
    }

    // member fn
    void topo::topological_sort() {
        int i,u,v,t[10],s[10];
       find_indegree();
       int top=-1;
       int k=0;
       for(i=0;i<n;i++){
       	if(indegree[i]==0){
       		s[++top]=i;
		   }
	   }
        while(top!=-1){
        	u=s[top--];
        	t[k++]=u;
        	for(v=0;v<n;v++){
        		if(a[u][v]==1)
        		{
        			indegree[v]--;
        			if(indegree[v]==0)
        			s[++top]=v;
				}
			}
		}
		cout<<"The topological ordering of the sequence is:"<<endl;
		for(i=0;i<n;i++){
			cout<<t[i]<<" ";
		}
}


int main() {
   topo t;
   system("cls");
   t.read_data();
   t.topological_sort();
}