#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<cmath>
#include<stdlib.h>
#include<queue>
using namespace std;
long long a,b,ans=1;
void read();
void read_into(int u,int v);
int main()
{
	read();
	return 0;
}

void read()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	for(int i=1;i<=a;i++)
	  ans*=a;
	if(a&1) ans++;
	printf("%lld",ans*(b+1));
}

