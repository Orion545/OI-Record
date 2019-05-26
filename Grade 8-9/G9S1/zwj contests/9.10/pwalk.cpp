#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge{
	int to,w,next;
}e[2010];
int n,q,times=1,first[1010],fa[1010],son[1010],size[1010],dep[1010];
int wei[1010],belong[1010],pos[510][1010],lian[1010],top[1010];
int a[1010][8010],nb[510],len[1010];
bool vis[1010];
void dfs1(int k,int f,int weight){
	int i,u,maxn=0,tmp=0;
	fa[k]=f;vis[k]=1;dep[k]=dep[f]+1;size[k]=1;
	len[k]=weight;
	for(i=first[k];~i;i=e[i].next){
		u=e[i].to;
		if(!vis[u]){
			dfs1(u,k,e[i].w);
			size[k]+=size[u];
			if(size[u]>maxn){
				maxn=size[u];tmp=u;
			}
		}
	}
	son[k]=tmp;
	return;
}
void dfs2(int k,int t,int cnt){
	int i,u;nb[times]++;
	belong[k]=times;pos[times][cnt]=k;wei[k]=cnt;lian[k]=lian[fa[t]]+1;
	vis[k]=1;top[k]=t;
	if(son[k]){
		dfs2(son[k],t,cnt+1);
	}
	for(i=first[k];~i;i=e[i].next){
		u=e[i].to;
		if(!vis[u]){
			++times;
			dfs2(u,u,1);
		}
	}
}
void build(int l,int r,int num,int t){
	if(l==r){
		a[t][num]=len[pos[t][l]];return;
	}
	int mid=(l+r)>>1;
	build(l,mid,num<<1,t);build(mid+1,r,(num<<1)+1,t);
	a[t][num]=a[t][num<<1]+a[t][(num<<1)+1];
	return;
}
int find(int ql,int qr,int l,int r,int num,int t){
	if(qr<l||ql>r) return 0;
	if(l>=ql&&r<=qr) return a[t][num];
	int mid=(l+r)>>1,re=0;
	if(mid>=ql) re+=find(ql,qr,l,mid,num<<1,t);
	if(mid<qr) re+=find(ql,qr,mid+1,r,(num<<1)+1,t);
	return re;
}
void swap(int &x,int &y){
	x^=y;y^=x;x^=y;
}
int query(int l,int r){
	int re=0;
	if(lian[l]>lian[r]) swap(l,r);
	while(lian[r]!=lian[l]){
		re+=find(wei[top[r]],wei[r],1,nb[belong[r]],1,belong[r]);
		r=fa[top[r]];
	}
	while(top[l]!=top[r]){
		re+=find(wei[top[l]],wei[l],1,nb[belong[l]],1,belong[l]);
		l=fa[top[l]];
		re+=find(wei[top[r]],wei[r],1,nb[belong[r]],1,belong[r]);
		r=fa[top[r]];
	}
	if(l==r) return re;
	if(dep[l]>dep[r]) swap(l,r);
	return re+find(wei[l],wei[r],1,nb[belong[l]],1,belong[l])-len[l];
}
int main(){
	freopen("pwalk.in","r",stdin);
	freopen("pwalk.out","w",stdout);
	int i,t1,t2,t3;
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&q);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		e[i*2-1].to=t2;e[i*2-1].w=t3;e[i*2-1].next=first[t1];first[t1]=i*2-1;
		e[i*2].to=t1;e[i*2].w=t3;e[i*2].next=first[t2];first[t2]=i*2;
	}
	memset(vis,0,sizeof(vis));
	dfs1(1,1,0);
	memset(vis,0,sizeof(vis));
	dfs2(1,1,1);
	for(i=1;i<=times;i++) build(1,nb[i],1,i);
	for(i=1;i<=q;i++){
		scanf("%d%d",&t1,&t2);
		printf("%d\n",query(t1,t2));
	}
}
