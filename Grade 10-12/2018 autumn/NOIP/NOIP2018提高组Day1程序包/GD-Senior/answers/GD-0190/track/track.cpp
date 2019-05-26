#include <stdio.h>
#include <algorithm>
#define N 30005
using namespace std;
int n,m,i,j,k,a,b,c,ans,ru[N],h[N],v[N],f[N],s[N],xia[N],dian[N];
struct hhh{
	int a,b,c,n;
}d[N];
void charu(int a,int b,int c){
	d[++j].a=a,d[j].b=b,d[j].c=c;
	d[j].n=h[a],h[a]=j;
}
int dfs(int a){
	int b,i;
	for(i=h[a];i;i=d[i].n){
		b=d[i].b;c=d[i].c;
		if(!v[b]){
			v[b]=v[a]+1;
			f[b]=a;
			s[b]=c;
			int x=dfs(b);
			dian[a]=max(dian[a],xia[a]+x);
			xia[a]=max(xia[a],x);
		}
	}
	return s[a]+=xia[a];
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d", &n, &m);
	if(m==1){
		for(i=1;i<n;i++){
			scanf("%d%d%d", &a, &b, &c);
			charu(a,b,c);charu(b,a,c);
			ru[a]++;ru[b]++;
		}
		v[1]=1;
		dfs(1);
		for(i=1;i<=n;i++)ans=max(ans,dian[i]);
		printf("%d",ans);
		//for(i=1;i<=n;i++)printf("%d %d\n",v[i],f[i]);
		//for(i=1;i<=n;i++)printf("%d %d %d\n",i,s[i],dian[i]);
	}
	return 0;
}
