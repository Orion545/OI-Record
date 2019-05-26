#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int u[5010],v[5010],path[40010],l[5010],r[5010];
bool _in[5010];
int st[5010],tp;
void dfs(int x,int f)
{
	st[++tp]=x;
	for (int i=l[x];i<=r[x];i++)
	if (path[i]&&path[i]!=f) dfs(path[i],x);
}

int cntcir,cir[5010];
bool in1[5010];
void getcir(int x,int f)
{
	if (cntcir) return;
	if (in1[x])
	{
		while (st[tp]!=x) cir[++cntcir]=st[tp],tp--;
		cir[++cntcir]=x;return;
	}
	in1[x]=1;st[++tp]=x;
	for (int i=l[x];i<=r[x];i++) if (path[i]!=f) getcir(path[i],x);	
	in1[x]=0;tp--;
}
int ans[5010];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&u[i],&v[i]);
	l[1]=1;
	for (int i=1;i<=n;i++,l[i]=r[i-1]+1,r[i]=r[i-1])
		for (int j=1;j<=m;j++)
		if (u[j]==i) path[++r[i]]=v[j];else if (v[j]==i) path[++r[i]]=u[j];
	for (int i=1;i<=n;i++) sort(path+l[i],path+r[i]+1);
		
	if (m==n-1)
	{
		_in[1]=1;dfs(1,0);
		for (int i=1;i<=n;i++) printf("%d ",st[i]);		
	} else
	{
		getcir(1,0);
		int ll,rr;ans[0]=-1;
		for (int K=1;K<=cntcir;K++)
		{
			if (K==46)
			{
				int xxx=1;
			}
			ll=cir[K];if (K<cntcir) rr=cir[K+1];else rr=cir[1];
			for (int i=l[ll];i<=r[ll];i++) if (path[i]==rr) path[i]=0;
			for (int i=l[rr];i<=r[rr];i++) if (path[i]==ll) path[i]=0;
			tp=0;
			dfs(1,0);
			if (ans[0]==-1) memcpy(ans,st,sizeof(st));
			else
			{
				for (int i=1;i<=n;i++) 
				if (st[i]<ans[i])
				{
					memcpy(ans,st,sizeof(st));break;
				} else if (st[i]>ans[i]) break;
			}
			for (int i=l[ll];i<=r[ll];i++) if (!path[i]) path[i]=rr;
			for (int i=l[rr];i<=r[rr];i++) if (!path[i]) path[i]=ll;
		}
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	}

	return 0;
}
