using namespace std;

#include <iostream>
#include <iomanip>
#include <ctype.h>

class tsp
{
    int n,a[10][10],v[10];
    public: int cost;
            void read_matrix();
            int least(int);
            void mincost(int);
            tsp()
            {
                cost=0;
            }

};

void tsp::read_matrix()
{
    int i,j;
    cout<<"Enter the number of cities"<<endl;
    cin>>n;
    cout<<"Enter the cost matrix"<<endl;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        cin>>a[i][j];
        v[i]=0;
    }
}

int tsp::least(int c)
{
    int i,nc=999,min=999;
    for(i=0;i<n;i++)
    {
        if(a[c][i]!=0 && v[i]==0)
        if(a[c][i]<=min)
        {
            min=a[c][i];
            nc=i;
        }
    }
        if(min!=999)
        cost+=min;
        return nc;
}

void tsp::mincost(int city)
{
    int i,ncity;
    v[city]=1;
    cout<<city<<setw(5);
    ncity=least(city);
    if(ncity==999)
    {
        ncity=0;
        cout<<ncity;
        cost+=a[city][ncity];
        return;
    }
    mincost(ncity);
}

int main()
{
    int i,j,source;
    tsp t;
    t.read_matrix();
    cout<<"Enter the source city"<<endl;
    cin>>source;
    t.mincost(source);
    cout<<endl<<"The minimum cost is "<<t.cost;
    return 0;
}