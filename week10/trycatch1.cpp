#include<iostream>
#include<exception>
using namespace std;
class array{
int* elts;
int count;
public:
array(long long int l);

};
array::array(long long int sz)
{
count=sz;
elts=new int[count];
}
int main()
{
array * ptr[10];
for(int I=0;I<10;++I)
	{
	try{
	ptr[I]=new array(10000000000000);
	}
	catch(exception &e)
	{
	
	cout<<"error"<<endl<<e.what()<<endl;
	}
	}

return 0;
}
