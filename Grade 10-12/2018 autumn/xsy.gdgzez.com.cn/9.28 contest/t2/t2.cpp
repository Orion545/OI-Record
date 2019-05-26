#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
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
int n,a[200010],dep[200010],cnte,ans=0;
int first[200010];
vector<int>f[200010],g[200010];
struct edge{
	int to,next;
}e[400010];
inline void add(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
bool anti(int l,int r){return l>r;}
void fg(int u,int v){
	int i,pos,su=f[u].size(),sv=g[v].size();
	if(su<sv){
		for(i=0;i<su;i++){
			pos=lower_bound(g[v].begin(),g[v].end(),f[u][i],anti)-g[v].begin();
			ans=max(ans,i+1+pos);
		}
	}
	else{
		for(i=0;i<sv;i++){
			pos=lower_bound(f[u].begin(),f[u].end(),g[v][i])-f[u].begin();
			ans=max(ans,i+1+pos);
		}
	}
}
void only(int u,int v){
	int l1,l2;
	l1=lower_bound(f[u].begin(),f[u].end(),a[u])-f[u].begin();
	l2=lower_bound(g[v].begin(),g[v].end(),a[u],anti)-g[v].begin();
	ans=max(ans,l1+l2+1);
	l1=lower_bound(f[v].begin(),f[v].end(),a[u])-f[v].begin();
	l2=lower_bound(g[u].begin(),g[u].end(),a[u],anti)-g[u].begin();
	ans=max(ans,l1+l2+1);
}
void merge(int u,int v){
	int i,su,sv;
	su=f[u].size();sv=f[v].size();
//	cout<<"	merge "<<su<<' '<<sv<<'\n';
	if(su>=sv) for(i=0;i<sv;i++) f[u][i]=min(f[u][i],f[v][i]);
	else{
		for(i=0;i<su;i++) f[v][i]=min(f[u][i],f[v][i]);
		swap(f[u],f[v]);
	}
	su=g[u].size();sv=g[v].size();
//	cout<<"	merge "<<su<<' '<<sv<<'\n';
	if(su>=sv) for(i=0;i<sv;i++) g[u][i]=max(g[u][i],g[v][i]);
	else{
		for(i=0;i<su;i++) g[v][i]=max(g[u][i],g[v][i]);
		swap(g[u],g[v]);
	}
}
void join(int u){
	int len,pos;
	len=f[u].size();
	pos=upper_bound(f[u].begin(),f[u].end(),a[u])-f[u].begin();
//	cout<<"join "<<u<<' '<<len<<' '<<pos<<' '<<a[u]<<'\n';
	if(!len||!pos||a[u]>f[u][pos-1]){
//		if(len) cout<<"	ok "<<f[u][pos-1]<<'\n';
		if(pos==len) f[u].push_back(a[u]);
		else f[u][pos]=a[u];
	}
	len=g[u].size();
	pos=upper_bound(g[u].begin(),g[u].end(),a[u],anti)-g[u].begin();
//	cout<<"join "<<u<<' '<<len<<' '<<pos<<' '<<a[u]<<'\n';
	if(!len||!pos||a[u]<g[u][pos-1]){
//		if(len) cout<<"	ok "<<g[u][pos-1]<<'\n';
		if(pos==len) g[u].push_back(a[u]);
		else g[u][pos]=a[u];
	}
}
void dfs(int u,int f){
	int i,v;
//	cout<<"dfs "<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs(v,u);
		only(u,v);
		fg(u,v);fg(v,u);
		merge(u,v);
	}
	join(u);
//	cout<<"finish dfs "<<u<<' '<<ans<<'\n';
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);
	printf("%d\n",ans);
}

