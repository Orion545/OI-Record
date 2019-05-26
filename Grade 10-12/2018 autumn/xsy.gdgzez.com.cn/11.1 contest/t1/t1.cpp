/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,useless,cnte=-1,first[200010],vis[200010],pre[200010],belong[200010],ans[200010];
struct edge{
	int to,next,w;
}a[600010];bool in[600010];
vector<int>top;
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
void dfs(int u,int t){
	int i,v;vis[u]=1;belong[u]=t;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		in[i]=in[i^1]=1;
		pre[v]=pre[u]^a[i].w;dfs(v,t);
	}
}
int main(){
//	freopen("in.in","r",stdin);
//	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();m=read();useless=read();int i,t1,t2,t3;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			top.push_back(i);
			dfs(i,i);
		}
	}
	for(i=0;i<=cnte;i+=2){
		if(in[i]) continue;
		if((pre[a[i].to]^pre[a[i^1].to])!=a[i].w){
			puts("-1");return 0;
		}
	}
//	cout<<"check "<<useless<<'n';
	reverse(top.begin(),top.end());
	for(i=0;i<top.size();i++){
		if(i==0) ans[top[i]]=useless-1;
		else ans[top[i]]=0;
	}
	for(i=1;i<=n;i++) if(!ans[i]) ans[i]=ans[belong[i]]^pre[i];
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
}
