#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=20000;
int f[N],next[N],h[N],st[N],ed[N],q[N],g[N],ans[N],x[N],y[N];
bool b[N];
int tot,n,m,now,w,step,no;
void add(int x,int y)
{
	f[++tot]=y;
	next[tot]=h[x];
	h[x]=tot;
}
void dfs1(int t)
{
	int p=h[t];
	st[t]=step+1;
	while(p){
		q[++step]=f[p];
		p=next[p];
	}
	ed[t]=step;
	sort(q+st[t],q+ed[t]+1);
}
void dfs2(int t)
{
	g[++w]=t;
	b[t]=true;
	int p=h[t];
	fo(i,st[t],ed[t])if(!b[q[i]]&&(
	(t!=x[no]||q[i]!=y[no])&&(t!=y[no]||q[i]!=x[no])
	))dfs2(q[i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=1;
	fo(i,1,m){
		scanf("%d%d",&x[i],&y[i]);
		add(x[i],y[i]);
		add(y[i],x[i]);
	}
	fo(i,1,n)dfs1(i);
	ans[1]=n+1;
	if(n==m){
	fo(i,1,m){
		fo(j,1,n)b[j]=false;
		no=i;
		w=0;
		dfs2(1);
		if(w<n)continue;
		bool p=false;
		fo(j,1,n)if(g[j]!=ans[j]){
			if(g[j]<ans[j])p=true;
			break;	
		}
		if(p)fo(j,1,n)ans[j]=g[j];
	}
	}
	else{
		w=0;
		dfs2(1);
		fo(j,1,n)ans[j]=g[j];	
	}
	fo(i,1,n)printf("%d ",ans[i]);
}
