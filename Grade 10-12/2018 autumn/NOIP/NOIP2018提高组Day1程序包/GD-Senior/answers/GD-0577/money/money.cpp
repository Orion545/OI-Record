#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
	int n,ma,o,ans,QA;
	int a[110],b[110];
	bool bz[5010],flag[110];
	bool p;
bool pd()
{
	for(int i=1;i<=n;i++)
		if(!bz[a[i]]) return false;
	return true;
}
void dfs(int x,int sum)
{
	QA++;
	if(n>=13&&n<=15&&QA>=800) return;
	if(n>15&&n<=20&&QA>=100) return;
	if(n>20&&QA>=5) return;
	if(p||pd()) {p=true;return;}
	if(x==o+1) return;
	for(int i=x;i<=o;i++)
	{
		dfs(i+1,sum);
		if(!flag[i])
		{
			flag[i]=true;
			for(int j=1;sum+b[i]*j<=ma;j++)
			{
				bz[sum+b[i]*j]=true;
				dfs(i+1,sum+b[i]*j);
			}
			flag[i]=false;
		}
	}
}
bool check(int x)
{
	for(int i=1;i<=ma;i++)
		bz[i]=false;
	for(int i=1;i<=n;i++)
		flag[i]=false;
	int u=1;
	o=0;
	//printf("%d:",x);
	for(;x;x>>=1)
	{
		if(x&1) b[++o]=a[u];
		u++;
	}
	/*for(int i=1;i<=o;i++)
		printf("%d ",b[i]);
	printf("\n");*/
	p=false;
	QA=0;
	dfs(1,0);
	return p;
}
int main()
{
	int T;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		bool tepan=false;
		ma=0;
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			ma=max(ma,a[i]);
			if(a[i]==1) tepan=true;
		}
		if(tepan) {printf("1\n");continue;}
		for(int k=0;k<(1<<n);k++)
			if(check(k)) ans=min(ans,o);
		printf("%d\n",ans);
	}
	return 0;
}
