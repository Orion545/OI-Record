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
int n,m,first[300010],cnte;
struct edge{
	int to,next,w;
}a[600010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
int dep[300010],d[300010],st[300010][20],fa[300010];
void dfs(int u,int f,int w){
	int i,v;
	dep[u]=dep[f]+1;d[u]=d[f]+w;
	st[u][0]=f;fa[u]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u,a[i].w);
	}
}
void ST(){
	int i,j;
	for(j=1;j<20;j++){
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	}
}
int lca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
//	cout<<"finish phase 1 "<<l<<' '<<r<<'\n';
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			r=st[r][i];
			l=st[l][i];
		}
	}
//	cout<<"finish phase 2 "<<l<<' '<<r<<'\n';
	return st[l][0];
}
int getdis(int l,int r){
	return d[l]+d[r]-(d[lca(l,r)]<<1);
}
int ql[300010],qr[300010],dis[300010],top[300010];
int maxn,tot,maxd,cnt[300010],tag[300010];
void getmax(int u,int f){
	int i,v;cnt[u]=tag[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		getmax(v,u);cnt[u]+=cnt[v];
	}
//	cout<<"finish getmax "<<u<<' '<<add[u]<<' '<<tot<<' '<<cnt[u]<<'\n';
	if(cnt[u]!=tot) return;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		if(cnt[v]==tot) maxn=max(maxn,a[i].w);
	}
}
bool check(int lim){
	int i;
	maxd=maxn=tot=0;
	memset(tag,0,sizeof(tag));
	for(i=1;i<=m;i++){
		if(dis[i]<=lim) continue;
		maxd=max(maxd,dis[i]);
		tot++;
		tag[ql[i]]++;tag[qr[i]]++;
		tag[top[i]]--;tag[fa[top[i]]]--;
	}
	getmax(1,0);
//	cout<<"check "<<lim<<' '<<tot<<' '<<maxn<<' '<<maxd<<'\n';
	return (maxn+lim>=maxd);
}
int main(){
//	freopen("in.in","r",stdin);
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dfs(1,0,0);ST();
	for(i=1;i<=m;i++){
		ql[i]=read(),qr[i]=read();
		dis[i]=getdis(ql[i],qr[i]);
		top[i]=lca(ql[i],qr[i]);
//		cout<<"input query "<<ql[i]<<' '<<qr[i]<<' '<<top[i]<<' '<<dis[i]<<'\n';
	}
	int l=0,r=1e9,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
