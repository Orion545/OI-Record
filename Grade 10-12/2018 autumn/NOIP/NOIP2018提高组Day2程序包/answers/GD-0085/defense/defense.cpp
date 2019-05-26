#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,m,x,y,p,q,p1,q1,h,tot,a[N],last[N*2],nex[N*2],to[N*2],fa[N],ll[505],rr[505],pp[N];
long long ans,f[N][2],f1[N][2],g[N],f2[N][2],f3[505][4],h1[4],h2[4],u[4];
char s[5];
void add(int x,int y)
{
	to[++tot]=y;
	nex[tot]=last[x];
	last[x]=tot;
}
long long min(long long a,long long b){return a<b?a:b;}
void dg(int x,int y)
{
	fa[x]=y;
	f[x][0]=0,f[x][1]=a[x];
	if (x==q) f[x][q1^1]=2e10;
	for (int i=last[x];i;i=nex[i])
	if (to[i]!=y)
	{
		dg(to[i],x);
		f[x][0]+=f[to[i]][1];
		g[to[i]]=min(f[to[i]][0],f[to[i]][1]);
		f[x][1]+=g[to[i]];
	}
}
void make(int x)
{
	int l=ll[x],r=rr[x];
	f2[l][1]=2e10;
	f2[l][0]=0;
	if (p==l) f2[p][p1^1]=2e10;
	if (q==l) f2[q][q1^1]=2e10;
	for (int i=l+1;i<=r;i++)
	{
		f2[i][0]=f2[i-1][1];
		f2[i][1]=a[i]+min(f2[i-1][0],f2[i-1][1]);
		if (p==i) f2[p][p1^1]=2e10;
		if (q==i) f2[q][q1^1]=2e10;
	}
	f3[x][0]=f2[r][0],f3[x][1]=f2[r][1];
	f2[l][0]=2e10;
	f2[l][1]=a[l];
	if (p==l) f2[p][p1^1]=2e10;
	if (q==l) f2[q][q1^1]=2e10;
	for (int i=l+1;i<=r;i++)
	{
		f2[i][0]=f2[i-1][1];
		f2[i][1]=a[i]+min(f2[i-1][0],f2[i-1][1]);
		if (p==i) f2[p][p1^1]=2e10;
		if (q==i) f2[q][q1^1]=2e10;
	}
	f3[x][2]=f2[r][0],f3[x][3]=f2[r][1];
}
void merge(long long f[4],long long g[4])
{
	u[0]=min(f[0]+g[2],min(f[1]+g[0],f[1]+g[2]));
	u[1]=min(f[0]+g[3],min(f[1]+g[1],f[1]+g[3]));
	u[2]=min(f[2]+g[2],min(f[3]+g[0],f[3]+g[2]));
	u[3]=min(f[2]+g[3],min(f[3]+g[1],f[3]+g[3]));
}
void find()
{
	u[0]=0,u[1]=0,u[2]=0,u[3]=0;
	for (int i=1;i<=tot;i++) merge(u,f3[i]);
	ans=2e10;
	for (int i=0;i<4;i++) if (u[i]<ans) ans=u[i];
	if (ans>=2e10) ans=-1;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s\n",s+1);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	if (n<=2000 && m<=2000)
	{
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&p,&p1,&q,&q1);
			dg(p,0);
			ans=-1;
			if (f[p][p1]<2e10) ans=f[p][p1];
			printf("%lld\n",ans);
		}
		return 0;
	}
	if (s[1]=='B')
	{
		dg(1,0);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&p,&p1,&q,&q1);
			f1[q][q1]=f[q][q1];
			f1[q][q1^1]=2e10;
			for (;q!=1;q=fa[q])
			{
				f1[fa[q]][0]=f[fa[q]][0]-f[q][1]+f1[q][1];
				f1[fa[q]][1]=f[fa[q]][1]-g[q]+min(f1[q][0],f1[q][1]);
			}
			ans=-1;
			if (f1[p][p1]<2e10) ans=f1[p][p1];
			printf("%lld\n",ans);
		}
		return 0;
	}
	if (s[1]=='A')
	{
		for (;h*h<n;) h++;
		tot=1;
		ll[1]=rr[1]=1,pp[1]=1;
		for (int i=2;i<=n;i++)
		{
			if (rr[tot]-ll[tot]+1==h) tot++,ll[tot]=rr[tot]=i;
			else rr[tot]++;
			pp[i]=tot;
		}
		for (int i=1;i<=tot;i++) make(i);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&p,&p1,&q,&q1);
			h1[0]=f3[pp[p]][0],h1[1]=f3[pp[p]][1],h1[2]=f3[pp[p]][2],h1[3]=f3[pp[p]][3];
			h2[0]=f3[pp[q]][0],h2[1]=f3[pp[q]][1],h2[2]=f3[pp[q]][2],h2[3]=f3[pp[q]][3];
			make(pp[p]);
			make(pp[q]);
			find();
			printf("%lld\n",ans);
			f3[pp[p]][0]=h1[0],f3[pp[p]][1]=h1[1],f3[pp[p]][2]=h1[2],f3[pp[p]][3]=h1[3];
			f3[pp[q]][0]=h2[0],f3[pp[q]][1]=h2[1],f3[pp[q]][2]=h2[2],f3[pp[q]][3]=h2[3];
		}
		return 0;
	}
	return 0;
}
