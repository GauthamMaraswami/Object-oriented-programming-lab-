#include<stdio.h>
#include<stdlib.h>
int smallat(int at[],int n){
int i=0;
int t=100,t1=-1;
for(i=0;i<n;++i)
{
 if(at[i]<t)
 {
 t=at[i];
 t1=i;
 }
}

return t1;
}

void sort(int at[],int bt[],int n)
{
        int i=0,j=0,te;
        for( i=0;i<n;++i)
        {   
               te=0;
                for(j=0;j<n-i-1;++j)
                {
                     if(at[j]>at[j+1])
                        {
                          te=at[i];
                          at[i]=at[j];
                          at[j]=te;
                          
                          te=bt[i];
                          bt[i]=bt[j];
                          bt[j]=te;
                                                
                        }
                }
        }

}







void main()
{
int pno[10],at[10],bt[10],ct[10],tat[10],wt[10],at1[10];
int n,i,t;
printf("enter the number of processes");
scanf("%d",&n);
for(i=0;i<n;++i)
{
        printf("enter the arrival time burst time of process %d",i);
        scanf("%d%d",&at[i],&bt[i]);
        at1[i]=at[t];
}

sort(at,bt,n);
if(at[0]>0)
        printf("IDLE");
printf("--->p%d",at[0]);
        
int ncpr=1;
int temp=0;
i=1;
temp=bt[0]-at[0];
ct[0]=temp;
while(ncpr<n)
{
  if(at[ncpr]>ct[ncpr-1])
     {
      printf("--->IDLE");
     }
  printf("--->p%d",at[ncpr]);
  temp+=bt[ncpr];
  ct[ncpr]=temp;
  ++ncpr;

}


/*
for(i=0;i<n;++i)
{
t=smallat(at1,n);
temp+=bt[t];
ct[t]=temp;
at1[t]=100;
}*/

int stat=0;
int swt=0;
for(i=0;i<n;++i)
{
tat[i]=ct[i]-at[i];
stat+=tat[i];

wt[i]=tat[i]-bt[i];
if(wt[i]<0)
wt[i]=0;
swt+=wt[i];
}

float avtat=((float) stat/n);
float avswt=((float) swt/n);
printf("pno   at   bt   ct   tat   wt\n");
for(i=0;i<n;++i)
{
printf("%d   %d   %d   %d   %d   %d\n",i,at[i],bt[i],ct[i],tat[i],wt[i]);

}
printf("AVG TAT=%f\n avg wt=%f",avtat,avswt );




}

