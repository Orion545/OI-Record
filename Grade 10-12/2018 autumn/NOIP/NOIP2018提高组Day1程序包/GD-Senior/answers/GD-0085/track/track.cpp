#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005;
int n,m,x,y,z,tot,l,r,mid,num,ans,last[N],nex[N*2],to[N*2],v[N*2],f[N],g[N],d[N],s[N],t[N];
void add(int x,int y,int z)
{
	to[++tot]=y;
	v[tot]=z;
	nex[tot]=last[x];
	last[x]=tot;
}
void dg(int x,int y)
{
	f[x]=0;
	for (int i=last[x];i;i=nex[i])
	if (to[i]!=y)
	{
		dg(to[i],x);
		f[x]+=f[to[i]];
	}
	d[0]=0;
	for (int i=last[x];i;i=nex[i])
	if (to[i]!=y) 
	{
		if (g[to[i]]+v[i]<mid) d[++d[0]]=g[to[i]]+v[i];
		else f[x]++;
	}
	g[x]=0;
	sort(d+1,d+d[0]+1);
	num=0;
	for (int i=1;i<=d[0];i++)
	{
		if (i==d[0])
		{
			g[x]=d[i];
			break;
		}
		if (d[i]+d[d[0]]>=mid) 
		{
			num++;
			s[num]=i,t[num]=d[0];
			d[0]--;
		}
		else g[x]=d[i];
	}
	f[x]+=num;
	t[num+1]=t[num]-1;
	for (int i=num;i;i--) 
	{
		s[0]=t[num]-num+i-1;
		while (t[i]>t[i+1]+1 && d[s[0]]+d[t[i]-1]>=mid) 
		{
			g[x]=d[t[i]];
			t[i]--;
		}
	}
	t[num+1]=s[num];
	for (int i=num;i;i--) 
	{
		s[0]=s[num]-num+i;
		while (t[i]>t[i+1]+1 && d[s[0]]+d[t[i]-1]>=mid) 
		{
			g[x]=d[t[i]];
			t[i]--;
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
		r+=z;
	}
	l=1;
	while (l<=r)
	{
		mid=l+r>>1;
		dg(1,0);
		if (f[1]>=m) ans=mid,l=mid+1; else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
