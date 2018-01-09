#include<stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
int totcars;
int delete_record(string cname,string name);
class car{
	private:
	string company;
	string car_name;
	int year;
	string colors[10];
	int ncolors;
	
	int no_available_sale;
	int no_rent[10];
	int no_rented;
	int no_sale[10];
	int no_sold;
	int no_available_rent;
	public:
	float selling_cost;
	float renting_cost;
	float shipping_cost;
	float servicing_cost;
	car()
	{
		company="maruthi\n";
		car_name="alto 800\n";
		year=2000;
		ncolors=0;
		selling_cost=0;
		renting_cost=0;
		shipping_cost=0;
		no_available_sale=0;
		no_available_rent=0;
	
	}
	void display()
	{
	cout<<"company:"<<company<<endl;
	cout<<"model:"<<car_name<<endl;
	cout<<"year:"<<year<<endl;
	cout<<"quantity:";
	for(int i=0;i<ncolors;++i)
	         {
	         	cout<<colors[i]<<no_rent[i]<<no_sale[i];
	         	
	         }
	cout<<endl<<"sold"<<no_sold<<"of"<<no_available_sale<<endl;
	cout<<"rented"<<no_rented<<"of"<<no_available_rent<<endl;
	cout<<"selling_cost"<<selling_cost<<endl;
	cout<<"renting_cost"<<renting_cost<<endl;
	cout<<"servicing_cost"<<servicing_cost<<endl;
	cout<<"shipping cost"<<shipping_cost<<endl;
	}
	int add_car(){
	         cout<<"enter company\n";
	         cin>>company;
	         cout<<"model name\n";
	         cin>>car_name;
	         cout<<"enter year\n";
	         cin>>year;
	         cout<<"enter no of colors\n";
	         cin>>ncolors;
	         cout<<"enter the colors no of car available for rent no of car available for sale\n";
	         for(int i=0;i<ncolors;++i)
	         {
	         	cin>>colors[i]>>no_rent[i]>>no_sale[i];
	         	no_available_sale+=no_sale[i];
	         	no_available_rent+=no_rent[i];
	         
	         }
	         cout<<"enter selling cost\n";
	         cin>>selling_cost;
	         cout<<"enter renting cost\n";
	         cin>>renting_cost;
	         cout<<"enter shipping cost\n";
	         cin>>shipping_cost;
	         cout<<"enter servicing cost\n";
	         cin>>servicing_cost;
 
		
	       	}
	   int rent_car(string col)
	   {
	   	for(int i=0;i<ncolors;++i)
	   	{
	   		if(col==colors[i]&&no_rent[i]>0)
	   		{
	   			no_rent[i]-=1;
	   			no_available_rent-=1;
	   			no_rented+=1;
	   			return 0;
	   		}
	   		 
	   	}
	  	 return 1;
	   
	   }
	   int sell_car(string col)
	   {
	   	for(int i=0;i<ncolors;++i)
	   	{
	   		if(col==colors[i]&&no_sale[i]>0)
	   		{
	   			no_sale[i]-=1;
	   			no_available_sale-=1;
	   			no_sold+=1;
	   			return 0;
	   		}
	   		 
	   	}
	   	return 1;
	   
	   }
	   string get_name()
	   {
	      	return car_name;
	   }
	   string get_company()
	   {
	   	   return company;
	   }
	   int get_year()
	   {
	   	   return year;
	   }
	   void avail_col()
	   {
	   	for(int i=0;i<ncolors;++i)
	   	{
	   		cout<<colors[i]<<endl;
	   	
	   	}
	   
	   }
	   int get_nosold()
	   {
	   	return no_sold;
	   }
	   int get_norent()
	   {
	   	return no_rented;
	   }
	};
	
	car carray[1000];
	
