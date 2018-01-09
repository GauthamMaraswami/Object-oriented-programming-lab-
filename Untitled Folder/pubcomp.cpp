#include<iostream>
#include<cstring>
using namespace std;
class publication
{
	private:
		string publisher;
		string tittle;
		float price;
	
	
	public:
		publication(string s, float am)
		{
		tittle=s;
		price=am;
		}
		publication()
		{
			tittle="";
			price=0.00;
		}
		string getpubname()
		{
		 return publisher;
		}
		void getdata()
		{
			cout<<"input publisher"<<endl;
			cin>>publisher;
			cout<<"input tittle "<<endl;
			cin>>tittle;
			cout<<"input price "<<endl;
			cin>>price;
		
		}
		void putdata()
		{
			cout<<"publishre"<<publisher<<endl;
			cout<<"tittle :"<<tittle<<endl;
			cout<<" price :"<<price<<endl;	
		} 
	
};
class book:public publication
{
	private:
	
		int pageCount;
	
	
	public:
		
	
		book()
		{
			pageCount=0;
		}
		
		void getdata()
		{
			publication::getdata();
			cout<<"input pageCount "<<endl;
			cin>>pageCount;
			
		
		}
		void putdata()
		{
			publication::putdata();	
			cout<<"pageCount: "<<pageCount<<endl;
			
		} 

};


class casette:public publication
{
	private:

		int tapelen;
	
	
	public:
	
		casette()
		{
			tapelen=0;
		}
		void getdata()
		{
			publication::getdata();
			cout<<"input tapelen "<<endl;
			cin>>tapelen;
			
		
		}
		void putdata()
		{
			publication::putdata();	
			cout<<"tapelen "<<tapelen<<endl;
			
		} 
	
};
int main()
{
	int n,cb=0,cc=0,type;

	cout<<"enter the numb of objects\n";
	cin>>n;
	book b[n];
	casette c[n];
	for(int i=0;i<n;++i)
	{
		cout<<"enter the type of object 1-book 2- type "<<endl;
		cin>>type;
		if(type==1)
		{
		 
		 b[cb].getdata();
		 ++cb;
		}
		else if(type==2)
		{
		 
		 c[cc].getdata();
		 ++cc;
		}
		
	
	}
	cout<<endl;
	cout<<"books"<<endl;
	for(int i=0;i<cb;++i)
	  b[i].putdata();
	  cout<<endl;
	cout<<"casettes"<<endl;
	for(int i=0;i<cc;++i)
	  c[i].putdata();
	  
	  cout<<"enter publisher whom to check";
	  string pname;
	  cin>>pname;
	  cout<<"books under the publisher";
	  for(int i=0;i<cb;++i)
	{
	  if(b[i].getpubname()==pname)
	     b[i].putdata();

	}
	 for(int i=0;i<cc;++i)
	{
	  if(c[i].getpubname()==pname)
	     c[i].putdata();

	}
return 0;
}
