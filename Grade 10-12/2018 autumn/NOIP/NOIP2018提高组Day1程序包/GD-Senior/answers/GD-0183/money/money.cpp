#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int read()
{
    int c, x = 0;
    c = getchar();
    while(c < '0'||c>'9') c = getchar();
    while(c >= '0' && c<='9')
    {
	x = x* 10 + c -'0';
	c = getchar();
    }
    return x;
}


const int MAXN = 25000 + 5;
bool isSu[MAXN];
int num[25][150];
int n[25];
int T;

int main()
{
    T = read();
    memset(isSu, false, sizeof(isSu));
    for(int i = 1; i <= T; i++)
    {
	n[i] = read();
	for(int j = 1; j <= n[i]; j++)
	    num[i][j] = read();
    }

    for(int i = 1; i <= T; i++)
	printf("%d\n", n[i]);

    return 0;
}
