#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[50003],b[50003],v[50003],bj,map[23][23],mmax,dis[233],vis[233],nmax;
int mymax(int x,int y){
	if (x>y) return x;else return y;
}
void dijk(int s){
	for (int i=1;i<=n;++i) {dis[i]=0;vis[i]=0;}
	dis[s]=0;vis[s]=1;int now=s;
	for (int j=2;j<=n;++j){
		for (int i=1;i<=n;++i)
		if (map[now][i] && !vis[i]){
			if (dis[now]+map[now][i]>dis[i]) dis[i]=dis[now]+map[now][i];
		}
		vis[now]=1;nmax=0;
		for (int i=1;i<=n;++i)
		if (dis[i]>nmax && !vis[i]){
			nmax=dis[i];now=i;
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;++i){
		scanf("%d%d%d",&a[i],&b[i],&v[i]);
		if (a[i]!=1) bj=1;map[a[i]][b[i]]=map[b[i]][a[i]]=v[i];
	}
	if (bj==0){
		sort(v+1,v+n);
		printf("%d",v[n-1]+v[n-2]);
	}
	else {
		for (int j=1;j<=n;++j){
			dijk(j);for (int k=1;k<=n;++k) if (dis[k]>mmax && dis[k]!=0x7FFFFFFF) mmax=dis[k];
		}printf("%d",mmax);
	}
	return 0;
}
