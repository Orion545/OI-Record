#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,m,first[100010],sum[100010],dep[100010];
struct edge{
	int to,next;
}a[200010];
int cnte;
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;
	sum[u]=(dep[u]%2)?1:-1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);sum[u]+=sum[v];
	}
}
int main(){
	memset(first,-1,sizeof(first));
	int i,t1,t2;
	n=read();m=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	if(m==n){
		puts("-1");return 0;
	} 
	dfs(1,0);
	t1=t2=0;
	for(i=1;i<=n;i++){
		if(dep[i]%2) t1++;
		else t2++;
	}
	if(t1!=t2){
		puts("-1");return 0;
	}
	int ans=0;
	for(i=1;i<=n;i++){
		ans+=abs(sum[i]);
	}
	cout<<ans;
}
