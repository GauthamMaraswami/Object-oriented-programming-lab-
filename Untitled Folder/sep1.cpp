
#include <iostream>
#include <fstream>
using namespace std;
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
	int add_car(){
	         cout<<"enter company\n";
	         cin>>company;
	         cout<<"model name\n";
	         cin>>company;
	         cout<<"enter year\n";
	         cin>>year;
	         cout<<"enter no of colors\n";
	         cin>>ncoloors;
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
	   	return no_rent;
	   }
	};
	
class sell
	{
	  float ship_dist;
	  string date;
	  float tax;
	  string company;
	  string name;
	  car cobj1;
	  public:
	  void input(){
	  
	  cout<<"enter the company\n";
	  cin>>company;
	  cout<<"enter the name\n";
	  cin>>name;
	  
	  
	  }	
	};
 

int main () {
  ofstream myfile ("example.txt");
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
