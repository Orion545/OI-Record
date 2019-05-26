#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5010;
int n,m,tot;
struct Data{
	int a[N],len;
	friend bool operator < (Data x,Data y){
		for (int i=1;i<=n;++i)
			if (x.a[i]!=y.a[i]) return x.a[i]<y.a[i];
		return false;
	}
	void print(){
		for (int i=1;i<=len;++i) printf("%d ",a[i]);
	}
}ans,now;
struct xxx{
	int y,nxt,ban;
}a[N*2];
int h[N],cir[N],vis[N],st[N],lis[N][N];
int tm;
void add(int x,int y){a[++tot].y=y; a[tot].nxt=h[x]; h[x]=tot; a[tot].ban=0;}
bool cmp(int x,int y){return a[x].y<a[y].y;}
void prework(){
	for (int i=1;i<=n;++i){
		lis[i][0]=0;
		for (int j=h[i];j!=-1;j=a[j].nxt)
			lis[i][++lis[i][0]]=j;
		sort(lis[i]+1,lis[i]+1+lis[i][0],cmp);
	}
}
void dfs(int x){
	int u;
	now.a[++now.len]=x;
	vis[x]=tm;
	for (int i=1;i<=lis[x][0];++i){
		u=a[lis[x][i]].y;
		if (vis[u]==tm||a[lis[x][i]].ban) continue;
		dfs(u);
	}
}
void solve(){
	++tm;
	now.len=0;
	dfs(1);
	if (now.len==n&&(ans.len==0||now<ans))
		ans=now;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	int x,y;
	scanf("%d%d",&n,&m);
	memset(h,-1,sizeof(h));
	tot=-1;
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	prework();
	ans.len=0;
	if (m==n-1){
		solve();
	}
	else{
		for (int i=0;i<=tot;i+=2){
			a[i].ban=1; a[i^1].ban=1;
			solve();
			a[i].ban=0; a[i^1].ban=0;
		}
	}
	ans.print();
}
