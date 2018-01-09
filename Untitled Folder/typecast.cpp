#include<iostream>
#include<math.h>
using namespace std;
class circle
{
int r;
float area;
public:
	circle()
	{
	r=0;
	area=0;
	}
	circle(int &a1)
	{
	  r=a1;
	}
	void input()
	{
		cout<<"enter radius"<<endl;
		cin>>r;
		calarea();
		
	}
	int gr()
	{
		return r;
	}
	float garea()
	{
		return area;
	}
	void calarea()
	{
	   area=3.14*r*r;
	}
	operator float()
	{
	  calarea();
	 return area;
	} 
       /* circle(ellipse &c)
        {
          r=sqrt(c.ga()*c.gb());
          area=c.garea();
        }*/
        void display()
	{
	cout<<"area"<<area<<endl;
	cout<<"r"<<r<<endl; 
	}




};

class ellipse
{
int a;
int b;
float area;
public:
        ellipse()
        {
	a=0;
	b=0;
	area=0;
	}
	ellipse(const int &a1)
	{
	  a=a1;
	  b=a1;
	  calarea();
	  
	}
	ellipse(circle &a1)
	{
	 a=a1.gr();
	 b=a1.gr();
	 area=a1.garea();
	}
	int ga()
	{
	return a;
	}
	int gb()
	{
	return b;
	}
	float garea()
	{
	return area;
	}
	void input()
	{
		cin>>a;
		cin>>b;
	}
	void calarea()
	{
	   
	   area=3.14*a*b;
	}
	operator float()
	{
	 return area;
	} 
	void display()
	{
	cout<<"area"<<area<<endl;
	cout<<"a,b"<<a<<" "<<b<<endl; 
	}



};





int main()
{
ellipse e1=10;
//e1=10;

e1.display();
float far;
far=e1;
cout<<"obj to no"<<far;
circle e2;
e2.input();
cout<<float(e2)<<" ewsw 1e3e";
e2.display();
ellipse e3=e2;
e3.display();
return 0;

}
