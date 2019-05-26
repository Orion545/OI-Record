#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int head[30005],to[60010],next[60010],from[60010],e[60010],ie=0;
int ans=-1;
int chu[30005],mc;
void add(int x,int y,int z)
{
	to[ie]=y;from[ie]=x;
	e[ie]=z;next[ie]=head[x];
	head[x]=ie;ie++;
}
bool h[30010];
void dfs(int a,int u,int val,int val2)
{
	if(val2==0) return;
	//printf("a=%d val=%d val2=%d\n",a,val,val2);
	for(int i=head[u];i!=-1;i=next[i])
	{
		int v=to[i];
		if(h[i/2]) continue;
		h[i/2]=true;
		chu[u]--;chu[v]--;
		dfs(a,v,val+e[i],val2);
		if(a==m)
		{
			if(val2!=9999999)
			ans=max(ans,min(val+e[i],val2));
			else ans=max(ans,val+e[i]);
		}
		chu[u]++;chu[v]++;
		h[i/2]=false;
	}
	if(a<m)
	for(int i=1;i<=n;i++)
	if(chu[i])
	dfs(a+1,i,0,min(val,val2));
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	//cout<<head[1]<<endl;
	scanf("%d%d",&n,&m);
	for(int i=1,a,b,c;i<=n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		chu[a]++;chu[b]++;
		add(a,b,c);add(b,a,c);
	}
	for(int i=1;i<=n;i++)
	if(chu[i]==1)
	mc=i;
	dfs(1,mc,0,9999999);
	printf("%d",ans);
}
