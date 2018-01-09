#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int value;
	struct node* next;
};

template <class t>
class stack
{
	 t node[100];
	 int size;
	 int top;
	 public :
	 	stack()
		{
		top=-1;
		size=0;
        	}
		void push(t a);
		t pop();
		void display();


};
template <class t>
void stack <t>::push(t a)
{
	top++;
	node[top]=a;
	++size;
	
	cout<<"pushed succe3ssfully"<<endl;
}
template <class t>
t stack<t>::pop()
{
	t x;
	if(top==-1)
	{
		cout<<"empty stack"<<endl;
		return -1;
	}
	else
	{	
		x=node[top];
		top--;
	}
	return x;
}
template <class t>
void stack<t>::display()
{
          int n;    
	  n=top;	
 		if(top==-1)
		{
			cout<<"empty\n";	
		}
		else
		{
			while(n!=-1)
			{
				cout<<node[n]<<"<--";
				n--;
			}
		}

}




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
	
	int ch,n1,t1,ch1,ch2;
	char t;
	cout<<"character stack\n";
	cout<<"enter the no of stacks";
	cin>>n1;
	stack <char> s[n1];
	while(1)
	{
		cout<<"1- push 2- pop 3- display 4- break\n"<<endl;
		cin>>ch;
        	if(ch==1)   
		{
			 cout<<"enter the stack no\n";
			 cin>>t1;
			 if(t1>=n1)
	 			cout<<"invalid entry";
			 else{
         			cout<<"enter the value\n";
  	 			cin>>t;
				s[t1].push(t);	
			     }
		}
		else if(ch==2)
		{
			cout<<"enter the stack no\n";
	 		cin>>t1;
			if(t1>=n1)
	 			cout<<"invalid entry";
			else{
        			cout<<s[t1].pop();
			    }
		}
		else if(ch==3)
		{
			cout<<"enter the stack no\n";
			 cin>>t1;
	 		if(t1>=n1)
	 			cout<<"invalid entry";
			else
			{
				s[t1].display();	
			}
		}
		else
			break;

	}
	cout<<"float stack\n";
	float tm;
	cout<<"enter the no of stacks";
	cin>>n1;
	stack <float> s1[n1];
	
	while(1)
	{
		cout<<"1- push 2- pop 3- display 4- break\n"<<endl;
		cin>>ch1;
        	if(ch1==1)   
		{
			 cout<<"enter the stack no\n";
			 cin>>t1;
			 if(t1>=n1)
	 			cout<<"invalid entry";
			 else{
         			cout<<"enter the value\n";
  	 			cin>>tm;
				s1[t1].push(tm);	
			     }
		}
		else if(ch1==2)
		{
			cout<<"enter the stack no\n";
	 		cin>>t1;
			if(t1>=n1)
	 			cout<<"invalid entry";
			else{
        			cout<<s1[t1].pop();
			    }
		}
		else if(ch1==3)
		{
			cout<<"enter the stack no\n";
			 cin>>t1;
	 		if(t1>=n1)
	 			cout<<"invalid entry";
			else
			{
				s1[t1].display();	
			}
		}
		else if(ch1==4)
			break;

	}
	
	
	
	
	
	Point tn;
	cout<<"point stack\n";
	cout<<"enter the no of stacks";
	cin>>n1;
	stack <Point> s2[n1];
	while(1)
	{
		cout<<"1- push 2- pop 3- display 4- break\n"<<endl;
		cin>>ch2;
        	if(ch2==1)   
		{
			 cout<<"enter the stack no\n";
			 cin>>t1;
			 if(t1>=n1)
	 			cout<<"invalid entry";
			 else{
			     int b;
         			cout<<"enter the value\n";
  	 			cin>>b;
  	 			Point tx(b);
				s2[t1].push(tx);	
			     }
		}
		else if(ch2==2)
		{
			cout<<"enter the stack no\n";
	 		cin>>t1;
			if(t1>=n1)
	 			cout<<"invalid entry";
			else{
        			cout<<s2[t1].pop();
			    }
		}
		else if(ch2==3)
		{
			cout<<"enter the stack no\n";
			 cin>>t1;
	 		if(t1>=n1)
	 			cout<<"invalid entry";
			else
			{
				s2[t1].display();	
			}
		}
		else if(ch2==4)
			break;

	}
	
	
	
	
	
	
	
	
	
	


}




