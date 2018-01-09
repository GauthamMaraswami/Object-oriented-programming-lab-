#include<stdio.h>
#include <stdlib.h>
int sem_mutex=1,sem_full=0,sem_empty=3,x=0;
main()
{
   int n;
   void producer();
   void consumer();
   int wait(int);
   int signal(int);
   printf("\n 1.Producer  \n 2.Consumer \n 3.Exit");
   while(1)
   {
      printf("\n Enter your choice:");
      scanf("%d",&n);
      switch(n)
      {
         case 1:
                 if((sem_mutex==1)&&(sem_empty!=0))
                    producer();
                 else
                    printf("Buffer is full");
     break;
         case 2:
             if((sem_mutex==1)&&(sem_full!=0))
    consumer();
    else
        printf("Buffer is empty");
       break;
         case 3:
    exit(0);
    break;
      }
   }
}
int wait(int s)
{
   return (--s);
}
int signal(int s)
{
   return(++s);
}
void producer()
{
   sem_mutex=wait(sem_mutex);
   sem_full=signal(sem_full);
   sem_empty=wait(sem_empty);
   x++;
   printf("\n Producer produces the item %d",x);
   sem_mutex=signal(sem_mutex);
}
void consumer()
{
   sem_mutex=wait(sem_mutex);
   sem_full=wait(sem_full);
   sem_empty=signal(sem_empty);
   printf("\n Consumer consumes item %d",x);
   x--;
   sem_mutex=signal(sem_mutex);
}
