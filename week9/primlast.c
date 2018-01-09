#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
typedef struct vertex
{
        int pos;
        int key;
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
        new1->next = it->next;
        it->next = new1;
}
void heapify(vert v[], int arr[], int i, int n)
{
        if(i == 0)
                return;
        if(v[arr[i]].key < v[arr[(i - 1)/2]].key)
        {
                int t = arr[i];
                arr[i] = arr[(i - 1)/2];
                arr[(i - 1)/2] = t;
                v[arr[i]].pos = i;
                v[arr[(i - 1) / 2]].pos = (i - 1) / 2;
                heapify(v, arr, (i - 1) / 2, n);
        }
}


void rheapify(vert v[], int arr[], int i, int n)
{
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int sm = i;
        if(2 * i + 1 < n && v[arr[sm]].key > v[arr[l]].key)
                sm = l;
        if(2 * i + 2 < n && v[arr[sm]].key > v[arr[r]].key)
                sm = r;
        if(sm != i)
        {
                int t = arr[sm];
                arr[sm] = arr[i];
                arr[i] = t;
                v[arr[i]].pos = i;
                v[arr[sm]].pos = sm;
                rheapify(v, arr, sm, n);
        }
}
int pop(vert v[], int arr[], int *n)
{
        int x = arr[(*n) - 1];
        arr[(*n) - 1] = arr[0];
        arr[0] = x;
        --(*n);
        v[arr[0]].pos = 0;
        v[arr[(*n)]].pos = -1;
        rheapify(v, arr, 0, (*n));
        return arr[(*n)];
}




void Prim(node *AdjList, int m, int n, int start)
{
        vert *v = malloc(sizeof(vert) * n);
        int *heap = malloc(sizeof(int) * n);
        int tot = 0;
        int i, n2 = n;
        for(i = 0; i < n; ++i)
        {
                v[i].pos = i;
                v[i].key = INT_MAX;
                heap[i] = i;
        }
        v[start].key = 0;
        heap[0] = start;
        heap[start] = 0;
        v[start].pos = 0;
        v[0].pos = start;

         printf("%d",v[0].pos );
        while(n2 != 0)
        {
                int x = pop(v, heap, &n2);
                if(v[x].key == INT_MAX)
                        break;
                tot += v[x].key;
                printf("%d---%d",x,v[x].key );
                node *t = AdjList[x].next;
                while(t != NULL)
                {
                        if(v[t->vert].key > t->dist)
                        {
			
                                v[t->vert].key = t->dist;
                                heapify(v, heap, v[t->vert].pos, n2);
                        }
                        t = t->next;
			
                }
        }
        if(tot < 0)
                printf("Disconnected graph given!\n");
        else

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
        printf("Input starting node\n");
        int st = 0;
        scanf("%d", &st);
        Prim(AdjList, m, size, st - 1);
        return 0;
}

