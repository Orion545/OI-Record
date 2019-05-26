using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7f7f7f7f7f7fll
#define N 100000
#define M 100000
int n,m;
char str[3];
int w[N+1];
struct EDGE{
	int to;
	EDGE *las;
} e[N*2+1];
int ne;
EDGE *last[N+1];
int bz[N+1];
long long f[N+1][3];
void dp(int x,int fa){
	f[x][0]=INF;
	f[x][1]=w[x];
	f[x][2]=0;
	long long sum=0,mn=INF;
	for (EDGE *ei=last[x];ei;ei=ei->las)
		if (ei->to!=fa){
			dp(ei->to,x);
			long long tmp=min(f[ei->to][0],f[ei->to][1]);
			if (f[ei->to][1]-tmp<mn)
				mn=f[ei->to][1]-tmp;
			sum+=tmp;
			f[x][1]+=min(tmp,f[ei->to][2]);
			f[x][2]+=f[ei->to][0];
		}
	f[x][0]=sum+mn;
	if (bz[x]==-1)
		f[x][1]=INF;
	else if (bz[x]==1)
		f[x][0]=f[x][2]=INF;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,str);
	for (int i=1;i<=n;++i)
		scanf("%d",&w[i]);
	for (int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		++ne;
		e[ne].to=v,e[ne].las=last[u],last[u]=e+ne;
		++ne;
		e[ne].to=u,e[ne].las=last[v],last[v]=e+ne;
	}
	while (m--){
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		bz[a]=(x?1:-1);
		bz[b]=(y?1:-1);
		dp(1,0);
		long long ans=min(f[1][0],f[1][1]);
		printf("%lld\n",(ans>=INF)?-1:ans);
		bz[a]=bz[b]=0;
	}
	return 0;
}
