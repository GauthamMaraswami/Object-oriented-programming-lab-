#include<fstream>
#include<iostream>
using namespace std;
int main()
{
	char story[100],story1[100];
	fstream fobj("story.txt",ios::out);	
	cout<<"enter your story\n";
	cin.getline(story,0100);
	fobj<<story;
	
	//story="alarm";
	fobj.close();
	fobj.open("story.txt",ios::in);
	int p;
	p=8;
	fobj.seekg(p);
	fobj>>story1;
	cout<<"your story"<<story1;
	fobj.close();
}
