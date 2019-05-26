#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
int lst[50005],nxt[100005],e[100005],cnt=0;
LL v[100005];
bool flag1=true,flag2=true;
LL l[50005],ans=0;
int tot=0;
LL a[50005];
LL f[50005];
void build(int x,int y,LL z)
{
	e[++cnt]=y;
	nxt[cnt]=lst[x];
	lst[x]=cnt;
	v[cnt]=z;	
}
int n,m;
int calc(LL x)
{
	int tot=0;
	LL sum=0;
	for(int i=1;i<n;i++)
	{
		sum+=a[i];
		if(sum>=x)
		{
			tot++;
			sum=0;
		}
	}
	return tot;
}
void dfs(int x,int fa)
{
	f[x]=0;
	LL mx=0,mxx=0;
	for(int u=lst[x];u;u=nxt[u])
	{
		int y=e[u];
		if(y==fa) continue;
		dfs(y,x);
		LL sum=f[y]+v[u];
		if(sum>=mx)
		{
			mxx=mx;
			mx=sum;
		}
		else if(sum>mxx) mxx=sum;
	}
	ans=max(ans,mxx+mx);
	f[x]=mx;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		LL z;
		scanf("%d%d%lld",&x,&y,&z);
		build(x,y,z);
		build(y,x,z);
		if(x!=1) flag1=false;
		if(y!=x+1) flag2=false;
		l[++tot]=z;
		a[x]=z;
		ans+=z;
	}
	if(flag1)
	{
		sort(l+1,l+tot+1);
		if(2*m<=tot)
		{
			for(int i=1;i<=m;i++)
				ans=min(ans,l[tot-i+1]+l[tot-2*m+i]);
		}
		else
		{
			int sum=tot-m;
			for(int i=1;i<=sum;i++)
				ans=min(ans,l[i]+l[i+sum]);
			for(int i=2*sum+1;i<=tot;i++)
				ans=min(ans,l[i]);
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(flag2)
	{
		LL l=1,r=ans;
		while(l<r)
		{
			LL mid=(l+r+1)/2;
			if(calc(mid)<m) r=mid-1;
			else l=mid;
		}
		printf("%lld\n",l);
		return 0;
	}
	if(m==1)
	{
		ans=0;
		dfs(1,0);
		printf("%lld\n",ans);
		return 0;
	}
	return 0;
}
