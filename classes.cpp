#include <iostream>
using namespace std;

 class Box{
   public:
    double length;
    double getwidth(void);
    void setwidth(double wid);

    private:
    double width;
 };

//member functions or freind functions can access private member
double Box::getwidth(void)
{
   return width;
}

void Box::setwidth(double wid)
{
   width=wid;
}

int main () {
 Box box;
 box.length=20.0; //length is public
 cout<<"length of the box "<<box.length<<endl;
 //box.width=10.00 is illegal as it's a private member
 box.setwidth(20.0); //friend function
 cout<< "Width of box "<< box.getwidth() <<endl;
 return 0;

}