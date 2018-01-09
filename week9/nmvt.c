#include<stdio.h> 
void main() 
{ 
	int m=0,m1=0,m2=0,p,count=0,i,ctr=0; 
	printf("Enter the total memory capacity:"); 
	scanf("%d",&m); 
	
	printf("enter the choice 1- Add process 2- delete process 3-display 4- exit")
	scanf("%d",&ch); 
	switch(ch)
	{
	    case 1:
	    {
	    printf("\nEnter the memory required for process:%d",ctr); 
		scanf("%d",&m1); 
	    count=count+m1; 
		if(m1<=m) 
		{ 
			if(count==m) 
			{ 
				printf("There is no more memory remaining:"); 
			} 
			else 
			{ 
				printf("The memory allocated for process is: %d ",m); 
				
				m2=m-m1; 
				printf("\nRemaining memory is: %d",m2); 
				m=m2; 
			} 
		} 
		else 
		{ 
			printf("Memory is not allocated for process"); 
		} 
			printf("\nExternal fragmentation for this process is:%d",m2); 
	    break;
	    }
	    case 2:
	    {
	    
	    
	    
	    }
	
	
	
	
	
	}
	
	
	
	
	
	
	
	
	
	printf("Enter the no of processes:"); 
	scanf("%d",&p); 
	for(i=0;i<p;i++) 
	{ 
		printf("\nEnter memory required for process%d: ",i+1); 
		scanf("%d",&m1); 
		count=count+m1; 
		if(m1<=m) 
		{ 
			if(count==m) 
			{ 
				printf("There is no more memory remaining:"); 
			} 
			else 
			{ 
				printf("The memory allocated for process%d is: %d ",i+1,m); 
				m2=m-m1; 
				printf("\nRemaining memory is: %d",m2); 
				m=m2; 
			} 
		} 
		else 
		{ 
			printf("Memory is not allocated for process%d",i+1); 
		} 
			printf("\nExternal fragmentation for this process is:%d",m2); 
	} 

} 
