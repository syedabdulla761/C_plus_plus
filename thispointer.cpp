#include<iostream>
using namespace std;
class Box
{
	private:
			int l,b,h;
	public:
	void SetDimension(int l,int b,int h)
	{
	    this->l=l;this->b=b;this->h=h;
	}
		void ShowDimension()
	{
		cout<<"\nl="<<l<<" b= "<<b<<" h= "<<h;
	}
};

int main()
{	
	Box smallBox;
	smallBox.SetDimension(12,10,5);
	smallBox.ShowDimension();
	return 0;
}

