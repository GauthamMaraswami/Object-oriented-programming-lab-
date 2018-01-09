#include<iostream>
using namespace std;
class base
{
public:
 virtual void show()
{
cout<<"Father\n";
}

};
class son:public base
{
void show()
{
cout<<"son\n";
}

};
int main()
{
base *b,c;
b=&c;
b->show();
son d;
b= &d;
b->show(); 


}
