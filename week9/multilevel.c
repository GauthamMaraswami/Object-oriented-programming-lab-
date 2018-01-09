#include <stdio.h>
#include<stdlib.h>
struct Process
{
	int no;
	int AT;
	int BT;
	int CT;
	int priority;
};

struct node
{
	struct Process data;
	struct node *next;
};
//node *front, *rear;
//front=rear=NULL:

void ins(struct Process p,struct node *front,struct node *rear)
{
	struct node *n = (struct node *) malloc(sizeof(struct node));
	n->next = NULL;	
	n->data = p;
	if(front == NULL)
		front = n;
	if(rear != NULL)
		rear->next = n;
	rear = n;
}
int sof(struct node *front,struct node *rear)
{

struct node *n = front;


int ctr=0;
	while(n!= NULL)
	{
		++ctr;
		n = n->next;
	}
return ctr;


}
struct Process del(struct node *front,struct node *rear)
{
	if(front == rear)
		rear = NULL;
	struct node *n = front;	
	front = front->next;
	struct Process a = n->data;
	delete n;
	return a;
}


int in(struct Process p,struct node *front,struct node *rear)
{
	struct node *n = front;
	while(n != NULL)
	{
		if(n->data.no == p.no)
			return 1;
		n = n->next;
	}
	return 0;
}

int empty(struct node *front,struct node *rear)
	{
		return front == NULL;
	}



void quick(struct Process *arr, int st, int end, int type = 0)
{
	if(st >= end)
		return;
	int piv = arr[end].AT;
	if(type == 1)
		piv = arr[end].BT;
	if(type == 2)
		piv = arr[end].priority;
	int j = st;
	int i;
	for(i = st; i <= end; ++i)
	{
		if((arr[i].AT <= piv && type == 0) || (arr[i].BT <= piv && type == 1) || (arr[i].priority <= piv && type ==  2))
		{
			struct Process k = arr[i];
			arr[i] = arr[j];
			arr[j] = k;
			++j;
		}
	}
	--j;
	quick(arr, st, j - 1, type);
	quick(arr, j + 1, end, type);
}
void qsort(struct Process *p, int size, int type = 0)
{
	quick(p, 0, size - 1, type);
}


void RR(struct Process *p, int size)
{
	printf("Enter time quantum\n");
	int TQ;
	scanf("%d", &TQ);
	struct Process *pq = (struct process*) malloc(size*sizeof(Process));
	int i;
	for( i = 0; i < size; ++i)
		pq[i] = p[i];
	qsort(pq, size);
	qsort(p, size);

	struct node *front=NULL;
	struct node *rear=NULL;  
	que.ins(p[0],front,rear);

	int currtime = 0;
	printf("\n0 ");
	int siz=1;
	while(!empty(front,rear))
	{	
		struct Process q = del(front,rear);
		siz=sof(front,rear);
	//printf("\n%d\n ",siz);
		if(q.AT <= currtime && q.BT > 0)
		{
			if(TQ < q.BT)
			{				
				currtime += TQ;
				q.BT -= TQ;
			}
			else
			{
				currtime += q.BT;
				pq[q.no - 1].BT = 0;
				q.BT = 0;
				p[q.no - 1].CT = currtime;
			}
			printf("(P%d) %d ", q.no, currtime);
		}
		else
		{
			++currtime;
			printf("IDLE %d ", currtime); 
		}
		int i;
		for( i = 0; i < size; ++i)
		{
			if(!in(p[i],front,rear) && p[i].AT <= currtime && pq[i].BT > 0 && pq[i].no != q.no)
				{
					ins(p[i],front,rear);
					
				}
		}
		if(q.BT > 0)
			{
				ins(q,front,rear);
			}
		siz=que.sof(front,rear);
	//printf("\n%d\n ",siz);
		if(siz==0)
			{
			//printf("rrrrrrrrrrrrr");
			int i;
			for( i=0;i<size;++i)
			{
			   if(pq[i].BT>0)
				{
				//printf("aaaaaaaa");
					ins(pq[i],front,rear);
					break;
				}	
			}
				

			}		
		
	}
	printf("\n\n");
}














int main()
{
	printf("Enter number of processes\n");
	int size;
	scanf("%d", &size);
	struct Process *p = (struct process*)malloc(size*sizeof(Process));
	printf("Enter AT and BT\n");
	int i;
	for( i = 0; i < size; ++i)
	{
		p[i].no = i + 1;
		scanf("%d %d", &(p[i].AT), &(p[i].BT));
	}
	printf("Scheduling method: \n1. FCFS \n2. SJF \n3. Round Robin \n4. Non-preemptive Priority\n");
	int opt;
	scanf("%d", &opt);	
	
			RR(p, size);
			
	return 0;
}
