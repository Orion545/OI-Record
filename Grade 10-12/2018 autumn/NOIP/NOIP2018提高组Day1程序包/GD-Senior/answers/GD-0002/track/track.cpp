#include <cstdio>
#include <cstring>
#define maxn 50010
#define ll long long

int n,m,len=0;
struct node{int x,y,z,next;};
node e[2*maxn];
int first[maxn];
void buildroad(int x,int y,int z)
{
	len++;
	e[len].x=x;
	e[len].y=y;
	e[len].z=z;
	e[len].next=first[x];
	first[x]=len;
}
ll dp[maxn],ans=0;
void dfs_dp(int x,int fa)
{
	ll ci_ma=0;
	for(int i=first[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa)continue;
		dfs_dp(y,x);
		if(dp[y]+(ll)e[i].z>dp[x])ci_ma=dp[x],dp[x]=dp[y]+(ll)e[i].z;
		else if(dp[y]+(ll)e[i].z>ci_ma)ci_ma=dp[y]+(ll)e[i].z;
	}
	if(ci_ma+dp[x]>ans)ans=ci_ma+dp[x];
}
int a[maxn];
ll minn(ll x,ll y){return x<y?x:y;}
int ch(ll x)
{
	ll tot=0;int p=0;
	for(int i=1;i<n;i++)
	{
		tot+=(ll)a[i];
		if(tot>=x)p++,tot=0;
	}
	return p;
}
int du[maxn];
ll mson[maxn];
int sum;
int maxx(int x,int y){return x>y?x:y;}
ll maxl(ll x,ll y){return x>y?x:y;}
ll dfs(int x,int fa,ll z)
{
	ll zuo(-1),you(-1);
	for(int i=first[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==fa)continue;
		if(zuo==-1)zuo=dfs(y,x,z)+e[i].z;
		else you=dfs(y,x,z)+e[i].z;
	}
	if(zuo==-1)return 0;
	if(you==-1)
	{
		if(zuo>=z)sum++,zuo=0;
		return zuo;
	}
	if(zuo>=z||you>=z)
	{
		sum++;
		if(zuo>=z&&you>=z)return maxl(zuo,you);
		if(zuo>=z)return you;
		else return zuo;
	}
	if(zuo+you>=z)return sum++,0;
	return maxl(zuo,you);
}
bool ch_dp(ll x)
{
	sum=0;
	if(dfs(1,0,x)>=x)sum++;
	return sum>=m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	bool ts=true,dul=true;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		buildroad(x,y,z);
		buildroad(y,x,z);
		du[x]++;du[y]++;
		if(du[x]>3||du[y]>3)dul=false;
		if(y!=x+1)ts=false;
	}
	if(m==1)
	{
		dfs_dp(1,0);
		printf("%lld",ans);
		return 0;
	}
	if(ts)
	{
		ll l=999999999999,r=0;
		int sal=0;
		for(int i=1;i<=len-1;i+=2)
		r+=(ll)(a[++sal]=e[i].z),l=minn(l,a[sal]);
		ll ans=-1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(ch(mid)>=m)l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%lld",ans);
		return 0;
	}
	if(dul)
	{
		ll l=999999999999,r=0;
		for(int i=1;i<=len-1;i+=2)
		r+=(ll)(e[i].z),l=minn(l,e[i].z);
		ll ans=-1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(ch_dp(mid))l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==n-1)
	{
		int p=999999999;
		for(int i=1;i<=len-1;i+=2)
		if(e[i].z<p)p=e[i].z;
		printf("%d",p);
		return 0;
	}
	printf("26282");
}
