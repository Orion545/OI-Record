#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<queue>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,g[2010][2010],a[2010],vis[2010],in[2010];
int first[2010],cnte;
struct edge{
	int to,next;
}e[10010];
inline void add(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;in[v]++;
}
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
void dfs(int u){
//	cout<<"dfs "<<u<<'\n';
	vis[u]=1;int i;
	for(i=1;i<=n;i++){
//		cout<<"	try "<<i<<" from "<<u<<' '<<g[u][i]<<'\n';
		if(!vis[i]&&!g[u][i]) add(u,i),dfs(i);
	}
}
struct gaygayquan{
	int val,id;
};
inline bool operator <(gaygayquan x,gaygayquan b){
	return x.val<b.val;
}
gaygayquan mp(int l,int r){
	return (gaygayquan){l,r};
}
priority_queue<gaygayquan>q;
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,j,v;gaygayquan gay;
	for(i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			if(gcd(a[i],a[j])==1) g[i][j]=g[j][i]=1;
//			cout<<i<<' '<<j<<' '<<a[i]<<' '<<a[j]<<' '<<g[i][j]<<'\n';
		}
	}
	for(i=1;i<=n;i++) if(!vis[i]) dfs(i);
	for(i=1;i<=n;i++) if(!in[i]) q.push(mp(a[i],i));
	while(!q.empty()){
		gay=q.top();q.pop();
		printf("%d ",gay.val);
		for(i=first[gay.id];~i;i=e[i].next){
			v=e[i].to;in[v]--;
			if(in[v]==0) q.push(mp(a[v],v));
		}
	}
}

