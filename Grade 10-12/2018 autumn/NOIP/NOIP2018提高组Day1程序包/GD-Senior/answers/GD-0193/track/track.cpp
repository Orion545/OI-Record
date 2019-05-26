#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,tot,ans;
int nxt[100001],last[100001];
int f[100001];
struct eg
{
	int u,v,w;
}e[100001];

void add(int u,int v,int w)
{
	e[++tot]=(eg){u,v,w};nxt[tot]=last[u];last[u]=tot;
}
int islian()
{
	int bj=1;
	for(int i=1;i<=tot;i++)
		if(e[i].u-e[i].v!=1 && e[i].v-e[i].u!=1)
		{
			bj=0;break;
		}
		else f[min(e[i].u,e[i].v)]=e[i].w;
	return bj;
}
int pd1(int x)
{
	int cnt=0;
	for(int i=1,s=0;i<n;i++)
	if(s+f[i]<x) s+=f[i];
	else cnt++,s=0;
	return cnt>=m;
}
int sol1()
{
	int l=0,r=0,mid;
	for(int i=1;i<n;i++) r+=f[i];
	while(l<r)
	{
		mid=l+r>>1;
		if(pd1(mid)) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int sol2(int u,int fa)
{
	int mx1=0,mx2=0,res;
	for(int i=last[u];i;i=nxt[i])
	{
		int v=e[i].v;
		if(v==fa) continue;
		res=sol2(v,u)+e[i].w;
		if(res>mx1) mx2=mx1,mx1=res;
		else if(res>=mx2) mx2=res;
	}
	ans=max(ans,mx1+mx2);
	return mx1;
}
int ai1()
{
	for(int i=1;i<=tot;i++)
		if(min(e[i].u,e[i].v)!=1) return 0;
	return 1;
}
bool cmp(int a,int b)
{
	return a>b;
}
int sol3()
{
	for(int i=1;i<n;i++)
		f[i]=e[(i<<1)-1].w;
	sort(f+1,f+n,cmp);
	int j=m+1;
	ans=1e9;
	for(int i=m;i;j++,i--)
		ans=min(ans,f[i]+((j<n)?f[j]:0));
	return ans;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	if(islian()) return 0 & printf("%d\n",sol1());
	else if(m==1) 
	{
		int t=sol2(1,0);
		return 0 &printf("%d\n",ans);
	}
	else if(ai1()) return 0 &printf("%d\n",sol3());
	return 0;
}
