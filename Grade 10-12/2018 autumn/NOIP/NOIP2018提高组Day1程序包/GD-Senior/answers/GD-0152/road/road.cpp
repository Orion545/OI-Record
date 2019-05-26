#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

#define N 100005

using namespace std;

int A[N], n, UseNum, Answer;

void read(int &x)
{
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s > '9')   { if (s == '-')   f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') { x = x * 10 + (s - '0'); s = getchar(); }
	x = x * f;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(A[i]);
    if (n <= 1000)
    {
    	for (int i = 1; i <= n; i++)
    	{
    		int cmin = 10005, id = 0;
		    for (int j = 1; j <= n; j++) 
		        if (A[j] != 0) 
			       if (cmin > A[j]) cmin = min(cmin, A[j]), id = j;
		    if (id != 0)
	        {
	    	    A[id] = 0;
	    	    int l = id - 1, r = id + 1;
	    	    while (l >= 1 && A[l] != 0) A[l] -= cmin, --l; 
	            while (r <= n && A[r] != 0) A[r] -= cmin, ++r;
		        Answer += cmin;
		    } else break;
	    }
    } else 
	{ 
	for (int i = 1; i <= n; i++)
    {
    	if (A[i] + UseNum > 0)
    	{
    		int x = A[i];
    		A[i] += UseNum;
    		Answer += A[i];
    		UseNum = -x;
		} else 
    	{
    		UseNum = -A[i];
    		A[i] = 0;
    	}
    }
    }
    printf("%d\n", Answer);
	return 0;
}
