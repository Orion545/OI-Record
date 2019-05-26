#include <cstdio>
#include <algorithm>
#define Add(x,y) (nxt[++num]=head[x],head[x]=num,V[num]=y)
#define For(x) for(int h=head[x],o=V[h]; h; o=V[h=nxt[h]])
using namespace std;
int head[5005],nxt[10005],V[10005],num;
int n,m;
int q[500005],cnt;

void dfs1(int x,int fa){
	int l=cnt+1,r;
	For(x) if (o!=fa) q[++cnt]=o;
	r=cnt;
	sort(q+l,q+r+1);
	for (int i=l; i<=r; i++){
		printf(" %d",q[i]);
		dfs1(q[i],x);
	}
}


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,uu,vv; i<=m; i++) scanf("%d%d",&uu,&vv),Add(uu,vv),Add(vv,uu);
	if (m==n-1){
		printf("%d",1);
		dfs1(1,0);
		puts("");
		return 0;
	}
	
	if (m==n){
		for (int i=1; i<=n; i++) printf("%d ",n);
	}
	
	return 0;
}
