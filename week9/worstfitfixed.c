#include<stdio.h>

void main()
{
        int m,p,p1[100],i,j,ct=0,pn,m1[100],ctr,flag[100],f1=0,tmused=0,f2=0,flag1,fra1,fra2;
        int lar[100];
	printf("Enter the memory size:"); 
	scanf("%d",&m); 
	printf("Enter the total no of partitions:"); 
	scanf("%d",&p); 
	printf("Enter the partition sizes:");
	for(i=0;i<p-1;++i)
		{
		scanf("%d",&p1[i]); 
		ct+=p1[i];
		flag[i]=0;
		}
	p1[p-1]=m-ct;
	flag[p-1]=0;
	
	printf("\nEnter the total no of processes:"); 
	scanf("%d",&pn); 
	for(i=0;i<pn;i++) 
	{ 
		flag1=0;
		ctr=0;
		printf("\nEnter the memory required for process%d:",i+1); 
		scanf("%d",&m1[i]);
		int posx,posy=-1;
		
		for(j=0;j<p;++j)
		{ 
		        if(flag[j]==0&&p1[j]>=m1[i])
			{
			posx=j;
			break;
			} 
		}
		//printf("jj%dnn",posx);
		int te=p1[posx];
		for(j=0;j<p;++j)
		{
		 if(p1[j]>=te&&m1[i]<=p1[j]&&flag[j]==0)
		   {
		    posy=j;
		    te=p1[j];
		    }
		
		}
		if(posy>=0)
			{
				printf("\nProcess is allocated in partition no %d",posy+1); 
				flag[posy]=1;
			        fra1=p1[posy]-m1[i];
			        printf("\nInternal fragmentation for process is:%d",fra1); 
				f1=f1+fra1;
				tmused+=p1[posy];
				flag1=1;
				if(f2>0)
					f2-=p1[posy];
			}
		if(flag1==0)
		{
		    if((m-tmused)>m1[i])
		    {
		        fra2=0;
		        for(j=0;j<p;++j)
		        {
		            if(flag[j]==0)
		            {
		            fra2+=p1[j];
		            }
		        }
		    	
		    	f2=fra2;
		    	printf("\ncannot accomodate external fragmentation=%d",f2);
		    }
		   else
		    {
		    	
		    	printf("\ncannot accomodate not enough space");
		    }
		    
		
		}
	}
	printf("total external fragmentation=%d\n",f2);
	printf("total internal fragmentation=%d\n",f1);
}	
	
	
	
	
	
	
	
	
	
	
	

