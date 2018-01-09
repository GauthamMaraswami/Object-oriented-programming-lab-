#include<stdio.h>
#include<string.h>
void ins(char,int);
void del(int,int);
char fr[50];
void main()
{
 int i,cnt=0,ch;
 printf("Enter the frame:\t");
 gets(fr);
 /*Charecter Stuffing*/
 ins('s',0);
 ins('e',5);
           //printf("%s",fr);
            for(i=0;i<strlen(fr);i++)
            {
             if(fr[i]=='d'&&fr[i+1]=='l'&&fr[i+2]=='e'&&i!=3&&i!=strlen(fr)-3)
             {
              ins('m',i+3);i+=6;
             }
            }
            printf("\n\nStuffed bit is \t%s\t",fr);
            /*Destuffing*/
            cnt=0;
            del(0,6);
            del(strlen(fr)-6,6);
            for(i=0;i<strlen(fr);i++)
            {
             if(fr[i]=='d'&&fr[i+1]=='l'&&fr[i+2]=='e')
             {
             cnt+=1;
             if(cnt==1)
             {         del(i,3);}
             }else
             {cnt=0;}
            }
            printf("\n\nDestuffed bit is \t%s",fr);
 }
void ins(char in,int p)
{
 char dup[50];
 int i;
 strcpy(dup,fr);
            if(in=='s')
            {
             fr[p]='s';
             fr[p+1]='t';
             fr[p+2]='x';
             fr[p+3]='d';
             fr[p+4]='l';
             fr[p+5]='e';
            for(i=p+6;i<strlen(fr)+6;i++)
            {
             fr[i]=dup[i-6];
            }
            }
            if(in=='e')
            {
             strcat(fr,"etxdle");return;
            }
            if(in=='m')
            {
             fr[p]='d';
             fr[p+1]='l';
             fr[p+2]='e';
             for(i=p+3;i<strlen(fr)+3;i++)
             {
             fr[i]=dup[i-3];
             }
            }
            }
void del(int q,int n)
{
 int i;
            for(i=q;i<strlen(fr);i++)
            {
             fr[i]=fr[i+n];
            }
}
