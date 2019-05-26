#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fup(i,a,b) for(int i=a;i<=b;i++)
#define fow(i,a,b) for(int i=a;i>=b;i--)
const int N = 1e5+7;
int n,m,ls,dq[N],la[N],d[N],b[N];
int p[N],so[N][2],to[N][2],fg[1024][1024];
int ans,f[N][2],f1[N],f2[N],g[1024][1024];
void add(int u,int v,int z)
{
	d[++ls] = v; b[ls] = z;
	la[ls] = dq[u]; dq[u] = ls;
}
void dfs(int w,int fa)
{
	for(int jz=dq[w];jz;jz=la[jz])
	{
		if(d[jz]==fa) continue;
		dfs(d[jz],w);
		int d1 = f[d[jz]][0]+b[jz];
		if(d1>=f[w][0])
		{
			f[w][1] = f[w][0];
			f[w][0] = d1;
		}else if(d1>f[w][1]) f[w][1] = d1;
	} ans = max(ans,f[w][0]+f[w][1]);
}
bool cmp1(int x,int y){ return x<y; }
bool cmp2(int x,int y){ return x>y; }
int calc(int w,int sl)
{
	if(sl==0&&w==n) return 2147483647;
	if(sl==0&&w!=n) return 0;
	if(w==n&&sl!=0) return 0;
	if(g[w][sl]) return g[w][sl];
	int dt = 0,rt = 0;
	fup(i,w,n-1)
	{
		dt = dt+p[i];
		rt = max(rt,min(dt,calc(i+1,sl-1)));
	} g[w][sl] = rt;
	return rt;
}
void ddfs(int x,int fa)
{
	for(int jz=dq[x];jz;jz=la[jz])
	{
		if(d[jz]==fa) continue;
		if(so[x][0]) 
		{
			so[x][1] = d[jz];
			to[x][1] = b[jz];
		} else
		{
			so[x][0] = d[jz];
			to[x][0] = b[jz];
		}
		ddfs(d[jz],x);
	}
}
int slove(int x,int sl)
{
	if(fg[x][sl]) return fg[x][sl];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m); 
	bool a1=1,lk=1;
	fup(i,1,n-1)
	{
		int u,v,z;
		scanf("%d%d%d",&u,&v,&z);
		add(u,v,z); add(v,u,z);
		if(u!=1||v!=1) a1 = false;
		if(u>v) swap(u,v); p[u] = z;
		if(v-1!=u) lk = false;
	}
	if(m==1)
	{
		ans = 0; dfs(1,0);
		printf("%d",ans);
	}else if(a1==true)
	{
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		fup(i,1,ls)
		{
			if(i%2==0) continue;
			f1[i/2+1] = b[i];
			f2[i/2+1] = b[i];
		} int cd = m*2;
		sort(f1+1,f1+cd+1,cmp1);
		sort(f2+1,f2+cd+1,cmp2);
		ans = 2147483647;
		fup(i,1,m) ans = min(ans,f1[i]+f2[i]);
		printf("%d",ans);
	}else if(lk==true)
	{
		printf("%d",calc(1,m));
	}else
	{
		ddfs(1,0); 
		printf("%d",slove(1,m));
	}
	return 0;
}

