#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;
const int inf=1<<30;
int n,d[maxn],ans,c[maxn],temp,minn=inf,pos,now,f[maxn][maxn];
bool vis[maxn];
void work(int l,int r,int t)
{
	if(r<l)return;
	if(l==r)
	{
		ans+=d[l]-t;
		return;
	}
	ans+=f[l][r]-t;
	t=f[l][r];
	int p=l;
	temp=t;
	while(l<=r)
	{
		if(d[l]==t)
		{
			work(p,max(1,l-1),temp);
			while(d[l]<=temp)l++;
			p=l;
		}
		l++;
	}
	work(p,r,t);
}
int cal(int l,int r)
{
	if(l==r)return d[l];
	int mid=(l+r)/2;
	f[l][mid]=cal(l,mid);
	f[mid+1][r]=cal(mid+1,r);
	return min(f[l][mid],f[mid+1][r]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(minn>d[i])minn=d[i];
	}
	f[1][n]=cal(1,n);
	work(1,n,0);
	printf("%d",ans);
	return 0;
}
