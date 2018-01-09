#include<iostream>
#include<stdlib.h>
using namespace std;
/* 

2)A University and a Company have jointly taken a project.  Class University contains name of the university, department to which the project is assigned, person to whom the project is assigned.  A function display is there to display the information. Class Company contains name of the company, Number of Engineers assigned, amount invested to do the project. A function display is there to display the information. Class Project is inherited from University and Company. It contains type of project, duration of project, amount granted to complete the project. A function display displays the related information. 
*/
class university
{
	string name;
	string dept;
	string person;
	public:
	university(){
	
	}
	university(string na,string de,string person1)
	{
	name=na;
	dept=de;
	person=person1;
	}
	void display()
	{
	cout<<"name "<<name;
        cout<<"dept "<<dept;
	}

};
class company
{
	string name;
	int neng;
	float amount;
	
	
	public:
	company()
	{
	}
	company(string na1,int nen,float amt)
	{
		name=na1;
		neng=nen;
		amount=amt;
	
	}
	void display()
	{
	cout<<"name "<<name;
        cout<<endl<<"engineers"<<neng;
	cout<<endl<<"amount"<<amount;
	}

};
/*2)A University and a Company have jointly taken a project.  Class University contains name of the university, department to which the project is assigned, person to whom the project is assigned.  A function display is there to display the information. Class Company contains name of the company, Number of Engineers assigned, amount invested to do the project. A function display is there to display the information. Class Project is inherited from University and Company. It contains type of project, duration of project, amount granted to complete the project. A function display displays the related information. 
*/
class project:public university,public company
{
	string type;
	int dur;
	float amount;
	
	
	public:
	project():university(),company()
	{
	
	}
	project(string na,string de,string np,string na1,int nen,float amt,string typ,int dur1,float amount1):university(na,de,np),company(na1,nen,amt)
	{
	type=typ;
	dur=dur1;
	amount=amount1;
	}
	void display()
	{
	university::display();
	company::display();
	cout<<"type "<<type;
        cout<<endl<<"duration"<<dur;
	cout<<endl<<"amount"<<amount;
	}

};
int main()
{
string name;
	string dept;
	string perso;
	string cname;
	int neng;
	float amount;
	string type;
	int dur;
	float tamount;
	
project p1;
int ch;
while(1)
{
cout<<"enter your choice 1- insert 2- display\n";
cin>>ch;
switch (ch)
{
case 1:
{
cin>>name>>dept>>perso>>cname>>neng>>amount>>type>>dur>>tamount;
project p2(name,dept,perso,cname,neng,amount,type,dur,tamount);
p1=p2;
break;
}
case 2:
p1.display();
break;
default:
exit(0);
}
}
return 0;
}


