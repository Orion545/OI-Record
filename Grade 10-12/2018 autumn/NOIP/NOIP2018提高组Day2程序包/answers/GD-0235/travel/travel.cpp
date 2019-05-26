#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5010
using namespace std;
int n,m,x,y,t[N*2],nx[N*2],l[N],bz[N],ans[N],s[N],w[N][N];
void add(int x,int y){
	t[++t[0]]=y;
	nx[t[0]]=l[x];
	l[x]=t[0];
}
void dg1(int x){
	for(int i=1;i<=w[x][0];i++){
		if(!bz[w[x][i]]){
			bz[w[x][i]]=1;
			ans[++ans[0]]=w[x][i];
			dg1(w[x][i]);
			bz[w[x][i]]=0;
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			w[x][++w[x][0]]=y;
			w[y][++w[y][0]]=x;
		}
		for(int i=1;i<=n;i++){
			sort(w[i]+1,w[i]+w[i][0]+1);
		}
		bz[1]=1;ans[++ans[0]]=1;
		dg1(1);
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		return 0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	bz[1]=1;s[++s[0]]=1;
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
