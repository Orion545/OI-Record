#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#define inf 2147483647
using namespace std;
typedef long long ll;
struct edge{
	int v,w,next;
}a[100001];
int n,m,u,v,maxn=-inf,sum=0,w[50001],tot=0,fa[50001][17],dis[50001],dep[50001],head[50001];
bool ok1=true,ok2=true,used[50001];
void add(int u,int v,int w){
	a[++tot].v=v;
	a[tot].w=w;
	a[tot].next=head[u];
	head[u]=tot;
}
void dfs(int u,int ff,int dpt,int ds){
	dep[u]=dpt;
	dis[u]=ds;
	fa[u][0]=ff;
	for(int i=1;i<=16;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int tmp=head[u];tmp!=-1;tmp=a[tmp].next){
		int v=a[tmp].v;
		if(v!=ff){
			dfs(v,u,dpt+1,ds+a[tmp].w);
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int l=dep[u]-dep[v];
	for(int i=16;i>=0;i--){
		if((1<<i)&l){
			u=fa[u][i];
		}
	}
	if(u==v)return u;
	for(int i=16;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i],v=fa[v][i];
		}
	}
	return fa[u][0];
}
void work(int dep,int mi){
	if(dep>m){
		maxn=max(maxn,mi);
		return;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int z=lca(i,j);
			for(int x=i;x!=z;x=fa[x][0])if(used[x])continue;
			for(int x=j;x!=z;x=fa[x][0])if(used[x])continue;
			for(int x=i;x!=z;x=fa[x][0])used[x]=true;
			for(int x=j;x!=z;x=fa[x][0])used[x]=true;
			work(dep+1,min(mi,dis[i]+dis[j]-dis[z]*2));
			for(int x=i;x!=z;x=fa[x][0])used[x]=false;
			for(int x=j;x!=z;x=fa[x][0])used[x]=false;
		}
	}
}
void work1(){
	dfs(1,0,1,0);
	work(1,inf);
	printf("%d",maxn);
}
void work2(){
	int x=-1,mx=0,maxn=0;
	dfs(1,0,1,0);
	for(int i=1;i<=n;i++){
		if(x==-1||dis[i]>mx){
			mx=dis[i];
			x=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=x){
			maxn=max(maxn,dis[i]+dis[x]-dis[lca(i,x)]*2);
		}
	}
	printf("%d",maxn);
}
bool chk3(int k){
	int nw=0,ret=0;
	for(int i=1;i<n;i++){
		nw+=w[i];
		if(nw>=k){
			ret++;
			nw=0;
		}
	}
	return ret>=m;
}
void work3(){
	int l=0,r=sum/m,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(chk3(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}
bool chk4(int k){
	int t1=1,t2,ret;
	for(int i=1;i<n;i++){
		if(w[i]>=k){
			t2=i-1;
			break;
		}
	}
	ret=n-t2-1;
	for(;t1<t2;){
		if(w[t1]+w[t2]<k)t1++;
		else{
			ret++;
			t1++;
			t2--;
		}
	}
	return ret>=m;
}
void work4(){
	int l=0,r=sum/m,ans=0;
	sort(w+1,w+n);
	while(l<=r){
		int mid=(l+r)/2;
		if(chk4(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&w[i]);
		add(u,v,w[i]);
		add(v,u,w[i]);
		sum+=w[i];
		if(v!=u+1)ok1=false;
		if(u!=1)ok2=false;
	}
	if(m==1)work2();
	else if(ok1)work3();
	else if(ok2)work4();
	else work1();
	return 0;
}
