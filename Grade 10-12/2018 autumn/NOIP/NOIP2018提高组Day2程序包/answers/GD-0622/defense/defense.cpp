#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
#define _ read()
const int N=1e5+5;
struct Edge{ int to,nxt; }e[N<<1];
int head[N],cnt,val[N],n,m,p[N];
inline void insert( int u,int v ) {
	e[cnt]=(Edge) { v,head[u]};
	head[u]=cnt++;
}
inline void ins( int u,int v ) {
	insert(u,v);
	insert(v,u);
}
long long f[N][3];
inline void dfs( int x,int fa ) {
	long long ans=2e18;
	f[x][1]=f[x][1]+p[x];
	long long sum=0;
	for(int i=head[x];~i;i=e[i].nxt) {
		if(e[i].to!=fa) {
			dfs(e[i].to,x);
			f[x][1]+=min(f[e[i].to][0],f[e[i].to][2]); //0:没放但是自己被覆盖，1:放了，2:没放，自己没被覆盖 
			f[x][2]+=f[e[i].to][0];
			sum+=f[e[i].to][0];
		}
	}
	for(int i=head[x];~i;i=e[i].nxt) 
		if(e[i].to!=fa) ans=min(ans,(sum-f[e[i].to][0])+f[e[i].to][1]);
	f[x][0]=ans;
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char s[10];
	memset(head,-1,sizeof(head));
	n=_; m=_; scanf("%s",s);
	for(int i=1;i<=n;i++)
		p[i]=_;
	for(int i=1;i<n;i++) {
		int u=_,v=_;
		ins(u,v);
	}
	while(m--) {
		int a=_,x=_,b=_,y=_;
		f[a][x==0?1:0]=f[b][y==0?1:0]=2e18;
		dfs(1,0);
		printf("%lld\n",min(f[1][1],f[1][0])==2e18?-1:min(f[1][1],f[1][0]));
	}
}
/*
5 3 C3
2 4 1 3 9
1 5
5 2
5 3
3 4
1 0 3 0
2 1 3 1
1 0 5 0
*/
