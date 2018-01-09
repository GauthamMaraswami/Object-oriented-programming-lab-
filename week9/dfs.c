#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int visit[100],n;

struct node{
int dat;
struct node* next;
};
struct node* top=NULL;
void push(int x){
struct node* nptr=(struct node *) malloc(sizeof(struct node));
nptr->dat=x;
nptr->next=NULL;
if(top==NULL)
{
top=nptr;
}
else{
nptr->next=top;
top=nptr;
}

//printf("peak element is%d\n ",top->dat);


}
int pop()
{
int pope;
if(top==NULL){
printf("empty stack");
return;
}
else{
pope=top->dat;
top=top->next;
}
return pope;
}

int peak()
{
if(top==NULL)
printf("empty list\n");
else
return top->dat;

}




void dfs(int k){
int y,y1,i,flag=0;
y=k;
visit[k]=1;
printf(" %d ",k);
push(k);
do{
y=peak();
 flag=0;
for(i=1;i<=n;++i)
{
	if(visit[i]==0&&a[y][i]==1)
	{
	printf(" %d ",i);
 	push(i);
	flag=1;
 	visit[i]=1;
	break;
	}

}
if(flag==0)
{
y1=pop();

}


}while(top!=NULL);
}
int create()
{
int i,n1,n2,ch;
printf("enter the no of elements\n");
scanf("%d",&n);
if(n==0)
{printf("no graph\n");
 return -999;
}
else
{
for(i=1;i<=n;++i)
visit[i]=0;
do{

printf("enter the nodes which are connected\n");
scanf("%d%d",&n1,&n2);

a[n1][n2]=1;
a[n2][n1]=1;
printf("do you want to add more edges\n");
scanf("%d",&ch);
}while(ch==1);
}
}

void main()
{

int d,i,tes;
for(i=1;i<=n;++i)
visit[i]=0;
printf("enter the graph\n");
tes=create();
if(tes!=-999){
printf("enter the node to start with\n");
scanf("%d",&d);
dfs(d);
for(i=1;i<=n;++i)
if(visit[i]==0)
dfs(i);
}}
