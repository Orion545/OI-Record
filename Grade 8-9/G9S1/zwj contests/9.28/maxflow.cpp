#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct edgee{
	int to,next;
}edge[100010];
struct node{
	int fa,sum,tag,dep;
	vector<int>son;
	node(){
		fa=sum=tag=dep=0;
	}
}a[50010];
int n,q,first[50010],ans=0;
bool vis[50010];
int st[50010][20];
int read(){
	int re=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		re=re*10+(int)(ch-'0');ch=getchar();
	}
	return re;
}
void dfs(int k,int fa){
	int i,v;a[k].fa=fa;a[k].dep=a[fa].dep+1;vis[k]=1;
	for(i=first[k];~i;i=edge[i].next){
		v=edge[i].to;
		if(!vis[v]){
			dfs(v,k);a[k].son.push_back(v);
		}
	}
}
void init(){
	int i,j;
	for(j=1;j<20;j++){
		for(i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
void lca(int l,int r){
	if(a[l].dep<a[r].dep) swap(l,r);
	int i,tl=l,tr=r,lca;
	for(i=19;i>=0;i--){
		if(a[st[l][i]].dep>=a[tr].dep) l=st[l][i];
	}
	if(l==r){
		a[tl].tag+=1;
		if(tr!=1) a[a[tr].fa].tag-=1;
		return;
	}
	for(i=19;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			l=st[l][i];r=st[r][i];
		}
	}
	lca=a[l].fa;
	a[tl].tag+=1;
	a[tr].tag+=1;
	a[lca].tag-=1;
	if(lca!=1) a[a[lca].fa].tag-=1;
}
void calc(int k){
	int i,v;
	for(i=0;i<a[k].son.size();i++){
		calc(a[k].son[i]);
	}
	for(i=0;i<a[k].son.size();i++){
		v=a[k].son[i];
		if(a[v].tag!=0){
			a[k].tag+=a[v].tag;
		}
	}
	a[k].sum=a[k].tag;
	ans=max(ans,a[k].sum);
	return;
}
int main(){
	freopen("maxflow.in","r",stdin);
	freopen("maxflow.out","w",stdout);
	int i,j,t1,t2;
	n=read();q=read();
	memset(first,-1,sizeof(first));
	for(i=1;i<n;i++){
		t1=read();t2=read();
		edge[i*2-1].to=t2;edge[i*2-1].next=first[t1];first[t1]=i*2-1;
		edge[i*2].to=t1;edge[i*2].next=first[t2];first[t2]=i*2;
	}
	dfs(1,1);
	for(i=1;i<=n;i++) st[i][0]=a[i].fa;
	init();
	for(i=1;i<=q;i++){
		t1=read();t2=read();
		lca(t1,t2);
	}
	calc(1);
	ans=max(ans,a[1].sum);
	printf("%d",ans);
}
