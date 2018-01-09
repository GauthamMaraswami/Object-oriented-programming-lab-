#include <stdio.h>
#include <stdlib.h>
struct Process
{
	int no;
	int AT;
	int BT;
	int CT;
};
struct node
{
	struct Process data;
	struct node *next;
};
struct node *front = NULL, *rear = NULL;
int empty()
{
	return front == NULL;
}
void ins(struct Process p)
{
	struct node *n = (struct node*)malloc(sizeof(struct node));
	n->next = NULL;
	n->data = p;
	if(front == NULL)
		front = n;
	if(rear != NULL)
		rear->next = n;
	rear = n;
}

struct Process del()
{
	if(front == rear)
		rear = NULL;
	struct node *n = front;
	front = front->next;
	struct Process a = n->data;
	free(n);
	return a;
}

int in(struct Process p)
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

void quick(struct Process *arr, int st, int end, int type)
{
	if(st >= end)
		return;
	int piv = arr[end].AT;
	if(type == 1)
		piv = arr[end].BT;
	int j = st, i;
	for(i = st; i <= end; ++i)
	{
		if((arr[i].AT <= piv && type == 0) || (arr[i].BT <= piv && type == 1))
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
void quicksort(struct Process *p, int size, int type)
{
	quick(p, 0, size - 1, type);
}

void FCFS(struct Process *p, int size, int *currtime)
{
	quicksort(p, size, 0);
	int i;
	//printf("\n%d ");
	for(i = 0; i < size; ++i)
	{
		if(*currtime < p[i].AT)
		{
			++*currtime;
			printf("IDLE %d ", *currtime);
		}
		*currtime += p[i].BT;
		p[i].CT = *currtime;
		printf("(P%d) %d ", p[i].no, *currtime);
	}
}

void RR(struct Process *p, int size, int *currtime, int TQ)
{
	int i;
	front = NULL;
	rear = NULL;
	struct Process *pq = (struct Process *)malloc(sizeof(struct Process) * size);
	for(i = 0; i < size; ++i)
		pq[i] = p[i];
	quicksort(pq, size, 0);
	quicksort(p, size, 0);

	ins(p[0]);
	
	while(!empty())
	{
		struct Process q = del();
		if(q.AT <= *currtime && q.BT > 0)
		{
			if(TQ < q.BT)
			{
				*currtime += TQ;
				q.BT -= TQ;
			}
			else
			{
				*currtime += q.BT;
				pq[q.no - 1].BT = 0;
				q.BT = 0;
				p[q.no - 1].CT = *currtime;
			}
			printf("(P%d) %d ", q.no, *currtime);
		}
		else
		{
			++*currtime;
			printf("IDLE %d ", *currtime);
		}
		for(i = 0; i < size; ++i)
		{
			if(!in(p[i]) && p[i].AT <= *currtime && pq[i].BT > 0 && pq[i].no != q.no)
				ins(p[i]);
		}
		if(q.BT > 0)
			ins(q);

	}
}

void disp(int i1, struct Process *p, int size, float *TAT, float *WT)
{
	quicksort(p, size, 0);
	int i;
	for(i = 0; i < size; ++i)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i1, p[i].no, p[i].AT, p[i].BT,
				p[i].CT, p[i].CT - p[i].AT, p[i].CT - p[i].BT - p[i].AT);
		*TAT += p[i].CT - p[i].AT;
		*WT += p[i].CT - p[i].BT - p[i].AT;
	}
}

int main()
{
	printf("3 Queues, Queue 1 = RR with TQ = 4, Queue 2 = RR with TQ = 2, Queue 3 = FCFS\n");
	struct Process *p[3];
	int size[3], i1;
	for(i1 = 0; i1 < 3; ++i1)
	{
		printf("Enter number of processes in queue %d\n", i1 + 1);
		int i;
		scanf("%d", &size[i1]);
		p[i1] = (struct Process *)malloc(sizeof(struct Process) * size[i1]);

		printf("Enter AT, and BT\n");
		for(i = 0; i < size[i1]; ++i)
		{
			p[i1][i].no = i + 1;
			scanf("%d %d", &(p[i1][i].AT), &(p[i1][i].BT));
		}
	}

	int currtime = 0;
	float TAT = 0, WT = 0;
	printf("\n0 ");
	RR(p[0], size[0], &currtime, 4);
	RR(p[1], size[1], &currtime, 2);
	FCFS(p[2], size[2], &currtime);
	printf("\n\n");

	printf("Q No\tP No\tAT\tBT\tCT\tTAT\tWT\n");
	for(i1 = 0; i1 < 3; ++i1)
		disp(i1 + 1, p[i1], size[i1], &TAT, &WT);
	printf("Average WT: %f\nAverage TAT: %f\n", WT / (float)(size[0] + size[1] + size[2]), TAT / (float)(size[0] + size[1] + size[2]));
	return 0;
}
