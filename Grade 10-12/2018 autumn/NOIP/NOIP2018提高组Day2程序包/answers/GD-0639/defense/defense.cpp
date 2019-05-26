#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <bitset>
using namespace std;
#define int long long
inline int read()
{
	int f=1,k=0;char c=getchar();
	while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
const int maxn=2e5+100,inf=1e12;
int last[maxn],val[maxn];
struct mc{int too,nxt;}e[maxn<<1];
int f[maxn][2],ans;
bool yes[maxn],v[maxn];
inline int min(const int a,const int b){return a<b?a:b;}
void dfs(const int cur,const int fa)
{
	f[cur][0]=0;f[cur][1]=val[cur];
	for (int i=last[cur];i;i=e[i].nxt)
	if (e[i].too!=fa)
	{
		dfs(e[i].too,cur);
		if (yes[e[i].too])
		{
			if (v[e[i].too])f[cur][1]+=f[e[i].too][1],f[cur][0]+=f[e[i].too][1];
			else f[cur][1]+=f[e[i].too][0],f[cur][0]=inf;
		}
		else f[cur][1]+=min(f[e[i].too][1],f[e[i].too][0]),f[cur][0]+=f[e[i].too][1];
	}
//	cout << cur <<": "<<f[cur][1]<<" "<<f[cur][0]<<endl;
}
signed main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char s[20];
	int n=read(),m=read();scanf("%s",s);
	for (int i=1;i<=n;i++)val[i]=read();
	for (int i=1,a,b;i<n;i++)
	a=read(),b=read(),
	e[i<<1].too=b,e[i<<1].nxt=last[a],last[a]=i<<1,
	e[i<<1|1].too=a,e[i<<1|1].nxt=last[b],last[b]=i<<1|1;
	for (int i=1;i<=m;i++)
	{
		int a=read(),av=read(),b=read(),bv=read();
		memset(f,0,sizeof(f));
		yes[a]=1;yes[b]=1;v[a]=av;v[b]=bv;
		dfs(1,0);
		int ans=inf;
		if (yes[1])
		{
			if (v[1])ans=f[1][1];
			else ans=f[1][0];
		}
		else ans=min(f[1][1],f[1][0]);
		printf("%lld\n",ans>=inf?-1:ans);
		yes[a]=yes[b]=0;
	}
}
