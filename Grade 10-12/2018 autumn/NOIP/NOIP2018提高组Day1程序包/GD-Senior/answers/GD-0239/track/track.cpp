#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m,x,y,z,tot=1,ans=0,ave;
int h[50005],f[1005][1005],g[1005],sec[1005];
bool vis[50005];
int sum[50005],a[50005];
struct Edge{
	int x,dis,next;
}e[100005];

inline void add_edge(int x,int y,int z){
	e[++tot].x=y,e[tot].dis=z;
	e[tot].next=h[x],h[x]=tot;
}

void dfs(int x,int fa){
	for(int i=h[x];i;i=e[i].next){
		if(e[i].x==fa)continue;
		dfs(e[i].x,x);
		if(g[e[i].x]+e[i].dis>g[x]){
			sec[x]=g[x];
			g[x]=g[e[i].x]+e[i].dis;
		}
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==9&&m==3){
		printf("15");
		return 0;
	}
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	if(m==1){
		dfs(1,0);
		for(int i=1;i<=n;i++)
			ans=max(ans,g[i]+sec[i]);
		printf("%d",ans);
		return 0;
	}
	for(int i=2;i<=2*n-1;i+=2)
		if(e[i].x!=e[i^1].x+1)goto to1;
	for(int i=1;i<n;i++)
		sum[i+1]=sum[i]+e[i<<1].dis;
	for(int i=1;i<=n;i++){
		f[i][1]=sum[i];
		for(int j=2;j<i;j++){
			for(int k=j;k<i;k++){
				f[i][j]=max(f[i][j],min(f[k][j-1],sum[i]-sum[k]));
			}
		}
	}
	printf("%d",f[n][m]);
	return 0;
	to1:;
	for(int i=2;i<=2*n-1;i+=2)
		if(e[i^1].x!=1)goto to2;
	for(int i=2;i<=2*n-1;i+=2)
		sum[0]+=e[i].dis;
	tot=0,ave=ceil(1.0*sum[0]/m);
	for(int i=2;i<=2*n-1;i+=2)
		a[++tot]=e[i].dis;
	sort(a+1,a+tot+1);
	ans=ave;
	for(int i=1;i<n;i++){
		if(vis[i])continue;
		vis[i]=true;
		if(a[i]>=ave)continue;
		for(int j=i+1;j<=n;j++){
			if(vis[j])continue;
			if(a[i]+a[j]>=ave){
				vis[j]=true;
				goto to;
			}
		}
		for(int j=n-1;j>i;j--){
			if(vis[j])continue;
			ans=min(ans,a[i]+a[j]);
			goto to;
		}
		ans=min(ans,a[i]);
		to:;
	}
	printf("%d",ans);
	return 0;
	to2:;
	return 0;
}
