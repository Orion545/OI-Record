#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define N 100005
#define LL long long
using namespace std;
LL f[N],g[N],h[N],gr[N],fr[N],hr[N];
int fs[N],nt[2*N],dt[2*N],n,m1,m,pr[N],dep[N],ft[N][20],bf[N];
void link(int x,int y)
{
	nt[++m1]=fs[x];
	dt[fs[x]=m1]=y;	
}
void dfs(int k,int fa)
{
	ft[k][0]=fa;
	dep[k]=dep[fa]+1;
	f[k]=pr[k],h[k]=0;
	if(bf[k]==0) f[k]=1e13;
	if(bf[k]==1) h[k]=1e13;
	LL mi=1e13;
	for(int i=fs[k];i;i=nt[i])
	{
		int p=dt[i];
		if(p!=fa) 
		{
			dfs(p,k);
			f[k]+=g[p];
			h[k]+=f[p];
		}
	}	
	g[k]=min(h[k],f[k]);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	char c1,c2;
	scanf(" %c%c",&c1,&c2);
	memset(bf,255,sizeof(bf));
	fo(i,1,n) scanf("%d",&pr[i]);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		link(x,y),link(y,x);
	}
	if(n<=2000&&m<=2000)
	{
		fo(j,1,19) fo(i,1,n) ft[i][j]=ft[ft[i][j-1]][j-1];
		fo(i,1,m)
		{
			int p,q,x,y;
			scanf("%d %d %d %d",&p,&x,&q,&y);
			bf[p]=x,bf[q]=y;
			dfs(1,0);
			if(g[1]>=1e13) printf("-1\n");
			else printf("%lld\n",g[1]);
			bf[p]=-1,bf[q]=-1;
		}
	}
	else if(c1=='A')
	{
		if(c2=='1')
		{
			dfs(1,0);
			fr[1]=pr[1];
			gr[1]=pr[1];
			hr[1]=1e13;
			fo(i,2,n) 
			{
				fr[i]+=gr[i-1]+pr[i];
				hr[i]+=fr[i-1];
				gr[i]=min(fr[i],hr[i]);
			}
			fo(i,1,m)
			{
				int p,q,x,y;
				scanf("%d %d %d %d",&p,&x,&q,&y);	
				if(y==0)
				{
					if(q==1) {printf("-1\n");continue;}
					printf("%lld\n",fr[q-1]+f[q+1]);
				}
				else
				{
					printf("%lld\n",gr[q-1]+f[q]);
				}
			}
		}
		else
		{
			dfs(1,0);
			fr[1]=pr[1];
			gr[1]=0;
			hr[1]=0;
			fo(i,2,n) 
			{
				fr[i]+=gr[i-1]+pr[i];
				hr[i]+=fr[i-1];
				gr[i]=min(fr[i],hr[i]);
			}
			fo(i,1,m)
			{
				int p,q,x,y;
				scanf("%d %d %d %d",&p,&x,&q,&y);	
				if(p>q) swap(p,q),swap(x,y);
				if(p==q&&x!=y) printf("-1\n");
				else
				{
					if(p==q-1&&x==0&&y==0) printf("-1\n");
					else
					{
						LL s=0;
						if(x==0) s+=hr[p];
						else s+=fr[p];
						if(y==0) s+=h[q];
						else s+=f[q];
						printf("%lld\n",s); 
					}
				}
			}
		}
	}
}
