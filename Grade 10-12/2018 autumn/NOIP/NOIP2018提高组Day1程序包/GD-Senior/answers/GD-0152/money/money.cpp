#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

#define N 105

using namespace std;

int A[N], B[N], n, T, num, cnt, cmin, cmax, Answer;
bool Viscp[25005], Usecp[25005];

void read(int &x)
{
	int f = 1; x = 0; char s = getchar();
	while (s < '0' || s > '9')   { if (s == '-')   f = -1; s = getchar(); }
	while (s >= '0' && s <= '9') { x = x * 10 + (s - '0'); s = getchar(); }
	x = x * f;
}

void dfs(int x, int now)
{
	++cnt; if (cnt >= 3000000) return;
	if (x > Answer) return;
	if (x > 20) return;
	for (int i = 1; i <= cmax; i++) Viscp[i] = 0;
	for (int i = 1; i < x; i++)
    {
        int rp = 1; 
        while (rp * B[i] <= cmax) 
		{
		      Viscp[rp * B[i]] = 1;
			  if (!Usecp[rp * B[i]]) return;
			  ++rp;
        }
	}
    int tot = 0;
	for (int i = 1; i <= cmax; i++)
    {
        if (!Viscp[i])
		{ 
		   for (int j = 1; j * 2 <= i; j++)
			   if (Viscp[j] && Viscp[i - j]) 
			   {
				   Viscp[i] = 1; 
				   if (!Usecp[i]) return;
				   break;
			   } 
        }
        if (Viscp[i] && !Usecp[i]) return;
        if (Viscp[i] && Usecp[i]) ++tot;
	}
    if (tot == num)
	{
	    Answer = x - 1;
        return;
    }
    for (int i = now + 1; i <= cmax; i++) 
	{
        B[x] = i;
        if (cnt >= 3000000) return; 
		dfs(x + 1, i);
	}
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	read(T);
	while (T--)
	{
		read(n);
	    cmin = 25005, cmax = 0;
		for (int i = 1; i <= n; i++) 
		    read(A[i]), cmin = min(cmin, A[i]), cmax = max(cmax, A[i]);
        if (n == 2)
        {
        	A[1] = A[1] % cmin; 
        	A[2] = A[2] % cmin;
        	if (A[1] || A[2]) printf("%d\n", 2); else printf("%d\n", 1);
        } else
		{ 
		    for (int i = 1; i <= cmax; i++) Usecp[i] = 0;
		    for (int i = 1; i <= n; i++)
            {
           	    int rp = 1; 
        	    while (rp * A[i] <= cmax) Usecp[rp * A[i]] = 1, ++rp;
            }
            num = 0;
            for (int i = 1; i <= cmax; i++)
            {
                if (!Usecp[i])
			    { 
			        for (int j = 1; j * 2 <= i; j++)
					    if (Usecp[j] && Usecp[i - j]) 
						{
							Usecp[i] = 1; break;
						} 
                }
                if (Usecp[i]) ++num;
            }
            Answer = n;
            cnt = 0; 
            dfs(1, cmin - 1); 
            printf("%d\n", Answer);
		}
    }
	return 0;
}
