#include<stdio.h>
#define buffer 10
int readcoun=0, sem_write=0;
int read[10],write1=-1;
void start_read(int id)
{
    if(readcoun>=0&& sem_write==0)
        {
            int i=0,flag=0;
            for(i=0;i<readcoun;++i)
                {
                   if(read[i]==id)
                    flag=1;
                                
                }
                if(flag==1)
                  {
                      printf("you are already reading\n");
                      
                   }
                 else if(flag==0){
                 
                      read[readcoun]=id;
                      ++readcoun;
                       printf("%d  started reading\n",id);
                  }
        
        }
    /*else if(readcoun==1&& sem_write==0)
        {
            read[readcoun]=id;
                ++readcoun;   
        
        }
     */
     else if( sem_write==1)
     {
          printf("someone is writing\n");
     
     }


}
void stop_read(int id)
{
    if(readcoun>0)
        {
                int i,pos,j,flag=0;
                for(i=0;i<readcoun;++i)
                   {
                     if(read[i]==id)
                        { 
                          flag=1;
                          pos=i;
                           for(j=pos;j<readcoun-1;++j)
                              read[j]=read[j+1];
                        }
                    }
                    if(flag==1)
                    { printf("%d stopped reading\n",id);
                    readcoun--;
                     }
                    else if(flag==0)
                    {
                       printf("you are not reading\n");
                    }
        }
    else 
        {
            printf("invalid id\n");
        
        }
    


}
void start_write(int id)
{
  if(sem_write==1)
    {
       printf("someone else is writing\n");
    
    
    }
   else if(readcoun>0)
       printf("someone else is reading\n");
   else{
        printf("%d  started writing\n",id);
      sem_write=1;
      write1=id;
   }
}

void stop_write(int id)
{
sem_write=0;
if(write1==id)
  {
  printf("%d stopped writing\n",id);
  sem_write=0;
  }
else
  printf("not authorized to stop\n");
}
void main()
{
int id,choice;
while(1)
{
   printf("enter id\n");
   scanf("%d",&id);
   printf("enter your choice 1-start read 2-stop read 3- start write 4- stop write 5-break\n");
   scanf("%d",&choice);
   if(choice==1)
    {
    start_read(id);
    }
   else  if(choice==2)
    {
    stop_read(id);
    }
    else  if(choice==3)
    {
    start_write(id);
    }
    else  if(choice==4)
    {
    stop_write(id);
    }
    else  if(choice==5)
    {
   break;
    }
}
}
