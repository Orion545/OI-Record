#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
const int N=5e4+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<48||ch>57) f=(ch=='-')?-1:1,ch=getchar();
	while (ch>=48&&ch<=57) x=(x*10)+(ch^48),ch=getchar();
	return x*f;
}
struct Edge{
	int to,dist,next;
}edges[N<<1];
int tot=0,head[N];
void AddEdge(int from,int to,int dist){
	edges[++tot]=(Edge){to,dist,head[from]};
	head[from]=tot;
}
int n,m,in[N],ans=0,v[N],d[N],sum;
void dfs(int now,int x){
	v[x]=1;
	if (now>ans) ans=now;
	for (int i=head[x];i;i=edges[i].next){
		int e=edges[i].to,dis=edges[i].dist;
		if (!v[e]) dfs(now+dis,e);
	}
	return;
}
int pd(int mid,int now,int x,int tot){
	v[x]=1;
	if (now<=0) tot++,now=mid;
	for (int i=head[x];i;i=edges[i].next){
		int e=edges[i].to,dis=edges[i].dist;
		if (!v[e]) return pd(mid,now-dis,e,tot);
	}
	if (tot>=m) return 1;else return 0;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	int flag=1,f2=1;
	for (int i=1;i<=n-1;i++){
		int u=read(),v=read(),dist=read();
		if (u!=1) flag=0;
		if (v!=u+1) f2=0;
		d[i]=dist;
		sum+=dist;
		AddEdge(u,v,dist);
		AddEdge(v,u,dist);
		++in[u];
		++in[v];
	}
	if (flag){
		sort(d+1,d+n);
		printf("%d\n",d[n-m]);
		return 0;
	}
	if (f2){
		int pp=0;
		for (int i=1;i<=n;i++) if (in[i]==1){
			pp=i;
			break;
		}
		int l=0,r=sum;
		while (l<r){
			int mid=(l+r)>>1;
			memset(v,0,sizeof(v));
			if (pd(mid,mid,pp,0)) l=mid+1;else r=mid-1;
		}
		if (pd(l,l,pp,0)) printf("%d\n",l);else printf("%d\n",l-1);
		return 0;
	}
	if (m==1){
		for (int i=1;i<=n;i++) if (in[i]==1) {
			memset(v,0,sizeof(v));
			dfs(0,i);
		}
		printf("%d\n",ans);
		return 0;
	}
	
}
