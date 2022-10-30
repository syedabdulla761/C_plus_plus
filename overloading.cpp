#include<iostream>
using namespace std;
class Box{
	public:
	double getvolume()
	{
		return length*width*height;
	}
	void setlength(double len)
	{
		length=len;
	}
	void setwidth(double wid)
	{
		width=wid;
	}
	void setheight(double hei)
	{
		height=hei;
	}
	Box operator+(const Box& b)
	{
		Box box;
		box.length=this->length+b.length;
		box.width=this->width+b.width;
		box.height=this->height+b.height;
		return box;
	}
	private:
	double length;
	double width;
	double height;
};

int main()
{
	Box box1;
	Box box2;
	Box box3;
	double volume=0.0;
	box1.setlength(3.0);
	box1.setwidth(4.5);
	box1.setheight(2.5);
	volume=box1.getvolume();
	cout<<"volume of box1 is "<<volume<<endl;

	box2.setlength(6.0);
	box2.setwidth(2.5);
	box2.setheight(4.5);
	volume=box2.getvolume();
	cout<<" volume of box2 is "<<volume<<endl;

	box3=box1 + box2;
	volume=box3.getvolume();
    cout<<" volume of box3 is "<<volume<<endl;

	return 0;
}