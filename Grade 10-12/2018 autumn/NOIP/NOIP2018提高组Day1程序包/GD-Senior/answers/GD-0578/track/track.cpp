#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define N 50100
using namespace std;
int n,m,las[N],nxt[N*2],to[N*2],dat[N*2],tot=1,lim,f[N],g[N],d[N],c[N];
void putin(int x,int y,int z)
{
	nxt[++tot]=las[x];las[x]=tot;to[tot]=y;dat[tot]=z;
}
void dg(int x,int fa)
{
	f[x]=g[x]=0;
	for(int i=las[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa) continue;
		dg(y,x);
		f[x]=f[x]+f[y];
	}
	d[0]=0;
	for(int i=las[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa) continue;
		d[++d[0]]=g[y]+dat[i];
		c[d[0]]=0;
	}
	sort(d+1,d+d[0]+1);
	while(d[d[0]]>=lim) d[0]--,f[x]++;
	int l=1;
	fd(i,d[0],1)
	{
		 while(l<i&&d[l]+d[i]<lim) l++;
		 if(l<i) f[x]++,c[i]=l,c[l]=i,l++;
		 else break;
	}
	int k=0;
	fd(i,d[0],1) if(c[i]==0) {k=i;break;}
	fd(i,d[0],k+1) if(d[c[i]]+d[k]>=lim) {k=i;break;}
	if(k>0) g[x]=d[k];
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int r=0;
	fo(i,2,n)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		r+=z;
		putin(x,y,z);putin(y,x,z);
	}
	int l=1;
	while(l+1<r)
	{
		lim=(l+r)/2;
		dg(1,0);
		if(f[1]>=m) l=lim;else r=lim;
	}
	lim=r;dg(1,0);
	if(f[1]>=m) l=r;
	printf("%d\n",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
