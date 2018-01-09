#include<iostream>
using namespace std;

int main(){
	int i,j,reg[5]={0},m=3,n,ip[50],state[8]={0,1,2,3,4,5,6,7},op[200];

	cout<<"\nEnter no. of bits";
	cin>>n;
	cout<<"\nEnter the input bit sequence";
	for(i=0;i<n;i++)
		cin>>ip[i];
	int counter=0;
	for(i=0;i<n;i++){
		for(j=0;j<=3;j++){
			reg[j+1]=reg[j];
		}
		reg[0]=ip[i];
		op[counter]=reg[3]^reg[2]^reg[1]^reg[0]	;
		counter++;
		op[counter]=reg[0]^reg[1]^reg[3];
		counter++;
	}
	for(i=0;i<5;i++){
	for(j=0;j<=3;j++){
			reg[j+1]=reg[j];
		}
		reg[0]=0;
		op[counter]=reg[3]^reg[2]^reg[1]^reg[0]	;
		counter++;
		op[counter]=reg[0]^reg[1]^reg[3];
		counter++;
	}
	for(i=0;i<counter;i++)cout<<op[i];	
	
	return 0;
}
