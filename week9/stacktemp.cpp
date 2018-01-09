#include<iostream>
using namespace std;


class stack
{
	
	 public :
	 	stack()
		{
		top=NULL;
        	}
		void push(int a);
		int pop();
		void display();


};
void stack::push(int a)
{
	cout<<"pushed succe3ssfully"<<endl;
	node *n=new node;
	n->value=a;
	n->next=top;
        top=n;
	cout<<"pushed succe3ssfully"<<endl;
}
int stack::pop()
{
	int x;
	if(top==NULL)
	{
		cout<<"empty stack"<<endl;
		return -1;
	}
	else
	{	
		x=top->value;
		top=top->next;
	}
	return x;
}

void stack::display()
{
		node *n=new node;
		n=top;
 		if(n==NULL)
		{
			cout<<"empty\n";	
		}
		else
		{
			while(n!=NULL)
			{
				cout<<n->value<<"<--";
				n=n->next;
			}
		}

}

int main()
{
	int ch,t,n1,t1;
	cout<<"enter the no of stacks";
	cin>>n1;
	stack s[n1];
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


}




