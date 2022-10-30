#include <iostream>
#include <stdlib.h>

using namespace std;

class knapsack{
int n,m,dp[10][10],p[10],w[10];
public : void read_data();
         void write_data();
         void solution();
};

void knapsack::read_data(){
cout<<"Enter the number of objects"<<endl;
cin>>n;
cout<<"Enter the weight of the objects"<<endl;
for(int i=0;i<n;i++)cin>>w[i];
cout<<"Enter the profit of the objects"<<endl;
for(int i=0;i<n;i++)cin>>p[i]; 
cout<<"Enter the capacity of knapsack"<<endl;
cin>>m;
}


void knapsack::write_data(){
cout<<"The output is"<<endl;

for(int i=0;i<=n;i++){
for(int j=0;j<=m;j++)
cout<<dp[i][j]<<" ";
cout<<endl;
}


cout<<"The maximum profit is "<<dp[n][m]<<endl;

cout<<"Solution array is - "<<endl;

int x[10]={0};
int i=n,j=m;

while(i!=0 && j!=0){
if(dp[i][j]!=dp[i-1][j]){
x[i]=1;
j=j-w[i-1];
}
i--;
}

for(i=1;i<=n;i++){
if(x[i]==1)cout<<"Index- "<<i-1<<" Profit- "<<p[i-1]<<endl;
}

}

void knapsack::solution(){
for(int i=0;i<=n;i++){
for(int j=0;j<=m;j++){
if(i==0 || j==0)dp[i][j]=0;
else if(w[i-1]<=j)
dp[i][j]=max(p[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
else
dp[i][j]=dp[i-1][j];
}
}
}

int main(){
knapsack k;
k.read_data();
k.solution();
k.write_data();
return 0;
}