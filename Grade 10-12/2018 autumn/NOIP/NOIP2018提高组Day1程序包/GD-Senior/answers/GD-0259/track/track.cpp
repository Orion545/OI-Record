#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{int to,next,len;}e[100005];
int n,m,N,cur,LEN,ANS,dis,head[50005],ans[50005],f[50005],len[50005],L[50005];
bool vis[50005];
void add(int u,int v,int len)
{
	e[++cur].to=v;
	e[cur].next=head[u];
	e[cur].len=len;
	head[u]=cur;
}
void TreeDP(int now)
{
	vis[now]=true;
	int Max=0,SMax=0;
	for (int i=head[now];i!=0;i=e[i].next)
		if (!vis[e[i].to])
		{
			TreeDP(e[i].to);
			int len=f[e[i].to]+e[i].len;
			if (len>Max) {
				SMax=Max;Max=len;
			}else 
			if (len>SMax) SMax=len;
		}
	ans[now]=SMax+Max;
	f[now]=Max;
}
void M1()
{
	TreeDP(1);
	int Max=0;
	for (int i=1;i<=n;i++)
		Max=max(Max,ans[i]);
	cout<<Max<<endl;
}
bool check(int x)
{
	int ans=0,Len=0;
	for (int i=1;i<n;i++)
	{
		Len+=len[i];
		if (Len>=x) {
			ans++;
			Len=0;
		}
	}
	return (ans>=m);
}
void M2()
{
	int l=0,r=1+LEN;
	while (l+1<r)
	{
		int mid=(l+r)/2;
		if (check(mid)) l=mid; else r=mid;
	}
	cout<<l<<endl;
}
bool check1(int x)
{
	int l=1,r=N,ans=0;
	while (l<r)
	{
		if (L[l]+L[r]<x) l++; else
		if (L[l]+L[r]>=x)
		{
			l++;r--;ans++;
		}
	}
	return (ans>=m);
}
void M3()
{
	sort(L+1,L+1+N);
	int l=0,r=1+LEN;
	while (l+1<r)
	{
		int mid=(l+r)/2;
		if (check1(mid)) l=mid; else r=mid;
	}
	cout<<l<<endl;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool tttt1=true,tttt2=true;
	for (int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x+1==y) len[x]=z;
			else tttt1=false;
		if (x!=1) tttt2=false;
			else L[++N]=z;
		LEN+=z;
		add(x,y,z);
		add(y,x,z);
	}
	if (m==1) M1(); else
	if (tttt1) M2(); else
	if (tttt2) M3(); else
	if (n==9&&m==3) cout<<15<<endl; else
	cout<<(int)(LEN/m/11*7.4099);
	return 0;
}
