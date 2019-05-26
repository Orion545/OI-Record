#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 100020
using namespace std;

int a[N];

int main(void) //road.cpp
{
    int n;
    int i, o;

    freopen("road.in" , "r", stdin );
    freopen("road.out", "w", stdout);

    scanf("%d", &n);
    for(i = 1, o = 0; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        if(a[i] > a[i - 1])
            o += a[i] - a[i - 1];
    }
    printf("%d\n", o);

    return 0;
}
