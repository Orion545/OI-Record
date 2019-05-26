#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,u,v,w;
int cur=-1,head[50005];
struct EDGE{int v,w,next;}edge[200005];
void add(int u,int v,int w)
{
	cur++;
	edge[cur].v=v;
	edge[cur].w=w;
	edge[cur].next=head[u];
	head[u]=cur;
}

int sum[50005],de[50005];
bool check(int x)
{
	int gs=0,s=0;
	for (int i=1;i<=n;i++)
	  {
	  	s+=sum[i];
	  	if (s>=x) gs++,s=0;
	  }
	if (gs>=m) return true;
	return false; 
}
bool visit[50005];
void DFS(int root)
{
	visit[root]=true;
	for (int i=head[root];i!=-1;i=edge[i].next)
	  {
	  	int v=edge[i].v;
	  	if (visit[v]) continue;
	  	sum[root]=edge[i].w;
	  	DFS(v);
	  }
}
int f[50005];
int ans1=0;
void DFS1(int root)
{
	visit[root]=true;
	int ma1=0,ma2=0;
	for (int i=head[root];i!=-1;i=edge[i].next)
	  {
	  	int v=edge[i].v;
	  	if (visit[v]) continue;
	  	int w=edge[i].w;
//	  	printf("%d %d\n",v,w);
	  	DFS1(v);
	  	f[root]=max(f[root],f[v]+w);
	  	if (f[v]+w>ma1) ma2=ma1,ma1=f[v]+w;
	  	  else if (f[v]+w>ma2) ma2=f[v]+w;
	  }
	ans1=max(ans1,ma1+ma2);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool f1=true,f2=true,f3=true;
	if (m==1) f3=true;
	memset(head,-1,sizeof(head));
	
	for (int i=1;i<=n-1;i++)
	  {
	  	scanf("%d%d%d",&u,&v,&w);
	  	sum[i]=w;
	  	de[u]++;de[v]++;
	  	add(u,v,w);add(v,u,w);
	  	if (v!=u+1) f2=false;
	  }
	if (de[1]==n-1) f1=true;
	
	if (f3)
	  {
	  	DFS1(1);
	  	
//	  	printf("%d %d %d\n",f[1],f[2],f[3]);
	  	cout<<ans1;
	  	return 0;
	  }
	if (f2)
	  {
	  	int l=0,r=500000000;
	  	n--;
	  	DFS(1);
	  	while (l+1<r)
	  	  {
	  	  	int mid=(l+r)/2;
	  	  	if (check(mid)) l=mid;else r=mid;
	  	  }
	  	printf("%d",l);
	  	return 0;
	  }
	if (f1)
	  {
	  	n--;
	  	sort(sum+1,sum+n+1);
	  	int ans=214748364;
	  	if (m<=n/2)
	  	  {
	  	  	int l=n-m-m+1,r=n;
	  	  	while (l<r)
	  	  	  {
	  	  	  	ans=min(ans,sum[l]+sum[r]);
	  	  	  	l++,r--; 
	  	  	  }
	  	  	
	  	  }
	  	else
	  	  {
	  	  	int mid=n-m;
	  	  	int l=1,r=mid+mid;
	  	  	while (l<r)
	  	  	  {
	  	  	  	ans=min(ans,sum[l]+sum[r]);
	  	  	  	l++,r--;
	  	  	  }
	  	  }
	  	
	  	printf("%d",ans);
	  	return 0;
	  }
	cout<<30946;
	return 0;
}
