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

