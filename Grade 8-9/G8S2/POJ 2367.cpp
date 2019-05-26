#include <iostream>  
#include <cstdio>  
#include <algorithm>  
using namespace std;  
  
const int N = 105;  
struct Edge  
{  
    int pos;  
    int next;  
};  
int n;  
int indeg[N];  
Edge edge[N * N];  
int cur;  
int neigh[N];  
int queue[N], front, rear;  
  
void init()  
{  
    for (int i = 0; i < n; ++i)  neigh[i] = -1;  
    cur = 0;  
    front = rear = 0;  
}  
  
int main()  
{  
    int t, e;  
    scanf("%d", &n);  
    init();  
    for (int i = 0; i < n; ++i)  
    {  
        while (scanf("%d", &t) && t)  
        {  
            ++indeg[t - 1];  
            edge[cur].pos = t - 1;  
            edge[cur].next = neigh[i];  
            neigh[i] = cur;  
            ++cur;  
        }  
    }  
    for (int i = 0; i < n; ++i)  
    {  
        if (indeg[i] == 0)  
        {  
            queue[rear++] = i;  
        }  
    }  
    bool beg = true;  
    while (front != rear)  
    {  
        t = queue[front++];  
        if (!beg) printf(" ");  
        printf("%d", t + 1);  
        beg = false;  
        e = neigh[t];  
        while (e != -1)  
        {  
            --indeg[edge[e].pos];  
            if (indeg[edge[e].pos] == 0) queue[rear++] = edge[e].pos;  
            e = edge[e].next;  
        }  
    }  
    printf("\n");  
    return 0;  
}