class sell
	{
	 
	  float tax;
	  string company;
	  string name;
	  car cobj;
	  int payment;
	  public:
	  void input()
	  {
	  
	  cout<<"enter the company\n";
	  cin>>company;
	  cout<<"enter the name\n";
	  cin>>name;
	
		string company,name;
		cout<<"enter company name \n";
		cin>>company>>name;
		int flag=0;
		int i;
		for( i=0;i<totcars;++i)
		{
			cout<<"hi"<<carray[i].get_company();
			
			if(carray[i].get_company()==company&&carray[i].get_name()==name)
			{
				flag=1;
				break;
			
			}
		
		
		}
		if(flag==0)
		{
		cout<<"car not found - please enter valid info\n";
		input();
		
		}
		else
		{
		cobj=carray[i];
		cout<<"car available found\n";
		}
	}
	  
	  void calculate_tax()
	  {
	  	tax=0.14*cobj.selling_cost;
	  
	  }
	  void generate_bill()
	  {
	  	input();
	  	string cname;
	  	cout<<"enter your name\n";
	  	cin>>cname;
	  	int age;
	  	cout<<"enter your age\n";
	  	cin>>age;
	  	string col;
	  	cout<<"enter color of the car\n";
	  	cobj.avail_col();
	  	cin>>col;
	  	cobj.sell_car(col);
	  	calculate_tax();
	  	cout<<"Thank you for shopping\n";
	  	cout<<"\t\t\tbill\n";
	  	cout<<"name:\t"<<name<<"\t\t\tage:\t"<<age<<endl;
	  	cout<<"cost of car:"<<cobj.selling_cost<<endl;
	  	cout<<"tax:\t"<<tax<<endl;
	  	cout<<"-----------------------\n";
	  	cout<<"total\n"<<cobj.selling_cost+tax;
	  	cout<<endl<<endl<<"please pay the bill\n";
	  	cin>>payment;
	  	if(payment==1)
	  	{
	  	  cout<<"payment successful\n";
	  	  delete_record(company,name);
	  	  carray[totcars]=cobj;
		  totcars++;
	  	}

	  }	
	};
class service
	{
	 
	  float tax;
	  string company;
	  string name;
	  float labour;
	  float parts;
	  car cobj;
	  float total;
	  int payment;
	  public:
	  void input()
	  {
	  
	  cout<<"enter the company\n";
	  cin>>company;
	  cout<<"enter the name\n";

		string company,name;
		cout<<"enter company name \n";
		cin>>company>>name;
		int flag=0,i;
		for( i=0;i<totcars;++i)
		{
			cout<<"hi"<<carray[i].get_company();
			
			if(carray[i].get_company()==company&&carray[i].get_name()==name)
			{
				flag=1;
				break;
			
			}
		}
		if(flag==0)
		{
		cout<<"car not found creating\n";
		input();
		}
		else
		{
		cout<<"car available\n";
		cobj=carray[i];
		}
	  }
	  void calculate_service()
	  {
	  	tax=0.14*cobj.servicing_cost;
	  	labour=800;
	  	cout<<"enter the parts cost\n";
	  	cin>>parts;
	  	total=labour+parts+tax+cobj.servicing_cost;
	   }
	  void generate_bill()
	  {
	  	input();
	  	string cname;
	  	cout<<"enter your name\n";
	  	cin>>cname;
	  	int age;
	  	cout<<"enter your age\n";
	  	cin>>age;
	  	
	  	calculate_service();
	  	cout<<"Thank you for shopping\n";
	  	cout<<"\t\t\tbill\n";
	  	cout<<"name:\t"<<name<<"\t\t\tage:\t"<<age<<endl;
	  	cout<<"service cost:"<<cobj.servicing_cost<<endl;
	  	cout<<"tax:\t"<<tax<<endl;
	  	cout<<"labour:\t"<<labour<<endl;
	  	cout<<"parts:\t"<<parts<<endl;
	  	cout<<"-----------------------\n";
	  	cout<<"total\n"<<total<<endl;
	  	cout<<endl<<endl<<"please pay the bill\n";
	  	cin>>payment;
	  	if(payment==1)
	  	{
	  	  cout<<"payment successful\n";
	  	  delete_record(company,name);
	  	  carray[totcars]=cobj;
		  totcars++;
	  	}
	   }	
	};
