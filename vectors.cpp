#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &v){
    for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> vect1;
    int ele;
    int size;
    cout<<"Enter size of vector: "<<endl;
    cin>>size;
    cout<<"Enter Elements in vector:"<<endl;
    for(int i=0;i<size;i++){
        cin>>ele;
        vect1.push_back(ele);
    }
    vector<int> vect2(vect1);
    display(vect1);
    display(vect2);
    return 0;
}