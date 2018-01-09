#include<stdio.h>
#include<string.h>
int main()
{
char s[100][100];
char c1[100];
int ctr=0,i,j;
int ch;
while(1)
{
printf("enter your choice 1-create 2-delete\n");
scanf("%d",&ch);
if(ch==1)
{
	printf("enter the file name\n");
	scanf("%s",s[ctr]);
	++ctr;
	int flag=0;
	for(i=0;i<ctr-1;++i)
	   if(strcmp(s[ctr-1],s[i])==0)
	   {
	      flag=1;
	   }
	if(flag==1)
	{
	     printf("file already exists\n");
	     --ctr;
	}
}
if(ch==2)
{
		printf("enter the file name\n");
		scanf("%s",c1);
		int flag=0;
		for(i=0;i<ctr;++i)
	        if(strcmp(c1,s[i])==0)
	        {
	            
	            flag=1;
	            for(j=i;j<ctr-1;++j)
	            {
	                 strcpy(s[i],s[i+1]);
	            }
	            ctr=ctr-1;
	            break;
	        }
	        if(flag==0)
	        {
	        printf("deletion failed");
	        }
		

}
if(ch==3)
break;

}


return 0;
}
