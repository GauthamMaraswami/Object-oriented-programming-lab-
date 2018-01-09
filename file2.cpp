#include<fstream>
#include<iostream>
using namespace std;
int main()
{
	char story[100],story1[100];
	fstream fobj("story1.dat",ios::out|ios::binary);	
	cout<<"enter your story\n";
	cin.getline(story,0100);
	fobj.write(story,sizeof(story));
	
	//story="alarm";
	fobj.close();
	fobj.open("story1.dat",ios::in|ios::binary);
	//fobj>>story1;
	while(!fobj.eof())
	{
	fobj.read(story1,sizeof(story1));
	cout<<story1<<endl;
	}

	cout<<"your story"<<story1;
	fobj.close();
}
