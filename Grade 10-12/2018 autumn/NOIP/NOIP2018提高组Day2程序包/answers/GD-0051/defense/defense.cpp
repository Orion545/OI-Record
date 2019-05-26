#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <vector>
const long long inf=1e15;
const int mo=1e9+7;
const int N=1e5+5;
using namespace std;
int n,m,fa[N],v[N],deep[N],in[N];
char s[10];
int lt[N*2],nt[N*2],to[N*2],tot;
long long f[N][2];
void link(int x,int y)
{
	nt[++tot]=lt[x];
	lt[x]=tot;
	to[tot]=y;
}
long long min(long long x,long long y)
{
	return x<y?x:y;
}
void dg(int x)
{
	deep[x]=deep[fa[x]]+1;
	f[x][0]=0,f[x][1]=v[x];
	for(int i=lt[x];i;i=nt[i])
	{
		int j=to[i];
		if(j==fa[x]) continue;
		fa[j]=x,dg(j);
		f[x][0]+=f[j][1];
		f[x][1]+=min(f[j][0],f[j][1]);
	}
	if(in[x]==0) f[x][1]=inf;
	else
	if(in[x]==1) f[x][0]=inf;
}
void up(int x)
{
	for(;x;x=fa[x])
	{
		f[x][0]=0,f[x][1]=v[x];
		for(int i=lt[x];i;i=nt[i])
		{
			int j=to[i];
			if(j==fa[x]) continue;
			f[x][0]+=f[j][1];
			f[x][1]+=min(f[j][0],f[j][1]);
		}
		if(in[x]==0) f[x][1]=inf;
		else
		if(in[x]==1) f[x][0]=inf;
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++) scanf("%d",&v[i]);
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),link(x,y),link(y,x);
	memset(in,1,sizeof(in));
	dg(1);
	for(int i=1,x,t1,y,t2;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&t1,&y,&t2);
		in[x]=t1,in[y]=t2;
		if(m<=2000)
		{
			dg(1);
			long long ans=min(f[1][0],f[1][1]);
			printf("%lld\n",ans>=inf?-1:ans);
			in[x]=in[y]=in[0];
		}
		else
		{
			if(deep[x]>deep[y]) up(x),up(y);
			else up(y),up(x);
			long long ans=min(f[1][0],f[1][1]);
			printf("%lld\n",ans>=inf?-1:ans);
			in[x]=in[y]=in[0];
			if(deep[x]>deep[y]) up(x),up(y);
			else up(y),up(x);
		}
	}
}
