#include<stdio.h>
int a[5];
void main()
{
int i=0;
for(i=0;i<5;++i)
{
   a[i]=0;
}
int choice;
int ch=1;
while(1)
{
printf("enter the choice 1-start 2- stop 3-break");
scanf("%d",&ch);
if(ch==1)
        {
                 printf("enter the philosopher who want to eat 100- to break\n");
                scanf("%d",&choice);
                if(choice==0)
                {  
                          if(a[4]==0&&a[1]==0)
                                {
                                   if(a[choice]==0)
                                           {
                                                    a[choice]=1;
                                                    printf("Philosopher %d starts eating\n",choice);
                                           }
                                   else
                                        {
                                                 printf("philosopher already eating\n");
                                         }
                                 }
                           else{
                                        printf("someone neighbour is eating \n");
                               }
                }
                else if(choice==4)
                {  
                         if(a[3]==0&&a[0]==0)
                         {
                                  if(a[choice]==0)
                                         {
                                                  a[choice]=1;
                                                printf("Philosopher %d starts eating\n",choice);
                                         }
                                  else
                                        {
                                                  printf("philosopher already eating\n");
                                        }
                        }
                         else{
                                printf("someone neighbour is eating \n");
                             }
                }
                

                else{
                         if(a[choice-1]==0&& a[choice+1]==0)
                         {
                                if(a[choice]==0)
                                 {
                                            a[choice]=1;
                                          printf("Philosopher %d starts eating\n",choice);
                                 }
                                else
                                 {
                                          printf("philosopher already eating\n");
                                 }
                         } 
                        else{
                                printf("someone neighbour is eating \n");
                          }



                     }
int i=0;
for(i=0;i<5;++i)
{
     if(a[i]==0)
       printf("Philosopher%d is thinking\n",i);
     else
        printf("Philosopher%d is eating\n",i);
}                     
                     
                     
}
else if(ch==2)
        {
             printf("enter the philosopher who want to stop eat\n");
                scanf("%d",&choice);
            if(a[choice]==1)
                {
                  a[choice]=0;
                  printf("Philosopher %d stops eating\n",choice);
                }
            else
                 printf("Philosopher not eating\n");
                 
        
        
        }
else
                {

                       break;
                }


}




}
