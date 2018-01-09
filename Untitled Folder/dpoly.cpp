#include<iostream>
using namespace std;
void fun1()
{
cout<<"Hey I am function1\n";

}
void fun2()
{
cout<<"I am funct 2"<<endl<<"\n";

}
int main()
{

	int ch;
	cout<<"enter your choice 1- fun1 2-fun2\n";
	cin>>ch;
	void (*p)(void);
	switch(ch)
	{
		case 1:
		p=&fun1;
		break;
		case 2:
		p=&fun2;
		break;
		default:
		cout<<"random\n";
		break;
		
	}
	p();
	return 0;
}
