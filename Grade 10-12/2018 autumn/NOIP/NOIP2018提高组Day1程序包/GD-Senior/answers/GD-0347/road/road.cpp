#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,d[100010],ans,lsb;
int s[10010],vis[10010],c[10010],f[10010],cnt,znum,tmp;
priority_queue<int,vector<int >,greater<int > >q; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i) 
	{
		scanf("%d",&d[i]);
		++d[i];
		++c[d[i]];
		if (!vis[d[i]]) q.push(d[i]),++cnt;
		vis[d[i]]=1;
	}
	d[0]=d[n+1]=0;
	for (int i=1;i<=n;++i) 
	{
		if (d[i]>d[i-1] || d[i]>d[i+1]) ++s[d[i]];
		if (d[i]==d[i-1] || d[i]==d[i+1]) ++s[d[i]];
		if (d[i]>d[i-1] && d[i]>d[i+1]) ++s[d[i]];
		if (d[i]>d[i-1] && d[i]==d[i+1]) ++s[d[i]],f[d[i]]=1;
		if (d[i]==d[i-1] && d[i]>d[i+1] && !f[d[i]]) ++s[d[i]];
		if (d[i]==d[i-1] && d[i]>d[i+1] && f[d[i]]) f[d[i]]=0;
	}
	znum=1;
	for (int i=1;i<=cnt;++i)
	{
		tmp=q.top();
		q.pop();
		ans+=(tmp-lsb)*znum;
		lsb=tmp;
		znum+=c[tmp]-s[tmp];
	}
	printf("%d",ans-1);
	return 0;
}
