#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n,sum=0;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	int x=0,y;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&y);
		if (y>x) sum+=(y-x);
		x=y;
	}
	printf("%d\n",sum);
	
	return 0;
}




























