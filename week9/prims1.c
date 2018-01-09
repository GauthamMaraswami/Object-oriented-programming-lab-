#include <stdlib.h>
#include <stdio.h>
typedef struct vertex
{
        int no;
        unsigned int key;
} vert;
typedef struct node
{
        int vert;
        struct node *next;
        int dist;
} node;
void connect(node *AdjList, int x, int y, int dist)
{
        node *new1 = malloc(sizeof(node));
        new1->next = NULL;
        new1->vert = x;
        new1->dist = dist;
        node *it = AdjList + y;
        while(it->next != NULL)
                it = it->next;
        it->next = new1;
}

void heapify(vert arr[], int i, int n, int dir)
{
        if(dir == 0)
        {
                if(i == 0)
                        return;
                if(arr[i].key < arr[i/2].key)
                {
                        vert t = arr[i];
                        arr[i] = arr[i/2];
                        arr[i/2] = t;
                        heapify(arr, i / 2, n, 0);
                }
        }
        else if(dir == 1)
        {

                if(2 * i + 1 >= n)
                        return;
                if(2 * i + 2 >= n)
                {
                        vert t = arr[2 * i + 1];
                        arr[2 * i + 1] = arr[i];
                        arr[i] = t;
                        heapify(arr, 2 * i + 1, n, 1);
                }
                else if(arr[2 * i + 1].key < arr[i].key || arr[2 * i + 2].key < arr[i].key)
                {
                        if(arr[2 * i + 1].key < arr[2 * i + 2].key)
                        {
                                vert t = arr[2 * i + 1];
                                arr[2 * i + 1] = arr[i];
                                arr[i] = t;
                                heapify(arr, 2 * i + 1, n, 1);
                        }
                        else
                        {
                                vert t = arr[2 * i + 2];
                                arr[2 * i + 2] = arr[i];
                                arr[i] = t;
 			        arr[i] = t;
                                heapify(arr, 2 * i + 2, n, 1);
                        }
                }
        }
}

vert pop(vert v[], int *n)
{
        vert x = v[(*n) - 1];
        v[(*n) - 1] = v[0];
        v[0] = x;
        --(*n);
        heapify(v, 0, (*n), 1);
        return v[(*n)];
}

void Prim(node *AdjList, int m, int n)
{
        vert *v = malloc(sizeof(vert) * n);
        int tot = 0;
        int i, n2 = n;
        for(i = 0; i < n + 1; ++i)
        {
                v[i].no = i;
                v[i].key = -1;
        }
        v[0].key = 0;
        while(n2 != 0)
        {
                vert x = pop(v, &n2);
                tot += x.key;
		//printf("%d--%d",x.no,x.key); 
		printf("%d\n",tot);
                node *t = AdjList[x.no].next;
                while(t != NULL)
                {
                        for(i = 0; i < n2; ++i)
                                if(v[i].no == t->vert && v[i].key > t->dist)
                                        v[i].key = t->dist;
                        t = t->next;
                }
        }
        printf("Total cost is %d\n", tot);
}

int main()
{
        int size, x, y, i, m, d;
        printf("Enter number of vertices of graph\n");
        scanf("%d", &size);
        if(size == 0)
        {
                printf("Empty graph!\n");
                return 0;
        }
        node *AdjList = malloc(sizeof(node) * size);
        for(i = 0; i < size; ++i)
                AdjList[i].next = NULL;
        printf("Enter number of edges of graph\n");
        scanf("%d", &m);
        if(m > size * size - 1 || m < size - 1)
        {
                printf("Incorrect number of edges!\n");
                return 1;
        }
        printf("Enter connected vertices and distance in format x y d\n");
        for(i = 0; i < m; ++i)
        {
                scanf("%d %d %d", &x, &y, &d);
                if(x > size || y > size)
                {
                        printf("Parameter exceeds size!");
                        break;
                }
                connect(AdjList, x - 1, y - 1, d);
                connect(AdjList, y - 1, x - 1, d);
        }
        Prim(AdjList, m, size);
        return 0;
}


