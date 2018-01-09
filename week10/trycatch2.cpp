#include<iostream>
#include<exception>
using namespace std;
class subRange
{ 
public: 
subRange( int, int );  
int getValue(); 
private:   int lower, upper;
};  
subRange::subRange( int low, int high )
{ 
lower = low;  upper = high;
}  
int subRange::getValue()
{ 
int v; 
cout << "Enter value [ " << lower << ", " << upper << " ]: "; 
cin >> v; 
if(v<lower)
	throw 'l';
else if(v>upper)
	throw 'g';
return v;
}
/*try{
if(v<lower)
	throw 'l';
else if(v>upper)
	throw 'g';
}
catch(char re)
{
	if(re=='l')
	{
	cout<<"low\n"<<endl;
	}
	else if(re=='g')
	cout<<"bigger\n";
	return this->getValue();
}
*/

  
int main()
{ 
subRange x(1,10);
while(1){  
try{
cout << x.getValue( ) << endl;
break;
}
catch(char re)
{
	if(re=='l')
	{
	cout<<"low\n"<<endl;
	}
	else if(re=='g')
	cout<<"bigger\n";
	//return this->getValue();
}
}
return 0;
} 
