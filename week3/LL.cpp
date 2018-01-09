#include <iostream>
using namespace std;
class node
{	
	int data;
	node *next;
	public:
	void ins(int d)
	{
		data = d;
	}
	void link(node *n)
	{
		next = n;
	}
	node *linked()
	{
		return next;
	}
	int info()
	{
		return data;
	}
};
class List
{
	node *front;
	int len;
	node* rev(node* n)
	{
		if(n->linked() == NULL || n == NULL)
			return n;
		node *it = rev(n->linked());
		n->linked()->link(n);
		return it;
	}
	public:
	List()
	{
		front = NULL;
		len = 0;
	}
	void ins();
	void del();
	void disp();
	int search();
	void swap();
	void reverse()
	{
		if(front == NULL)
		{
			cout<<"Empty list";
			return;
		}
		node* it = rev(front);
		front->link(NULL);
		front = it;
	}
};
void List::swap()
{
	cout<<"Enter positions to be swapped\n";
	int pos1, pos2;
	cin>>pos1>>pos2;
	if(pos1 > len || pos2 > len)
	{
		cout<<"Invalid positions\n";
		return;
	}
	node *it1 = front;
	node *it2 = front;
	for(int i = 1; i < pos1; ++i)
		it1 = it1->linked();
	for(int i = 1; i < pos2; ++i)
		it2 = it2->linked();
	node temp;
	temp.ins(it1->info());
	it1->ins(it2->info());
	it2->ins(temp.info());
}
void List::ins()
{
	node *n = new node;
	n->link(NULL);	
	cout<<"Enter position to insert\n";
	int pos;
	cin>>pos;
	int info;
	cout<<"Enter number to insert\n";
	cin>>info;
	n->ins(info);
	++len;
	node *it = front;
	
	if(front == NULL || pos == 1)
	{
		n->link(front);
		front = n;
		return;
	}
	if(pos >= len)
	{
		while(it->linked() != NULL)
			it = it->linked();
		it->link(n);
		return;
	}
	int i;
	for(i = 1; it->linked()->linked() != NULL; ++i)
	{
		if(i + 1 == pos)
		{
			n->link(it->linked());
			it->link(n);
			return;
		}
		it = it->linked();
	}
}

void List::del()
{
	if(front == NULL)
	{
		cout<<"Empty queue!\n";
		return;
	}
	cout<<"Enter position to delete\n";
	int pos;
	cin>>pos;
	if(pos > len || pos < 1)
	{
		cout<<"Invalid position\n";
		return;
	}
	--len;
	
	if(pos == 1)
	{
		front = front->linked();
		return;
	}
	if(pos == len - 1)
	{
		node *it = front;
		while(it->linked()->linked() != NULL)
			it = it->linked();
		it->link(NULL);
	}
	int i;
	node *it = front;
    for(i = 1; it->linked() != NULL; ++i)
	{
		if(i + 1 == pos)
		{
			it->link(it->linked()->linked());
			return;
		}
		it = it->linked();
	}
}
void List::disp()
{
	node *n = front;
	cout<<"Front: ";
	while(n != NULL)
	{
		cout<<n->info()<<" ";
		n = n->linked();
	}
	cout<<"\n";
}

int List::search()
{
	cout<<"Enter data in element to be found\n";
	int data;
	cin>>data;
	node *it = front;
	int i = 0;
	while(it->linked() != NULL)
	{
		if(it->info() == data)
			return i + 1;
		it = it->linked();
		++i;
	}
	return -1;
}
int main()
{	
	int a, sea;
	List L;
	cout<<"List functions:\n1. Insert\n2. Delete\n3. Display\n4. Reverse\n5. Search\n6. Swap nodes\n7. Exit\n";
	do{
		cout<<"Enter option:\n";
		cin>>a;
		switch(a)
		{
			case 1:
				L.ins();
				break;
			case 2:
				L.del();
				break;
			case 3:
				L.disp();
				break;
			case 4:
				L.reverse();
				break;
			case 5:
				sea = L.search();
				if(sea == -1)
				{
					cout<<"Element not found\n";
				}
				else
					cout<<"Element found at: "<<sea<<endl;
				break;
			case 6:
				L.swap();
				break;
		}
	}while(a != 7);
	return 0;
}





