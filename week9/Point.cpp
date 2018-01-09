#include<iostream>
#include<stdlib.h>
#include<stdlib.h>
using namespace std;
class Point
{
	int x,y;
	public:
		Point()
		{
			x=0;
			y=0;
		}
		Point(int a)
		{
			x=a;
			y=a;
		}
		Point(int a,int b)
		{
			x=a;
			y=b;
		}
		Point operator +(Point &arg)
		{
			Point P;
			P.x=x+arg.x;
			P.y=y+arg.y;
			return P;
			
		
		}
		Point operator -(Point &arg)
		{
			Point P;
			P.x=x-arg.x;
			P.y=y-arg.y;
			return P;
		}
		void display()
		{
			cout<<"x="<<x<<" y="<<y<<endl;
		}
		Point operator ++()
		{
			Point P;
			x=x+1;
			y=y+1;
			P.x=x;
			P.y=y;
			
			return P;
		}
		Point operator ++(int ar)
		{
			Point P;
			P.x=x;
			P.y=y;
			x=x+1;
			y=y+1;
			return P;
		}
		Point operator --()
		{
			Point P;
			P.x=x-1;
			P.y=y-1;
			x=x-1;
			y=y-1;
			return P;
		}
		void *operator new(size_t l)
		{
		 cout<<"new objected created\n";
		 Point* P=(Point *)malloc(l);
		 return P;
		}
		void operator delete(void *ptr)
		{
		  cout<<"deleted \n";
		  free (ptr);
		}
		Point operator --(int ar)
		{
			Point P;
			P.x=x;
			P.y=y;
			x=x-1;
			y=y-1;
			return P;
		}
		friend ostream & operator << (ostream &out, const Point &c);
		friend istream & operator >> (istream &in,  Point &c);
};

                ostream & operator << (ostream &out, const Point &c)
		{
    			out <<"x= "<< c.x;
    			out << "y= " << c.y << endl;
   			return out;
		}
		istream & operator >> (istream &in,  Point &c)
		{
			cout<<"enter x\n";
    			in>> c.x;
    			cout<<"enter y\n";
    			in>> c.y;
   			return in;
		}
int main()
{
	Point* p1=new Point(3);
	p1->display();
	Point p;
	p.display();
	Point q(5);
	q.display();
	Point r(5,4);
	r.display();
	p=r+q;
	p.display();
	++p;
	p.display();
	Point m=q++;
	cout<<"\nm ";
	m.display();
	cout<<"\nq ";
	q.display();
	Point n=q--;
	cout<<"\nm ";
	m.display();
	cout<<"\nq ";
	q.display();
	
	--q;
	cout<<"\nq ";
	q.display();
	cout<<"<< ";
	cout<<q;
	Point z;
	cin>>z;
	cout<<endl<<z;
	delete p1;
	return 0;
}
