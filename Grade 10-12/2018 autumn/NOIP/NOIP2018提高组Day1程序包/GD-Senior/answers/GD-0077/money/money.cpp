#include<cstdio>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int T,n,a[110],b[100000],ans;
bool judge_1=0;
bool judge(int x)
{
	for(int i=1;i<=n;++i)
	if(x%a[i]) return 0;
	return 1;
}
bool pd(int x)
{
 	for(int i=2;i<=x/i;++i)
 	if(x%i==0) return 0;
	return 1;
}
int cb(int a,int b) {return a*b-a-b;}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		judge_1=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]==1) judge_1=1;
		}
		if(judge_1)
		{
			printf("1\n");
			continue;
		}
	}
	
	return 0;
}
