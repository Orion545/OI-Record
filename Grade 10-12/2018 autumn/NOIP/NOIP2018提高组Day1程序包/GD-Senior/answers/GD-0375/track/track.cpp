#include <cstdio>
#include <algorithm>
#include <cstring>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define re(i,x) for(i=x; i; i=nex[i])
using namespace std;

const int N=50001,M=N<<1;
int i,j,n,m,a,b,l,r,mid,tot,tov[M],len[M],nex[M],fir[N],dis[N],deg[N],rt,sz[N],f[1001][1001];
bool p[N],bz,jh;

void link(int x,int y) {tov[++tot]=y; len[tot]=l; nex[tot]=fir[x]; fir[x]=tot;}

int dfs(int x)
{
	p[x]=bz;
	int ans=x,i,y;
	re(i,fir[x])
		if(p[y=tov[i]]!=bz)
		{
			dis[y]=dis[x]+len[i]; y=dfs(y);
			if(dis[y]>dis[ans]) ans=y;
		}
	return ans;
}

bool check(int X)
{
	j=2;
	fd(i,n,j)
	{
		if(dis[i]>=X) continue;
		while(j<i&&dis[i]+dis[j]<X) j++;
		if(i==j) return n-i>=m;
		j++;
	}
	return n-i>=m;
}

int min(int x,int y) {return x<y?x:y;}
int max(int x,int y) {return x>y?x:y;}
void MAX(int&x,int y) {if(y>x)x=y;}
void tree_dp(int x)
{
	p[x]=sz[x]=1;
	memset(f[x],200,sizeof f[x]);
	f[x][0]=0;
	int i,l=0,r=0,z=0;
	re(i,fir[x])
		if(!p[tov[i]])
			if(!l) l=tov[i]; else r=tov[i];
		else	z=len[i];
	if(l) 
	{
		tree_dp(l); sz[x]+=sz[l];
		fo(i,0,min(m,sz[l])) 
		{
			if(f[l][i]<0) break;
			MAX(f[x][i],f[l][i]);
			if(f[l][i]>=mid) f[x][i+1]=0;
		}
	}
	if(r)
	{
		tree_dp(r); sz[x]+=sz[r];
		fo(i,0,min(m,sz[l]))
			if(f[l][i]>=0)
				fo(j,0,min(m-i,sz[r]))
					if(f[r][j]>=0)
					{
						MAX(f[x][i+j],max(f[l][i],f[r][j]));
						if(f[l][i]>=mid) MAX(f[x][i+j+1],f[r][j]);
						if(f[r][j]>=mid) MAX(f[x][i+j+1],f[l][i]);
						if(f[l][i]>=mid&&f[r][j]>=mid) MAX(f[x][i+j+2],0);
						if(f[l][i]+f[r][j]>=mid) MAX(f[x][i+j+1],0);
					}
	}
	fo(i,0,min(m,sz[x]))
	{
		if(f[x][i]<0) break;
		f[x][i]+=z;
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m); jh=1;
	fo(i,1,n-1)
	{
		scanf("%d%d%d",&a,&b,&l);
		jh&=(a==1);
		link(a,b); deg[a]++;
		link(b,a); deg[b]++;
	}
	
	if(m==1)
	{
		dis[bz=1]=0; l=dis[a=dfs(1)];
		for(dis[a]=0; bz=!bz,dis[b=dfs(a)]>l; dis[a=b]=0) l=dis[b];
		printf("%d",l);
		return 0;
	}
	
	if(jh)
	{
		dfs(bz=1);
		sort(dis+2,dis+n+1);
		l=0,r=n*10000;
		while(l<r)
		{
			mid=l+r+1>>1;
			if(check(mid))
					l=mid;
			else	r=mid-1;
		}
		printf("%d",l);
		return 0;
	}
	
	fo(rt,1,n) if(deg[rt]<=2) break;
	l=0,r=n*10000;
	while(l<r)
	{
		mid=l+r+1>>1;
		memset(p,0,sizeof p);
		tree_dp(rt);
		if(f[rt][m]>=0)
				l=mid;
		else	r=mid-1;
	}
	printf("%d",l);
}
