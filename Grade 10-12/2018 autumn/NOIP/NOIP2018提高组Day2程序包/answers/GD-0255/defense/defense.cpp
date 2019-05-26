#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

template <class T> inline void qread(T &x){
	x=0;char c=getchar();while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}

template <class T> inline void qprint(T x){if (x>=10) qprint(x/10);putchar(x%10+'0');}

template <class T> inline void qput(T x){qprint(x);putchar('\n');}

const int N=1e5+5;
const long long INF=0x3f3f3f3f3f3f3f3f;

int n,m,a,x,b,y;
int p[N],fa[N];
long long f[N][2];
string type;
vector<int> g[N];

bool dfs(int u){
	f[u][1]=p[u];
	f[u][0]=0;
	if (u==a){
		if (x){
			f[u][1]=p[u];
			f[u][0]=INF;
		}
		else{
			f[u][1]=INF;
			f[u][0]=0;
		}
	}
	if (u==b){
		if (y){
			f[u][1]=p[u];
			f[u][0]=INF;
		}
		else{
			f[u][1]=INF;
			f[u][0]=0;
		}
	}
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (v==fa[u]) continue;
		fa[v]=u;
		dfs(v);
		if (f[v][1]==INF) f[u][0]=INF;
		else{
			if (f[u][0]!=INF) f[u][0]+=f[v][1];
		}
		if (f[v][0]==INF&&f[v][1]==INF) f[u][1]=INF;
		else{
			if (f[u][1]!=INF) f[u][1]+=min(f[v][0],f[v][1]);
		}
	}
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	qread(n);qread(m);
	cin>>type;
	for (int i=1;i<=n;i++) qread(p[i]);
	for (int i=1;i<n;i++){
		int u,v;
		qread(u);qread(v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i=1;i<=m;i++){
		qread(a);qread(x),qread(b),qread(y);
		memset(fa,0,sizeof(fa));
		memset(f,0,sizeof(f));
		dfs(1);
		long long ans=min(f[1][0],f[1][1]);
		if (ans>=INF) puts("-1");
		else qput(ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
