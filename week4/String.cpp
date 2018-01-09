#include<iostream>
using namespace std;
class STRING{
private:
     char* str;
     int len;
public:
     STRING();
     STRING(STRING &arg);
     STRING(char *st);
     
     int getlen();
     void display();
     
     STRING append(STRING &arg);
     STRING append(char *st);
     void replace(char c,int loc);
     void replace (char cur,char newchar);
     
     int find(char *substr);
     STRING reverse();
     STRING operator +(STRING &arg)
     {
        int te1=arg.getlen();
	int te2=len;
	len=te1+te2;
	char* str1;
        str1= new char[len+1];
        for(int i=0;i<te2;++i)
	   str1[i]=str[i];
	   int ctr=te2;
	for(int i=0;i<te1;++i)
	   {
	   str1[ctr]=arg[i];
	   ++ctr;
	   }
	str1[ctr]='\0';
	STRING S(str1);
	return S;
     
     
     }
     char operator [](int k)
     {
          return str[k];
     }
};
STRING::STRING()
{
	str=NULL;
	len=0;

}
STRING::STRING(STRING &arg)
{
	len=arg.getlen();
	str= new char[len+1];
	int i;
	for( i=0;i<len;++i)
	   str[i]=arg[i];
	str[i]='\0';
}
STRING::STRING(char* st)
{
  int ctr=0;
  while(st[ctr]!='\0')
     {
    	++ctr;
     }
    len=ctr;
    str= new char[len+1];
    int i;
    for( i=0;i<len;++i)
	   str[i]=st[i];
	   str[i]='\0';
}

int STRING::getlen()
{

return len;

}
void STRING::display()
{
	for(int i=0;i<len;++i)
	  cout<<str[i];
}
STRING STRING::append(STRING &arg)
{
	int te1=arg.getlen();
	int te2=len;
	len=te1+te2;
	char* str1;
        str1= new char[len+1];
        for(int i=0;i<te2;++i)
	   str1[i]=str[i];
	   int ctr=te2;
	for(int i=0;i<te1;++i)
	   {
	   str1[ctr]=arg[i];
	   ++ctr;
	   }
	str1[ctr]='\0';
	STRING S(str1);
	return S;
}
 STRING STRING::append(char *st){
    int ctr=0;
    while(st[ctr]!='\0')
     {
     ++ctr;     
     }
     int te2=ctr;
     char* str1;
        str1= new char[len+1];
 	for(int i=0;i<len;++i)
	   str1[i]=str[i];
 	  ctr=len;
	for(int i=0;i<te2;++i)
	   {
	   str1[ctr]=st[i];
	   ++ctr;
	   }
 	str1[ctr]='\0';
	STRING S(str1);
	return S;
 }
void STRING::replace(char c,int loc)
{
	if(loc>=len)
	  cout<<"invalid location\n";
	else
	   str[loc]=c;
}

void STRING::replace(char cur,char newchar)
{
        for(int i=0;i<len;++i)
          {
            if(str[i]==cur)
               str[i]=newchar;
          }
}




int STRING::find(char *substr)
{
      int ctr=0;
  while(substr[ctr]!='\0')
     {
    	++ctr;
     }
     if(ctr>len)
     {
       return -1;
     }
     else
     {    
	int flag=0;
	int flag1,i;
	for( i=0;i<len;++i)
	  {  flag1=0;
	     if(str[i]==substr[0])
	       {
	         for(int j=0;substr[j]!='\0';++j)
	            {
	              if(str[i+j]!=substr[j])
	              {
	                 flag1=1;
	                 break;
	               }
	                 
	            }
	            if(flag1==0)
	            {
	               flag=1;
	              return i;
	            }
	       }
	  }
	 return -1;
	  if(flag==0)
	     return -1;
	  else
	     return i;
	}

}

STRING STRING::reverse()
{
  int ctr=0;
  char* str1= new char[len+1];
   for(int i=len-1;i>=0;--i)
      {
      		str1[ctr]=str[i];
      		++ctr;
      }
      str1[ctr]='\0';
      STRING S(str1);
   return S;

}


int main()
{
 	STRING st1;
 	char c[10];
 	int len;
 	cin>>len;
 	for(int i=0;i<len;++i)
 	{
 	  cin>>c[i];
 	}
 	c[len]='\0';
 	STRING st2(c);
 	
 	cout<<"STRING2 argument executed"<<endl;
 	st2.display();
 	cout<<endl;
 	cout<<"STRING2 reverse executed"<<endl;
 	st2.reverse().display();
 	cout<<endl;
 	STRING st3(st2);
 	st3.display();
 	cout<<"enter len and  string to append\n";
 	cin>>len;
 	for(int i=0;i<len;++i)
 	{
 	  cin>>c[i];
 	}
 	cout<<endl;
 	st3=st3.append(c);
 	cout<<endl;
 	st3.display();
 	st2=st2.append(st3);
 	cout<<endl;
 	st2.display();
 	cout<<endl;
 	st2.replace('m',2);
 	st2.display();
 	cout<<endl;
 	st2.replace('h','z');
 	st2.display();
 	cout<<endl;
 	cout<<"enter len and string to search\n";
 	char c1[10];
 	cin>>c1;
 	cout<<st2.find(c1);
 	
 	st2=st2+st1;
 	st2.display();
 	
 	 return 0;
}
