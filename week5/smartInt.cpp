#include<iostream>
#include<stdlib.h>
using namespace std;
class smartInt{
   int * a;
   int size;
   public:
   	smartInt();
   	smartInt(int );
   	~smartInt();
   	void input();
   	void display();
   	void display(int n);
   	void insert(int, int);
   	void remove(int);
   	int second();
   	void sort();
   	void randomize();
   	void frequency();
};
smartInt::smartInt()
	{
	 	size=10;
	 	a=new int[10];
	 	for(int i=0;i<size;++i)
	 		a[i]=0;
	 }
smartInt::smartInt(int n)
	{
		size=n;
		a=new int[size];
		for(int i=0;i<size;++i)
			a[i]=0;
			
	}
smartInt::~smartInt()
	{
		size=0;
		delete a;
		cout<<"desructed"<<endl;
	}	
void smartInt::input()
	{
		delete a;
		cout<<"enter size\n";
		cin>>size;
		a=new int[size];
		for(int i=0;i<size;++i)
			cin>>a[i];
		cout<<endl;
	}
void smartInt::display()
	{
	
		for(int i=0;i<size;++i)
			cout<<a[i]<<" ";
		cout<<endl;
	}
void smartInt::display(int n)
	{	if(n>=size)
	       		cout<<"invalid"<<endl;
		else
			cout<<a[n]<<endl;
	}
void smartInt::remove(int pos)
	{ 
	       if(pos>=size)
	       		cout<<"invalid"<<endl;
	       else
	       {
			for(int i=pos;i<size-1;++i)
			    a[i]=a[i+1];
			    a[size]=-9999;
			    size--;
	       }
	  	
	}
void smartInt::insert(int n,int pos)
	{
		if(pos>size)
			cout<<"invalid"<<endl;
		else if(a[size]==-9999)
		{
			for(int i=size-1;i>=pos;--i)
				a[i+1]=a[i];
			++size;
			a[pos]=n;
		}
		else
		{
		       int *b;
			++size;
			b=new int[size];
			for(int i=0;i<pos;++i)
			 {
			 	b[i]=a[i];
			 }		
			b[pos]=n;
			int ctr=pos+1;
			for(int i=pos;i<size-1;++i)
			 {
			 	b[ctr]=a[i];
			 	++ctr;
			 }	
			 delete a;
			 a=new int[size];
			 a=b;
		
		}	      
		
	}
int smartInt::second()
	{
		int f=a[0];
		int second=-9999;
		int flag=0;
		for(int i=0;i<size;++i)
		    {
		    	if(a[i]>f)
		    	   {	
		    	        second=f;
		    	   	f=a[i];
		    	   	flag=1;
			   }	    	   	
		    }
		if(flag==0)
		   {
			   for(int i=1;i<size;++i)
			    {
			    	if(a[i]>second)
			    	   {	
			    	   	second=a[i];
			    	   	flag=1;
				   }	    	   	
			    }
			   
		   
		   }	    
		    		
	}
void smartInt::sort()
	{
	int i,j;
	int temp;
        for(i=0;i<size;++i)
        {
                temp=a[i];
                for(j=i-1;j>=0;--j)
          {
                if(temp>a[j])
                 {   
                    break;
                }
                a[j+1]=a[j];
          }
                a[j+1]=temp;
        
        }    
	}
void smartInt::frequency()
	{
		int f[size];
		for(int i=0;i<size;++i)
		   {
		   f[i]=0;
		   }
		
		for(int i=0;i<size;++i)
		    {
		    int ctr=1;
		       if(f[i]==0)
		       {
		        for(int j=i+1;j<size;++j)
		        	{
		        		if(a[i]==a[j])
				 	 {
				 	 ++ctr;	
				 	 ++f[j];
				 	 }
		        	}
		        cout <<a[i]<< "has frequency" <<ctr<<endl;
		        }
		    
		    }
	
	}
void smartInt::randomize()	
	{
	 int *b=new int[size];
	int f[size];
		for(int i=0;i<size;++i)
		   {
		   f[i]=0;
		   }
		   int ctr=0;
		   while(ctr<size)
		   {
		   int te=rand()%size;
		     if(f[te]==0)
		     {
		      b[ctr]=a[te];
		      ++ctr;
		      ++f[te];
		     }
		   }
		   delete a;
		   a=b;
		  
	}
int main()
	{
		smartInt s1;
		s1.display();
		cout<<endl;
		smartInt s2(5);
		s2.display();
		cout<<endl;
		s2.input();
		cout<<endl;
		s2.display();
		cout<<endl;
		s2.display(4);
		cout<<endl;
		s2.remove(3);
		s2.display();
		cout<<endl;
		s2.insert(511,7);
		s2.display();
		cout<<endl;
		s2.frequency();
		s2.sort();
		s2.display();
		cout<<endl;
		s2.randomize();
		s2.display();
		return 0;
	}
