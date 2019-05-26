#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 105
#define NUM 25005
using namespace std;
int T,n,num[N];
bool Pack[NUM];
void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	sort(num+1,num+1+n);
	memset(Pack,0,sizeof(Pack));
	Pack[0]=1;
	int m=0;
	for(int i=1;i<=n;i++)
	if(!Pack[num[i]])
	{
		m++;
		for(int j=0;j<=num[n]-num[i];j++)
			if(Pack[j])Pack[j+num[i]]=1;
	}
	printf("%d\n",m);
	return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
