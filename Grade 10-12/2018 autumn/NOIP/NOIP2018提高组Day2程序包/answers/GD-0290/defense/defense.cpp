#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=1e5+2;
typedef long long ll;
int lj[N<<1],nxt[N<<1],fir[N],p[N];
ll f[N][2],g[N][2];
int n,m,i,j,x,xx,y,z,zz,c,bs;
inline void read(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
inline void add(int x,int y)
{
	lj[++bs]=y;
	nxt[bs]=fir[x];
	fir[x]=bs;
	lj[++bs]=x;
	nxt[bs]=fir[y];
	fir[y]=bs;
}
void dfs(int x,int y)
{
	f[x][0]=0;f[x][1]=p[x];
	int i;
	for (i=fir[x];i;i=nxt[i]) if (lj[i]!=y)
	{
		dfs(lj[i],x);
		if (lj[i]==z)
		{
			if (zz)
			{
				f[x][0]+=f[lj[i]][1]; 
				f[x][1]+=f[lj[i]][1];
			}
			else
			{
				f[x][0]=1e9;
				f[x][1]+=f[lj[i]][0];
			}
		}
		else
		{
			f[x][0]+=f[lj[i]][1];
			f[x][1]+=min(f[lj[i]][0],f[lj[i]][1]);
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n);read(m);
	if ((n<=2000)&&(m<=2000))
	{
		read(x);
		for (i=1;i<=n;i++) read(p[i]);
		for (i=1;i<n;i++)
		{
			read(x);read(y);
			add(x,y);
		}
		while (m--)
		{
			read(x);read(xx);read(z);read(zz);
			dfs(x,x);
			if (f[x][xx]<1e9) printf("%lld\n",f[x][xx]); else printf("-1\n");
		}
		return 0;
	}
	while ((c<'A')||(c>'C')) c=getchar();
	if (c=='A')
	{
		read(zz);
		for (i=1;i<=n;i++) read(p[i]);
		for (i=1;i<n;i++)
		{
			read(x);read(x);
		}
		g[n][0]=0;g[n][1]=p[n];
		for (i=n-1;i;i--)
		{
			g[i][0]=g[i+1][1];
			g[i][1]=min(g[i+1][0],g[i+1][1])+p[i];
		}
		if (zz==1)
		{
			f[1][0]=1e9;f[1][1]=p[1];
			for (i=2;i<=n;i++)
			{
				f[i][0]=f[i-1][1];
				f[i][1]=min(f[i-1][0],f[i-1][1])+p[i];
			}
			while (m--)
			{
				read(x);read(x);read(x);read(xx);
				if (xx) printf("%lld\n",min(f[x-1][0],f[x-1][1])+min(g[x+1][0],g[x+1][1])+p[x]);
				else printf("%lld\n",f[x-1][1]+g[x+1][1]);
			}
			return 0;
		}
		f[1][1]=p[1];
		for (i=2;i<=n;i++)
		{
			f[i][0]=f[i-1][1];
			f[i][1]=min(f[i-1][0],f[i-1][1])+p[i];
		}
		while (m--)
		{
			read(x);read(xx);read(z);read(zz);
			if ((xx|zz)==0)
			{
				printf("-1\n");
				continue;
			}
			printf("%lld\n",f[x][xx]+g[z][zz]);
		}
		return 0;
	}
	z=0;dfs(1,1);
	while (m--)
	{
		read(x);read(xx);read(z);read(zz);
		if ((xx|zz)==0)
		{
			for (i=fir[xx];i;i=nxt[i]) if (lj[i]==z)
			{
				printf("-1\n");z=0;
				break;
			}
			if (z==0) continue;
		}
		if (z==1)
		{
			swap(x,z);swap(xx,zz);
		}
		if (x==1) printf("%lld\n",f[1][xx]); else printf("%lld\n",min(f[1][0],f[1][1]));
	}
}