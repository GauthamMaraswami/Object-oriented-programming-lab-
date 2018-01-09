#include<iostream>
#include<stdlib.h>
using namespace std;
class user
{
	protected:
	string name;
	int age;
	public:
	user()
	{
	}
	user(string s,int ag)
	{
	  name=s;
	  age=ag;
	} 
	void display()
	{
		cout<<"name"<<name<<endl<<"age"<<endl;
	}


};

class student:public user
{
	string course;
	int rno;
	float marks;
	public:
	student():user()
	{
	}
	student(string na,int ag,string cor,int rn,float mar):user(na,ag)
	{
		course=cor;
		rno=rn;
		marks=mar;
	}
	void display()
	{
		user::display();
		cout<<endl<<"course"<<course<<endl;
		
		cout<<"marks"<<marks;	
	}
};
/*Class user contains data member name and age. A constructor with two arguments is used to assign name and age.  User are of two types a) Student and b) Teacher. class Student contains data member i)course ii) Roll Number and iii)Marks and method display() to display data related to student. class Teacher contains data member i) subject_assigned  (May take this as an array) ii) contact_hour and method display() to display data related to teacher.

 Implement this program using base class constructor in derived class.*/
class teacher:public user
{
	string subject[10];
	int nsub;
	string contact;
	public:
	teacher():user()
	{
	
	}
	teacher(string na,int ag,string su[],int nsu,string cont):user(na,ag)
	{
		
		nsub=nsu;
		for(int i=0;i<nsub;++i)
		{
		 subject[i]=su[i];
		}
		contact=cont;
		
	}
	void display()
	{
		user::display();
		cout<<endl<<"contact"<<contact<<endl;
		for(int i=0;i<nsub;++i)
		    cout<<subject[i]<<endl;
		
	}
};

int main()
{	
student s2;
teacher t2;
string name;
	int age,ch;
	string course;
	int rno;
	float marks;
	string subject[10];
	int nsub;
	string contact;
	while(1)
	{
	cout<<"enter the choice 1-create student 2-create teacher 3-display student 4- display teacher\n";
	
	cin>>ch;
	switch(ch)
	{
	case 1:
	{
	cin>>name;
	cin>>age;
	cin>>course;
	cin>>rno;
	cin>>marks;
	student s1(name,age,course,rno,marks);
	s2=s1;
	}
	break;
	case 2:
	{cin>>name;
	cin>>age;
	cin>>nsub;
	for(int i=0;i<nsub;++i)
	cin>>subject[i];
	cin>>contact;
	teacher t1(name,age,subject,nsub,contact);
	t2=t1;
	}
	break;
	case 3:
	s2.display();
	break;
	case 4:
	t2.display();
	break;
	default:
	exit(0);
	}
	}
	
return 0;
}




