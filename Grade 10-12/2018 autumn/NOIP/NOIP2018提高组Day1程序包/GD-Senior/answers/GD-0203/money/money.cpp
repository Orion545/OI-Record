#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;
bool c[110],f[25010];
int a[110],b[110],d[110];
int n,cnt,ans,T;

bool judge() 
{
	int cnt1=0;
	for (int i=1;i<=cnt;i++) if (c[i]) d[++cnt1]=b[i];
	for (int i=0;i<=b[cnt];i++) f[i]=false;
	f[0]=true;
	for (int i=1;i<=cnt1;i++) 
	for (int j=0;j<=b[cnt];j++) 
	if (j-d[i]>=0 && f[j-d[i]]) f[j]=true;
	bool flag=true;
	for (int i=1;i<=cnt;i++) if (!c[i] && !f[b[i]]) flag=false;
	return flag;
}

void dfs(int s) 
{
	if (s>cnt) 
	{
		int sum=0;
		for (int i=1;i<=cnt;i++) if (c[i]) sum++;
		if (judge()) ans=min(ans,sum); 
		return;
	}
	c[s]=true;
	dfs(s+1);
	c[s]=false;
	dfs(s+1);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--) 
	{
		scanf("%d",&n);
		ans=n;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=1;i<=n;i++) 
		if (a[i]!=0) 
		for (int j=i+1;j<=n;j++) if (a[j]%a[i]==0) a[j]=0;
		cnt=0;
		for (int i=1;i<=n;i++) if (a[i]!=0) b[++cnt]=a[i];
		ans=cnt;
		sort(b+1,b+cnt+1);
		for (int i=1;i<=cnt;i++) c[i]=false;
		dfs(1);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
