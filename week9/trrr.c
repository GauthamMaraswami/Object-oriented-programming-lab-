#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct dir{
char dname[15];
struct dir* par;
struct dir* chil[50];
char fname[15][15];
int cds;
int cfs;
};
int mkdir(char c[15],struct dir* cur)
{
        int i,flag=0;
	for(i=0;i<cur->cds;++i)
		{
			struct dir *tes=(struct dir*) malloc(sizeof(struct dir));
			tes=cur->chil[i];
			if(strcmp(tes->dname,c)==0)
			{
			flag=1;
			}
			
		}
		if(flag==0){
		   cur->cds+=1;
		   struct dir *tes=(struct dir*) malloc(sizeof(struct dir));
		   strcpy(tes->dname,c);
		   tes->cds=0;
		   tes->cfs=0;
		   tes->par=cur;
		   cur->chil[(cur->cds)-1]=tes;
		   return 0;
		
		
		}
		else return -1;


}



int main()
{
 char c[15];
 int ret,opt;
 struct dir *cur=(struct dir*) malloc(sizeof(struct dir));
 strcpy(cur->dname,"root\0");
 cur->par=NULL;
 cur->cfs=0;
 cur->cds=0;
while(1)
{
printf("Enter option: (0)go back(1)create directory (2)change dir (3) Create file (4) Delete file (5) Delete directory (6) Display file system (7) Exit\n");
		scanf("%d", &opt);
	switch(opt)
	{
	case 0:
	{
	if(strcmp(cur->dname,"root")==0)
	{
	printf("failure");
	
	}
	else
	{
	   cur=cur->par;
	}
	break;	
	}
	case 1:
	{
	    printf("enter directory name\n");
	    scanf("%s",c);
	    ret=mkdir(c,cur);
	    if(ret==0)
	    {
	    printf("successful\n");
	    
	    }
	    else if(ret==-1)
	    {
	    printf("failure\n");
	    }
	    break;
	}
	case 2:
	{
	printf("enter directory name\n");
	    scanf("%s",c);
	    struct dir *tes=(struct dir*) malloc(sizeof(struct dir));
	    int i;
	    int ct=-1;
	    for(i=0;i<cur->cds;++i)
	    {
	    tes=cur->chil[i];
	    if(strcmp(tes->dname,c)==0)
	       {
	       ct=i;
	       break;
	       }
	        
	    }
	    if(ct!=-1)
	    {
	    cur=cur->chil[ct];
	    }
	    else
	    ("printf failure\n");
	break;
	}
	case 3:
	{
		printf("enter the file name\n");
		scanf("%s",c);
		strcpy(cur->fname[cur->cfs],c);
		++cur->cfs;
		int flag=0;
		int i;
		for(i=0;i<cur->cfs-1;++i)
	 		  if(strcmp(cur->fname[i],c)==0)
	  		 {
	      			flag=1;
	   		}
		if(flag==1)
		{
	     		printf("file already exists\n");
	     		--cur->cfs;
		}
	break;
	
	}
	case 4:
	{
		printf("enter the file name\n");
		scanf("%s",c);
		int flag=0;
		int i,j;
		for(i=0;i<cur->cfs;++i)
	        if(strcmp(c,cur->fname[i])==0)
	        {
	            flag=1;
	            for(j=i;j<(cur->cfs-1);++j)
	            {
	                 strcpy(cur->fname[i],cur->fname[i+1]);
	            }
	             --(cur->cfs);
	            break;
	           
	        }
	        if(flag==0)
	        {
	        printf("deletion failed");
	        }
	        break;
	
	}
	case 5:
	{
	printf("enter directory name\n");
	    scanf("%s",c);
	    int ct=-1;
	    	struct dir *tes=(struct dir*) malloc(sizeof(struct dir));
	    	int i;
	 for(i=0;i<cur->cds;++i)
	 {
	  tes=cur->chil[i];
	    if(strcmp(tes->dname,c)==0)
	       {
	        ct=i;
	       break;
	       }
	    
	 
	 }
	  if(tes->cds!=0&&tes->cfs!=0)
	  {
	  printf("unable to delete");
	  }
	 else
	 {
	  cur->cds-=1;
	 printf("delete successful\n");
	}
	}
	case 6:
	{
	int flag=0;
		int i,j;
		for(i=0;i<cur->cfs;++i)
		printf("%s\n",cur->fname[i]);
		for(i=0;i<cur->cds;++i)
		{
			struct dir *tes=(struct dir*) malloc(sizeof(struct dir));
			tes=cur->chil[i];
			printf("%s\n",tes->dname);
		}
	        
	        break;
	
	}
	case 7:
	{
	exit(0);
		
	}
	
	
	
	}

}

return 0;
}
