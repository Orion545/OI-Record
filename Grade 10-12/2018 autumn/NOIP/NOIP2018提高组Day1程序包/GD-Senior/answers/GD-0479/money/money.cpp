#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(const int& x,const int&y)
{
	return x<y;
}
int a[105];
int ans[105];
int num=0;
int cnt=0;
bool tf=false;
void dfs(int u,int v)
{
	if(tf) return;
	if(v>cnt) return;
	if(u%ans[v]==0)
	{
		tf=true;
		return;
	}
	int i=0;
	while(1)
	{
		if(ans[v]*i>u) break;
		dfs(u-(ans[v]*i),v+1);
		i++;
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	int n;
	while(T--)
	{
		num=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1,cmp);
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			tf=false;
			dfs(a[i],1);
			if(!tf)
			{
				cnt++;
				ans[cnt]=a[i];
				num++;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
