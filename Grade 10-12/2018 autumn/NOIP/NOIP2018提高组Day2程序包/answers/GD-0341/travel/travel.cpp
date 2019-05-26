#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<cctype>
#define go(i,a,b) for(register int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
const int N=5007;
inline int read (int& x) {
	bool f=0;char c;
	for(;!isdigit(c=getchar());f|=(c=='-'));
	for(x=0;isdigit(c);c=getchar())x=x*10+(c^48);
	return x=(f?-x:x);
}
inline void swap(int& a,int& b) {a^=b;b^=a;a^=b;}
int n,m,du[N];
vector<int> node[N];
inline void print(int& x) {
	static int cnt=0;
	if(++cnt!=n) printf("%d ",x);
	else printf("%d",x);
}
void dfs0(int x,int fa) {
	print(x);int l=du[x];
	go(i,0,l-1)
		if(node[x][i]!=fa)
			dfs0(node[x][i],x);
}
void dfs1(int x) {
	static bool vis[N]={0};
	static int& tp=node[1][1];
	if(vis[x]) return;
	print(x);vis[x]=1;
	go(i,0,1) {
		if(node[x][i]>tp && !vis[tp]) {dfs1(tp);return;}
		if(!vis[node[x][i]]) dfs1(node[x][i]);
	}
}
void dfs(int x,int fa) {
	print(x);
	sort(node[x].begin(),node[x].end());
	int l=du[x];
	go(i,0,l-1) {
		int& y=node[x][i];
		if(y!=fa)
			dfs(y,x);
	}
}
bool incirle[N]={0};
void dfss(int x,int fa) {
	static bool vis[N]={0};
	if(vis[x])  {incirle[x]=1;return;}
	vis[x]=1;
	sort(node[x].begin(),node[x].end());
	go(i,0,du[x]-1) {
		int& y=node[x][i];
		if(y!=fa) {
			dfss(y,x);
			if(incirle[y] && du[x]>1) incirle[x]=1;
		}
		
	}
}
void dfsss(int x,int fa) {
	static bool vis[N]={0};
	static int rukou=0,pos=2;
	vis[x]=1;print(x);
	if(!incirle[x]) {
		int l=du[x];
		go(i,0,l-1)
			if(node[x][i]!=fa) 
				dfsss(node[x][i],x);	
	}else {
		if(!rukou) rukou=x,pos=(rukou==1)?1:2;
		int l=du[x];
		go(i,0,l-1){
			bool flag=1;
			if(pos>=du[rukou]) pos=du[rukou]-1,flag=0;
			int &y=node[x][i],&z=node[rukou][pos];
			if(vis[y]) continue;
			if(flag && !vis[z] && y>z) {dfsss(node[rukou][pos++],x);return;}
			dfsss(y,x);
		}
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n);read(m);int u,v;bool f1=1;
	go(i,1,m) {
		read(u);read(v);
		node[u].push_back(v);
		node[v].push_back(u);
		f1&=(++du[u]<3),f1&=(++du[v]<3);
	} 
	if(f1)
		if(m==n-1)
			dfs0(1,0);
		else {
			if(node[1][0]>node[1][1])
				swap(node[1][0],node[1][1]);
			dfs1(1);
		}	
	else {
		if(m==n-1)
			dfs(1,0);
		else{
			dfss(1,0);
			dfsss(1,0);
		}
	}
	return 0;
}
