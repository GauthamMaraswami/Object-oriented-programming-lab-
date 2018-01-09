#include<iostream>
#include<stdlib.h>
using namespace std;

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
		int isempty()
		{
		if(top==-1)
		return 1;
		else
		return 0;
		}


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

template <class t>
class queue
{
	stack <t> s1;
	stack <t> s2;
	public:
	
	void insert(t a)
	{
	    s1.push(a);
	    
	
	}
	t remove()
	{
		t nx;
		while(!s1.isempty())
		{
		s2.push(s1.pop());
		}
		if(!s2.isempty())
			nx=s2.pop();
	
		while(!s2.isempty())
		{
		s1.push(s2.pop());
		}
		return nx;
	}
	

};


int main()
{
	int ch,t,n1,t1;
	cout<<"enter the no of queues";
	cin>>n1;
	queue <int> s[n1];
	while(1)
	{
		cout<<"1- insert 2- delete  4- break\n"<<endl;
		cin>>ch;
        if(ch==1)   
		{
			cout<<"enter the stack no\n";
	 		cin>>t1;
	 		if(t1>=n1)
				 cout<<"invalid entry";
			else
			{
        		 cout<<"enter\n";
  				 cin>>t;
				 s[t1].insert(t);	
			}
		}
		else if(ch==2)
		{
			cout<<"enter the stack no\n";
			cin>>t1;
	 		if(t1>=n1)
	 			cout<<"invalid entry";
			else
			{
       			 cout<<s[t1].remove();
			}
		}
		
			else
				break;

	}


}



