#include<iostream>
using namespace std;


template <class t>
class queue
{	
	struct node
	{
	t value;
	struct node* next;
	};
	struct node* front;
	struct node* back;
	public:
		queue()
		{
			front=NULL;
			back=NULL;
		}
		void insert(t n);
		t remove();
		void display();
};

template <class t>
void queue<t>::insert(t a)
{	
	node *n=new node;
	n->value=a;
	n->next=NULL;
	if(front==NULL&&back==NULL)
	{
		front=n;
        	back=n;
	}
	else
	{
		back->next=n;
		back=n;
	}
	cout<<"pushed successfully"<<endl;
}

template <class t>
t queue<t>::remove()
{
	t x;
	if(front==NULL&&back==NULL)
	{
		cout<<"empty queue"<<endl;
		return -1;
	}
	else if(front->next==NULL)
	{
		x=front->value;
		front=NULL;
		back=NULL;
	}
	else
	{	
		x=front->value;
		front=front->next;
	}
		return x;
}

template <class t>
void queue<t>::display()
{
	node *n=new node;
	n=front;
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
	cout<<"enter the no of queues";
	cin>>n1;
	queue <int> s[n1];
	while(1)
	{
		cout<<"1- insert 2- delete 3- display 4- break\n"<<endl;
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

