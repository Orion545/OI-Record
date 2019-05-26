#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#define fo(i,x,y) for(i=x;i<=y;i++)
#define dw(i,x,y) for(i=x;i>=y;i--)
#define N 100055
using namespace std;
int n,m,i,j,k,x,y,t,tot,l,r,mid,ans,cnt,top;
int nxt[N],lst[N],f[N],d[N],tr[N*4],s[N];
bool bz[N];
struct edge{int to,len;}b[N];
void link(int x,int y,int len)
{
	b[++tot].to=y;
	b[tot].len=len;
	nxt[tot]=lst[x];
	lst[x]=tot;
}
void dfs(int x,int fa)
{
	int i,l=lst[x],now;
	while (l)
	{
		int to=b[l].to;
		if (to!=fa) dfs(to,x);
		l=nxt[l];
	}
	d[0]=0;
	l=lst[x];
	while (l)
	{
		int to=b[l].to;
		if (to!=fa) d[++d[0]]=f[to]+b[l].len;
		l=nxt[l];
	}
	if (!d[0]) return;
	sort(d+1,d+d[0]+1);
	fo(i,1,d[0]) bz[i]=true;
	now=top=0;
	dw(i,d[0],1)
		if (d[i]>=k)
		{
			bz[i]=false;
			cnt++;
		}else
		{
			now=i;
			s[++top]=now;
			break;
		}
	fo(i,1,d[0])
	{
		if (!bz[i]) continue;
		while (d[now-1]+d[i]>=k && now>1) now--,s[++top]=now;
		if (d[now]+d[i]<k) continue;
		while (top && (!bz[s[top]] || s[top]<=i)) top--;
		if (top)
		{
			bz[i]=bz[s[top]]=0;
			top--;
			cnt++;
		}
	}
	dw(i,d[0],1)
		if (bz[i])
		{
			f[x]=d[i];
			break;
		}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1)
	{
		scanf("%d%d%d",&x,&y,&t);
		link(x,y,t);link(y,x,t);
		r+=t;
	}
	while (l<=r)
	{
		mid=l+r>>1;
		cnt=0;k=mid;
		memset(f,0,sizeof(f));
		dfs(1,0);
		if (cnt>=m) ans=mid,l=mid+1;else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
