#include <stdio.h>
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
	Process data;
	node *next;
};
class Queue
{
	node *front, *rear;
	public:
	Queue()
	{
		front = rear = NULL;
	}
	~Queue()
	{
		while(front != NULL)
			del();
	}
	void ins(Process p);
	Process del();
	bool empty()
	{
		return front == NULL;
	}
	bool in(Process p);
};
void Queue::ins(Process p)
{
	node *n = new node;
	n->next = NULL;	
	n->data = p;
	if(front == NULL)
		front = n;
	if(rear != NULL)
		rear->next = n;
	rear = n;
}

Process Queue::del()
{
	if(front == rear)
		rear = NULL;
	node *n = front;	
	front = front->next;
	Process a = n->data;
	delete n;
	return a;
}

bool Queue::in(Process p)
{
	node *n = front;
	while(n != NULL)
	{
		if(n->data.no == p.no)
			return true;
		n = n->next;
	}
	return false;
}

void quick(Process *arr, int st, int end, int type = 0)
{
	if(st >= end)
		return;
	int piv = arr[end].AT;
	if(type == 1)
		piv = arr[end].BT;
	if(type == 2)
		piv = arr[end].priority;
	int j = st;
	for(int i = st; i <= end; ++i)
	{
		if((arr[i].AT <= piv && type == 0) || (arr[i].BT <= piv && type == 1) || (arr[i].priority <= piv && type ==  2))
		{
			Process k = arr[i];
			arr[i] = arr[j];
			arr[j] = k;
			++j;
		}
	}
	--j;
	quick(arr, st, j - 1, type);
	quick(arr, j + 1, end, type);
}
void qsort(Process *p, int size, int type = 0)
{
	quick(p, 0, size - 1, type);
}

void FCFS(Process *p, int size)
{
	qsort(p, size);
	int currtime = 0;
	printf("\n0 ");
	for(int i = 0; i < size; ++i)
	{
		if(currtime < p[i].AT)
		{
			++currtime;
			printf("IDLE %d ", currtime); 
		}
		currtime += p[i].BT;
		p[i].CT = currtime;
		printf("(P%d) %d ", p[i].no, currtime);
	}
	printf("\n\n");
}

void SJF(Process *p, int size)
{
	Process *q = new Process[size];
	for(int i = 0; i < size; ++i)
		q[i] = p[i];
	qsort(q, size, 1);
	qsort(p, size, 1);
	int currtime = 0;
	printf("\n0 ");
	while(1)
	{
		int flag = 0;
		for(int i = 0; i < size; ++i)
		{
			if(q[i].AT <= currtime && q[i].BT != 0)
			{
				currtime += q[i].BT;
				p[i].CT = currtime;
				q[i].BT = 0;
				printf("(P%d) %d ", q[i].no, currtime);
				i = -1;
			}
			if(flag == 0 && q[i].BT != 0)
				flag = 1;
		}
		if(flag == 1)
		{
			++currtime;
			printf("IDLE %d ", currtime); 
		}
		else
			break;
	}
	printf("\n\n");
}

void RR(Process *p, int size)
{
	printf("Enter time quantum\n");
	int TQ;
	scanf("%d", &TQ);
	Process *pq = new Process[size];
	for(int i = 0; i < size; ++i)
		pq[i] = p[i];
	qsort(pq, size);
	qsort(p, size);

	Queue que;
	que.ins(p[0]);

	int currtime = 0;
	printf("\n0 ");

	while(!que.empty())
	{	
		Process q = que.del();
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
		for(int i = 0; i < size; ++i)
		{
			if(!que.in(p[i]) && p[i].AT <= currtime && pq[i].BT > 0 && pq[i].no != q.no)
				que.ins(p[i]);
		}
		if(q.BT > 0)
			que.ins(q);
		
	}
	printf("\n\n");
}


void disp(Process *p, int size, int type = 0)
{
	qsort(p, size);
	
	if(type == 1)
		printf("P No\tPrty\tAT\tBT\tCT\tTAT\tWT\n");
	else if(type == 0)
		printf("P No\tAT\tBT\tCT\tTAT\tWT\n");

	float TAT = 0, WT = 0;
	for(int i = 0; i < size; ++i)
	{
		if(type == 0)
			printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].no, p[i].AT, p[i].BT, 
				p[i].CT, p[i].CT - p[i].AT, p[i].CT - p[i].BT - p[i].AT);
		else if(type == 1)
			printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].no, p[i].priority, p[i].AT, p[i].BT, 
				p[i].CT, p[i].CT - p[i].AT, p[i].CT - p[i].BT - p[i].AT);
		TAT += p[i].CT - p[i].AT;
		WT += p[i].CT - p[i].BT - p[i].AT;
	}
	printf("Average WT: %f\nAverage TAT: %f\n", WT / (float)size, TAT / (float)size);
}

int main()
{
	printf("Enter number of processes\n");
	int size;
	scanf("%d", &size);
	Process *p = new Process[size];
	printf("Enter AT and BT\n");
	for(int i = 0; i < size; ++i)
	{
		p[i].no = i + 1;
		scanf("%d %d", &(p[i].AT), &(p[i].BT));
	}
	printf("Scheduling method: \n1. FCFS \n2. SJF \n3. Round Robin \n");
	int opt;
	scanf("%d", &opt);	
	switch(opt)
	{
		case 1:
			FCFS(p, size);
			disp(p, size);
			break;
		case 2:
			SJF(p, size);
			disp(p, size);
			break;
		case 3:
			RR(p, size);
			disp(p, size);
			break;
		
	}
	return 0;
}
