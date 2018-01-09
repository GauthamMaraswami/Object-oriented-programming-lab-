#include<stdio.h> 
void main() 
{ 
	int m,p,s,p1; 
	int m1[4],i,f,f1=0,f2=0,fra1,fra2,s1; 
	printf("Enter the memory size:"); 
	scanf("%d",&m); 
	printf("Enter the total no of partitions:"); 
	scanf("%d",&p); 
	s=m/p; 
	printf("Each partition size is:%d",s); 
	printf("\nEnter the total no of processes:"); 
	scanf("%d",&p1); 
	for(i=0;i<p1;i++) 
	{ 
		printf("\nEnter the memory required for process%d:",i+1); 
		scanf("%d",&m1[i]); 
		if(m1[i]<=s) 
		{ 
			printf("\nProcess is allocated in partition no %d",i+1); 
			fra1=s-m1[i]; 
			printf("\nInternal fragmentation for process is:%d",fra1); 
			f1=f1+fra1;
		} 
		else 
		{ 
			printf("\nProcess not allocated in any partition%d",i+1); 
			int j;
			for(j=0;j<p1;++j)
			{
			
			}
			printf("\nExternal fragmentation for partition is:%d",fra2); 
		} 
	} 
printf("\nProcess\tmemory\talloatedmemory"); 
for(i=0;i<p1;i++) 
	printf("\n%5d\t%5d\t%5d",i+1,s,m1[i]); 
f=f1+f2;
printf("\nThe tot no of fragmentation is:%d",f); 
} 

