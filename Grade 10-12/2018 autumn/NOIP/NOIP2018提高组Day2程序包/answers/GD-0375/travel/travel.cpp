#include <cstdio>
#include <algorithm>
#include <cstring>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;

const int N=5010,M=N<<1;
int i,n,m,u,v,tot=1,st[N],en[N],t,ans[N],a[N],lim,bz;
bool p[N];
struct T
{
	int x,y,i;
}e[M];
bool cmpx(T a,T b) {return a.x<b.x;}
bool cmpy(T a,T b) {return a.y<b.y;}

void dfs(int x)
{
	if(t>n) return;
	if((a[t]=x)<ans[t]&&bz==1) bz=2;
	if((a[t]=x)>ans[t]&&bz==1) bz=0;
	p[x]=1;
	int i,y;
	fo(i,st[x],en[x])
		if(!p[y=e[i].y]&&e[i].i!=lim)
			t++,dfs(y);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		scanf("%d%d",&u,&v);
		e[++tot]=(T){u,v,i}; 
		e[++tot]=(T){v,u,i};
	}
	sort(e+2,e+tot+1,cmpx);
	fo(i,2,tot)
	{
		if(e[i].x!=e[i-1].x) st[e[i].x]=i;
		if(e[i].x!=e[i+1].x) sort(e+st[e[i].x],e+(en[e[i].x]=i)+1,cmpy);
	}
	
	fo(i,1,n) ans[i]=n;
	
	if(m==n-1)
	{
		dfs(t=bz=1);
		fo(i,1,n) printf("%d ",a[i]);
		return 0;
	}
	
	fo(lim,1,m)
	{
		memset(p,0,sizeof p);
		if(dfs(t=bz=1),bz==2)
		{
			fo(i,1,n) if(!p[i]) goto endl;
			memcpy(ans,a,sizeof a);
		}
		endl:;
	}
	fo(i,1,n) printf("%d ",ans[i]);
}
