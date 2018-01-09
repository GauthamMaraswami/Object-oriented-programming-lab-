#include<stdio.h>
#include<stdlib.h>

int smallbt(int at[],int bt[],int done[],int cur,int n){
int i=0;
int t=100,t1=-1;
for(i=0;i<n;++i)
{
 if(bt[i]<t&& at[i]<=cur && done[i]==0)
 {
 t=bt[i];
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
int pno[10],at[10],bt[10],ct[10],tat[10],wt[10],at1[10],done[10];
int n,i,t;
printf("enter the number of processes");
scanf("%d",&n);
for(i=0;i<n;++i)
{
 printf("enter the process no arrival time burst time of process %d",i);
        scanf("%d%d",&at[i],&bt[i]);
        done[i]=0;
        at1[i]=at[t];
}

sort(at,bt,n);
int curt=0;
if(curt<at[0])
        {
        printf("idle--");
        curt=at[0];
        }
  printf("--->p%d",t);
done[i]=1;



curt+=bt[0];
int te=smallbt(at,bt,done,curt,n);

while(te<n)
{
printf("-->p%d ",te);
done[te]=1;
curt+=bt[te];

}

int curt=0,npwt=5;
int rqu[5];
int pdng=0
t=smallat(at1[],n);
//for(i=0;i<te;++i)
 // at1[i]=100;
if(curt<at1[t])
        {
        printf("idle--");
        curt=at1[t];
        }
  printf("p%d",&t);
curt+=bt[t];
done[t]=1;
int te=0;
for(i=0;i<n;++i)
{
if((at[i]<curt)&&(done[i]==0))
        {
          at1[te]=at[i];
          ++te;      
        }

}



}
