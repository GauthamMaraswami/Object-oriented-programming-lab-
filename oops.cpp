#include<stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
int totcars;
int delete_record(string ,string);

class car{
	private:
	string company;
	string car_name;
	int year;
	string colors[10];
	int ncolors;
	static int ncars;
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
		/*company="maruthi\n";
		car_name="alto 800\n";
		year=2000;
		ncolors=0;
		selling_cost=0;
		renting_cost=0;
		shipping_cost=0;
		no_available_sale=0;
		no_available_rent=0;*/
	
	}
	
	void display()
	{
	cout<<"\ncompany : "<<company<<endl;
	cout<<"model : "<<car_name<<endl;
	cout<<"year : "<<year<<endl;
	cout<<"quantity : "<<endl;
	for(int i=0;i<ncolors;++i)
	         {
	         	cout<<"Car colour -> "<<colors[i]<<"\nNumber of available for rent -> "<<no_rent[i]<<"\nNumber of available for sale : "<<no_sale[i]<<endl;
	         	
	         }
	cout<<endl<<"Total number of cars sold : "<<no_sold<<" out of "<<no_available_sale<<endl;
	cout<<"Total number of cars rented"<<no_rented<<" out of "<<no_available_rent<<endl;
	cout<<"Base Selling cost = "<<selling_cost<<endl;
	cout<<"Base Renting cost per hour = "<<renting_cost<<endl;
	cout<<"Servicing cost = "<<servicing_cost<<endl;
	cout<<"Shipping cost per km = "<<shipping_cost<<endl;
	}
	int add_car1(string col,int ch)
	{
	++ncars;
		for(int i=0;i<ncolors;++i)
		{
			if(colors[i]==col&&ch==1)
			{
				cout<<"Enter the number of cars to be added :"<<endl;
				int q;
				cin>>q;
				no_rent[i]+=q;
			}
			else if(colors[i]==col&&ch==2){
				cout<<"Enter the number of cars to be added :"<<endl;
				int q;
				cin>>q;
				no_sale[i]+=q;
			}
		
		}
	}
	int add_car(){
	++ncars;
	         cout<<"\nEnter car company :\n";
	         cin>>company;
	         cout<<"Enter model name :\n";
	         cin>>car_name;
	         cout<<"Enter year :\n";
	         cin>>year;
	         cout<<"Enter total number of colors available :\n";
	         cin>>ncolors;
	         cout<<"Enter "<<ncolors<<" colors and number of rentable cars and number of cars available for sale of that colour :\n";
	         for(int i=0;i<ncolors;++i)
	         {
	         	cin>>colors[i]>>no_rent[i]>>no_sale[i];
	         	no_available_sale+=no_sale[i];
	         	no_available_rent+=no_rent[i];
	         
	         }
	         cout<<"Enter sale price :\n";
	         cin>>selling_cost;
	         cout<<"Enter renting cost per hour :\n";
	         cin>>renting_cost;
	         cout<<"Enter shipping cost per km :\n";
	         cin>>shipping_cost;
	         cout<<"Enter repair cost :\n";
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
class shipping
	{
	float dist;
	public:
	float calculate_shipping(float cost)
	{
	      cout<<"cout enter distance\n";
	      cin>>dist;
	      return dist*cost;
	}
	};
	
class sell:public shipping
	{
	 
	  float tax;
	  string company;
	  string name;
	  car cobj;
	  int wpayment,payment;
	  string cname,cadd;
	  int phone,ssn;
	  int shipflag;
	  float shipcost;
	  public:
	  string col;
	  void display()
	  {
	  	cout<<"company"<<company<<endl;
	  	cout<<"model"<<name<<endl;
	  	cout<<"color"<<col<<endl;
	  	cout<<"payment"<<payment<<endl;
	  	cout<<"name"<<cname<<endl;
	  	cout<<"phone"<<phone<<endl;
	  	cout<<"address"<<cadd<<endl;
	  	cout<<"ssn"<<ssn<<endl;
	  	
	  	cout<<"shipingcost"<<shipcost<<endl;
		cout<<"Base cost of car:"<<cobj.selling_cost<<endl;
		cout<<"tax"<<tax<<endl;
		cout<<"-----------------------\n";
		cout<<"total\n"<<cobj.selling_cost+tax+shipcost;	  
	  
	  }
	  void input()
	  {
	  
	  cout<<"enter the company\n";
	  cin>>company;
	  cout<<"enter the name\n";
	  cin>>name;
	
		
		int flag=flag=search_record(company,name);
		if(flag==-1)
		{
		cout<<"car not found - please enter valid info\n";
		input();
		
		}
		else
		{
		cobj=carray[i];
		cout<<"car available found\n";
		  	
	  	cout<<"enter color of the car\n";
	  	cobj.avail_col();
	  	cin>>col;
		}
	}
	  
	  void calculate_tax()
	  {
	  	tax=0.14*cobj.selling_cost;
	  
	  }
	  
	  void generate_temp_bill()
	  {
	  	input();
	  	cout<<"Do you want shipping 1- yes 2- no";
	  	cin>>shipflag;
	  	if(shipflag==1)
	  	{
	  	shipcost=calculate_shipping(cobj.shipping_cost);
	  	}
	  	
	  	
	  	
	  	calculate_tax();
	  	
	  	cout<<"\t\t\tbill\n";
	  	
	  	cout<<"cost of car:"<<cobj.selling_cost<<endl;
	  	cout<<"tax:\t"<<tax<<endl;
	  	cout<<"shipping:\t"<<shipcost<<endl;
	  	cout<<"-----------------------\n";
	  	cout<<"total\n"<<cobj.selling_cost+tax+shipcost;
	  	cout<<endl<<endl<<"does customer want to buy the car?\n";
	  	cin>>wpayment;
	  	if(wpayment==1)
	  	{
	  	generate_bill();
	  	 }

	  }	
	  
	  void generate_bill()
	  {
	  	
	  	
	  	cout<<"Enter customer name\n";
	  	cin>>cname;
	  
	  	cout<<"Enter customer phone number \n";
	  	cin>>phone;
	  	
	  	cout<<"Enter Customer Address\n";
	  	
	  	cin>>cadd;
	  	cout<<"Enter Customer SSN\n";
	  	
	  	cin>>ssn;
	  	cobj.sell_car(col);
	  	calculate_tax();
	  	cout<<"Thank you for shopping with us\n";
	  	cout<<"\t\t\tBill\n";
	  	cout<<"Name:\t"<<cname<<"\t\tAddress\t\t"<<cadd<<endl;
	  	cout<<"Phone\t"<<phone<<"\t\tSSN\t\t"<<ssn<<endl;
	  	cout<<"Base cost of car:"<<cobj.selling_cost<<endl;
	  	cout<<"shipping:\t"<<shipcost<<endl;
	  	cout<<"Tax amount @14%:\t"<<tax<<endl;
	  	cout<<"-----------------------\n";
	  	cout<<"Total cost of car\n"<<cobj.selling_cost+tax+shipcost;
	  	cout<<endl<<endl<<"Please pay the amount\n";
	  	cout<<"Customer wants to pay by cash(1) or card(2)?\n";
	  	cin>>payment;
	  	if(payment<=2&&payment>0)
	  	{	int y;
	  		if(payment==1){
			cout<<"Has the customer paid the cash?";
			cin>>y;
			if(y==1)	  			
	  	  	cout<<"Payment by cash successful\n";
	  	  	else
	  	  	cout<<"Payment not successful\n";
	  	  	}
	  	  	if(payment==2){
			cout<<"Has the bank confirmed the transaction?";
			cin>>y;
			if(y==1)	  			
	  	  	cout<<"Payment by card successful\n";
	  	  	else
	  	  	cout<<"Payment not successful\n";
	  	  	}
	  	  delete_record(company,name);			//ERROR!
	  	  carray[totcars]=cobj;
		  totcars++;
	  	}

	  }	
	};
class service:public shipping
	{
	 
	  float tax;
	  string company;
	  string name;
	  float labour;
	  int time;
	  float parts;
	  car cobj;
	  float total,shipflag,shipcost;
	  int payment;
	  
	  string cname,cadd;
	  int phone,ssn;

	  public:
	  void display()
	  {
	  	cout<<"company"<<company<<endl;
	  	cout<<"model"<<name<<endl;
	  	cout<<"payment"<<payment<<endl;
	  	cout<<"name"<<cname<<endl;
	  	cout<<"phone"<<phone<<endl;
	  	cout<<"address"<<cadd<<endl;
	  	cout<<"ssn"<<ssn<<endl;
	  	cout<<"labour:\t"<<labour<<endl;
	  	cout<<"parts:\t"<<parts<<endl;
	  	cout<<"shipingcost"<<shipcost<<endl;
		cout<<"service cost:"<<cobj.servicing_cost<<endl;
		cout<<"tax"<<tax<<endl;
		cout<<"-----------------------\n";
		cout<<"total\n"<<total<<endl;	  
	  
	  }
	  void input()
	  {
	  
	  cout<<"enter the company\n";
	  cin>>company;
	  cout<<"enter the name\n";
		cin>>name;
		int search_record(company,name);
		if(flag==-1)
		{
		cout<<"car not found\n";
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
	  	cout<<"Enter the time needed to repair";
	  	cin>>time;
	  	cout<<"enter the parts cost\n";
	  	cin>>parts;
	  	labour=time*200;
	  	total=labour+parts+tax+cobj.servicing_cost+shipcost;
	   }
	  void generate_bill()
	  {
	  	
	  	input();
	  	cout<<"Do you want shipping 1- yes 2- no";
	  	cin>>shipflag;
	  	if(shipflag==1)
	  	{
	  	shipcost=calculate_shipping(cobj.shipping_cost);
	  	
	  	}
	  	
	  	cout<<"Enter customer name\n";
	  	cin>>cname;
	  	int phone;
	  	cout<<"Enter customer phone number \n";
	  	cin>>phone;
	  	
	  	cout<<"Enter Customer Address\n";
	  	
	  	cin>>cadd;
	  	cout<<"Enter Customer SSN\n";
	  	
	  	cin>>ssn;
	  	calculate_service();
	  	cout<<"Thank you for shopping\n";
	  	cout<<"\t\t\tbill\n";
	  	cout<<"Name:\t"<<cname<<"\t\tAddress\t\t"<<cadd<<endl;
	  	cout<<"Phone\t"<<phone<<"\t\tSSN\t\t"<<ssn<<endl;
	  	
	  	
	  	cout<<"service cost:"<<cobj.servicing_cost<<endl;
	  	cout<<"tax:\t"<<tax<<endl;
	  	cout<<"labour:\t"<<labour<<endl;
	  	cout<<"parts:\t"<<parts<<endl;
	  	cout<<"shipping:\t"<<shipcost<<endl;
	  	cout<<"-----------------------\n";
	  	cout<<"total\n"<<total<<endl;
	  	cout<<endl<<endl<<"Please pay the amount\n";
	  	cout<<"Customer wants to pay by cash(1) or card(2)?\n";
	  	cin>>payment;
	  	if(payment<=2&&payment>0)
	  	{	int y;
	  		if(payment==1){
			cout<<"Has the customer paid the cash?";
			cin>>y;
			if(y==1)	  			
	  	  	cout<<"Payment by cash successful\n";
	  	  	else
	  	  	cout<<"Payment not successful\n";
	  	  	}
	  	  	if(payment==2){
			cout<<"Has the bank confirmed the transaction?";
			cin>>y;
			if(y==1)	  			
	  	  	cout<<"Payment by card successful\n";
	  	  	else
	  	  	cout<<"Payment not successful\n";
	  	  	}
	  	
	  	}
	   }	
	};
	service aservice[1000];
	int nservice=0;
class rent:public shipping{
	float tax;
	string company;
	string name;
	car cobj1;
	float time;
	float rentt,shipcost;
	int total,shipflag;
	int payment,wpayment;
	string cname,cadd,col;
	  int phone,ssn;

	public:
	 void display()
	  {
	  	cout<<"company"<<company<<endl;
	  	cout<<"model"<<name<<endl;
	  	cout<<"color"<<col<<endl;
	  	cout<<"payment"<<payment<<endl;
	  	cout<<"name"<<cname<<endl;
	  	cout<<"phone"<<phone<<endl;
	  	cout<<"address"<<cadd<<endl;
	  	cout<<"ssn"<<ssn<<endl;
	  	cout<<"time\t"<<time<<endl;
	  	
	  	cout<<"shipingcost"<<shipcost<<endl;
		cout<<"rent cost:"<<cobj1.renting_cost<<endl;
		cout<<"tax"<<tax<<endl;
		cout<<"-----------------------\n";
		cout<<"total\n"<<total<<endl;	  
	  
	  }
	void input()
	  {
	  
	  	cout<<"enter the company\n";
	  	cin>>company;
	  	cout<<"enter the name\n";
	  	cin>>name;
	  	int flag;
	  	flag=search_record(company,name);
		if(flag==-1)
		{
		cout<<"car not found\n";
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
	         tax=0.14*rentt;
		 total=rentt+tax+shipcost;
	   }
	   void generate_temp_bill()
	  {
	  	input();
	  	cout<<"Do you want shipping 1- yes 2- no";
	  	cin>>shipflag;
	  	if(shipflag==1)
	  	{
	  	shipcost=calculate_shipping(cobj1.shipping_cost);
	  	
	  	}
	  	string col;
	  	cout<<"enter color of the car\n";
	  	cobj1.avail_col();
	  	cin>>col;
	  	
	  	calculate_rent();
	  	
	  	cout<<"\t\t\tbill\n";
	  	
	  	cout<<"cost of car per hour:"<<cobj1.renting_cost<<endl;
	  	cout<<"time used:"<<time<<endl;
	  	cout<<"total rent:"<<rentt<<endl;
	  	cout<<"tax:\t"<<tax<<endl;
	  	cout<<"shipping:\t"<<shipcost<<endl;
	  	cout<<"-----------------------\n";
	  	cout<<"total\n"<<total;
	  	cout<<endl<<endl<<"does customer want to rent the car?\n";
	  	cin>>wpayment;
	  	if(wpayment==1)
	  	{
	  	generate_bill();
	  	 }

	  }	
	  
	  void generate_bill()
	  {
	  	
	  	
	  	cout<<"Enter customer name\n";
	  	cin>>cname;
	  	int phone;
	  	cout<<"Enter customer phone number \n";
	  	cin>>phone;
	  	
	  	cout<<"Enter Customer Address\n";
	  	
	  	cin>>cadd;
	  	cout<<"Enter Customer SSN\n";
	  	
	  	cin>>ssn;
	  	cobj1.rent_car(col);
	  	calculate_rent();
	  	cout<<"Thank you for shopping with us\n";
	  	cout<<"\t\t\tBill\n";
	  	cout<<"Name:\t"<<cname<<"\t\tAddress\t\t"<<cadd<<endl;
	  	cout<<"Phone\t"<<phone<<"\t\tSSN\t\t"<<ssn<<endl;
	  
	  
	  	cout<<"cost of car per hour:"<<cobj1.renting_cost<<endl;
	  	cout<<"time used:"<<time<<endl;
	  	cout<<"total rent:"<<rentt<<endl;
	  	cout<<"Tax amount @14%:\t"<<tax<<endl;
	  	cout<<"shipping:\t"<<shipcost<<endl;
	  	cout<<"-----------------------\n";
	  	cout<<"total\n"<<total;
	  	
	  	cout<<"-----------------------\n";
	  	
	  	cout<<endl<<endl<<"Please pay the amount\n";
	  	cout<<"Customer wants to pay by cash(1) or card(2)?\n";
	  	cin>>payment;
	  	if(payment<=2&&payment>0)
	  	{	int y;
	  		if(payment==1){
			cout<<"Has the customer paid the cash?";
			cin>>y;
			if(y==1)	  			
	  	  	cout<<"Payment by cash successful\n";
	  	  	else
	  	  	cout<<"Payment not successful\n";
	  	  	}
	  	  	if(payment==2){
			cout<<"Has the bank confirmed the transaction?";
			cin>>y;
			if(y==1)	  			
	  	  	cout<<"Payment by card successful\n";
	  	  	else
	  	  	cout<<"Payment not successful\n";
	  	  	}
	  	
	  	  delete_record(company,name);			//ERROR!
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
int search_record(string company,string name)
	{
		car cobj1;
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
		return -1;
		}
		else
		{
		cout<<"available";
		return 0;
		}
		break;
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
		
		string company,name;
		cout<<"enter company name \n";
		cin>>company>>name;
		int flag;
		flag=search_record(company,name);
		if(flag==-1)
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
		int flag,i;
		flag=search_record(company,name);
		
		if(flag==-1)
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
sell sarray[1000];
int sellen=0;
rent rarray[1000];
int relen;
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
		cout<<"\nChoose :\n\t1. Add Car \n\t2. Sell Car \n\t3.Rent Car \n\t4. Repair Car \n\t 5.admin data\n\t0. Logout !\n\n";
		cin>>choice;
		if(choice==1){
			modify_database();
		}
		else if(choice==2)
		{
		sell seobj;
		seobj.generate_temp_bill();
		sarray[sellen]=seobj;
		sellen++;	
		
		}
		else if(choice==3)
		{
		rent reobj;
		reobj.generate_temp_bill();
		rarray[relen]=reobj;
		relen++;	
		
		}
		else if(choice==4)
		{
		 service sobj;
		 sobj.generate_bill();
		 aservice[nservice]=sobj;
		 nservice++;
		
		}
		else if(choice==5){
		int ch;
		cout<<"enter choice 1-check database 2- check sales 3- check service 4- check rent 5- break\n";
		cin>>ch;
		if(ch==1)
		{
			car cobj;
			for(int i=0;i<totcars;++i)
			{
				carray[i].display();
				cout<<endl;
			}
		
		}
		else if(ch==2)
		{
			sell sobj;
			for(int i=0;i<sellen;++i)
			{
				sarray[i].display();
				cout<<endl;
			}
		
		}
		else if(ch==4)
		{
			sell sobj;
			for(int i=0;i<sellen;++i)
			{
				sarray[i].display();
				cout<<endl;
			}
		
		}
		else if(ch==3)
		{
			sell sobj;
			for(int i=0;i<nservice;++i)
			{
				aservice[i].display();
				cout<<endl;
			}
		
		}
		}
		else if(choice==0)
		{
		goto ID;
		}			
		}

return 0;
}
