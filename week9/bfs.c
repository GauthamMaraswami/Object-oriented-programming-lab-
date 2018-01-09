#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int visit[100],n;
struct node{
int d1;
struct node* next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enque(int x)
{
struct node *nptr=(struct node *) malloc(sizeof(struct node));
nptr->d1=x;
     nptr->next=NULL;
if(front==NULL&&rear==NULL)
    {
        front=rear=nptr;
        
     //   printf("enqus sucessful\n");
    }
else{
 	rear->next=nptr;
        rear=rear->next;
	//  printf("enqus sucessful\n");
}
}







int deque()
{
	struct node* ptr=(struct node *) malloc(sizeof(struct node));

	int res;
	if(front==NULL&&rear==NULL)
		 {
 		 // printf("underflow\n");
		  return 0;
		}
	else if(front->next!=NULL){
  		 res=front->d1;

       		 front=front->next;
       		 
      		 return res;
    		 }
	else {
  		 res=front->d1;

       		 front=rear=NULL;
       		 
      		 return res;
    		 }	
	
}
void bfs(int k){

enque(k);
int y,i;
visit[k]=1;
do{
y=deque();
printf(" %d ",y);
for(i=1;i<=n;++i)
{
	if(visit[i]==0&&a[y][i]==1)
	{
 	enque(i);
	//printf("kkkk%dkkkk",i);
 	visit[i]=1;
	}

}
}while(front!=NULL&&rear!=NULL);


}
void create()
{
int i,n1,n2,ch;
printf("enter the no of elements\n");
scanf("%d",&n);
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

void main()
{

int d,i;
for(i=1;i<=n;++i)
visit[i]=0;
printf("enter the graph\n");
create();
printf("enter the node to start with\n");
scanf("%d",&d);
bfs(d);
}