class rent{
	float tax;
	string company;
	string name;
	car cobj1;
	int time;
	float rentt;
	int payment;
	int total;
	public:
	void input()
	  {
	  
	  	cout<<"enter the company\n";
	  	cin>>company;
	  	cout<<"enter the name\n";
	  	cin>>name;
	  
		string company,name;
		cout<<"enter company name \n";
		cin>>company>>name;
		int flag=0,i;
		for(i=0;i<totcars;++i)
		{
			
			if(carray[i].get_company()==company&&carray[i].get_name()==name)
			{
				flag=1;
				break;
			}
		
		}
		if(flag==0)
		{
		cout<<"car not found creating\n";
		input();
		}
		else
		cout<<"car available\n";
		cobj1=carray[i];
		}
	 void calculate_rent()
	  {
	  	 cout<<"enter time\n";
	  	 cin>>time;
	         rentt=cobj1.renting_cost*time;
	         tax=0.14*cobj1.renting_cost;
		 total=rentt+tax;
	   }
	  void generate_bill()
	  {
	  	input();
	  	string name;
	  	cout<<"enter your name\n";
	  	cin>>name;
	  	int age;
	  	cout<<"enter your age\n";
	  	cin>>age;
	  	string col;
	  	cout<<"enter color of the car\n";
	  	cobj1.avail_col();
	  	cin>>col;
	  	cobj1.rent_car(col);
	  	calculate_rent();
	  	cout<<"Thank you for shopping\n";
	  	cout<<"\t\t\tbill\n";
	  	cout<<"name:\t"<<name<<"\t\t\tage:\t"<<age<<endl;
	  	cout<<"cost of car per hour:"<<cobj1.renting_cost<<endl;
	  	cout<<"time used:"<<time<<endl;
	  	cout<<"total rent:"<<rentt<<endl;
	  	cout<<"tax:\t"<<tax<<endl;
	  	cout<<"-----------------------\n";
	  	cout<<"total\n"<<total;
	  	cout<<endl<<endl<<"please pay the bill\n";
	  	cin>>payment;
	  	if(payment==1)
	  	{
	  	  cout<<"payment successful\n";
	  	  delete_record(company,name);
	  	  carray[totcars]=cobj1;
		  totcars++;
	  	}
	}
};

int delete_record(string cname,string name)
{
		int flag=0;
		int i;
		for( i=0;i<totcars;++i)
		{
			if(carray[i].get_company()==cname&&carray[i].get_name()==name)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		cout<<"car not found \n";
		
		return -1;
		}
		else
		{
		for(int j=i;j<totcars-1;++j)
		{
		carray[j]=carray[j+1];
		
		}
		cout<<"deleted \n";
		totcars--;
		return 0;
		}
}
void modify_database()
{
	int ch;
	cout<<"enter your choice\n 1-add\n 2-search\n 3-delete";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
		car cobj1;
		string company,name;
		cout<<"enter company name \n";
		cin>>company>>name;
		int flag=0;
		for(int i=0;i<totcars;++i)
		{
			if(carray[i].get_company()==company&&carray[i].get_name()==name)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		cout<<"car not found creating\n";
		carray[totcars].add_car();
		totcars++;
		}
		else
		cout<<"already found\n";
		
		break;
		}
		case 2:
		{
		car cobj1;
		string company,name;
		cout<<"enter company name \n";
		cin>>company>>name;
		int flag=0,i;
		for(i=0;i<totcars;++i)
		{
			if(carray[i].get_company()==company&&carray[i].get_name()==name)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		cout<<"car not found\n";
		}
		else
		{
		cout<<"available";
		carray[i].display();
		}
		break;
		}
		case 3:
		{
		string company,name;
		cout<<"enter company name \n";
		cin>>company>>name;
		delete_record(company,name);
		
		break;
		}
		
	}

}
string UID[3]={"mehul","gunjan","gautham"},PWD[3]={"15co130", "15co134","15co118"};

int checkID(string a,string b){
	int flag=0;
	for(int i=0;i<3;i++){
		if(a==UID[i]&&b==PWD[i])
			flag=1;
	}
	return flag;
}
int main () {
	string id,pwd;
	int c=0;
	cout<<"Welcome !!\n"<<endl;
	ID :
	cout<<"Enter User ID :\n";
	cin>>id;
	cout<<"Enter Password :\n";
	cin>>pwd;
	int x= checkID(id,pwd);	//Function to validate user              	  
	if(x==0){c++;
		if(c==3){
			cout<<"\nToo many wrong attempts..Exiting the Program.\n\nSorry for the incovinience :)\n";   //Invalid User
			exit(0);
		}
		cout<<"\nWrond Username or Password !!\nPlease Re-enter ->\n\n";
		goto ID;
	}
	int choice;
	while(1){
		cout<<"\nChoose :\n\t1. Add Car \n\t2. Sell Car \n\t3.Rent Car \n\t4. Repair Car \n\t0. Logout !\n\n";
		cin>>choice;
		
	}
return 0;
}
