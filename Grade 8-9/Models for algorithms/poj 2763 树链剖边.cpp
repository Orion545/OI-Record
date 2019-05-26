#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
	int to,next;
}edge[100010];
int head[100010]; 
int fa[100010],dep[100010],size[100010],son[100010],top[100010],w[100010];
int n,n1=0,q,s;
int a[400010];//segment tree
int dfs1(int k,int from){
	int p=head[k],maxn=0,sum=0,tmp,ttmp;
	fa[k]=from;dep[k]=dep[from]+1;
	while(p!=-1){
		tmp=dfs1(edge[p].to,k);
		if(maxn<=tmp){
			maxn=tmp;ttmp=edge[p].to;
		}
		sum+=tmp;
		p=edge[p].next;
	}
	size[k]=sum+1;son[ttmp];
	return size[k];
}
void dfs2(int k,int last){
	int p=head[k];
	top[son[k]]=top[k];
	w[son[k]]=++last;
	dfs2(son[k],last);
	while(p!=-1){
		if(son[k]=edge[p].to) continue;
		else{
			top[edge[p].to]=edge[p].to;w[edge[p].to]=++last;
			dfs2(edge[p].to,last);
		}
	}
}
void add(int pt,int c,int l,int r,int num){
	int mid=(l+r)/2;
	if(pt>r||pt<l) return;
	if(pt==l&&pt==r) a[num]+=c;
	if(l<=pt&&pt<=mid){
		add(pt,c,l,mid,num*2);
		a[num]+=c;
	}
	if(mid+1<=pt&&pt<=r){
		add(pt,c,mid+1,r,num*2+1);
		a[num]+=c;
	}
}
int check(int l,int r,int ql,int qr,int num){
	if(l>=ql&&r<=qr) return a[num];
	int mid=(l+r)/2,re=0;
	if(ql<=mid) re+=check(l,mid,ql,qr,num*2);
	if(qr>mid) re+=check(mid+1,r,ql,qr,num*2+1);
	return re;
}
int query(int op,int ed){
	int re=0;
	while(top[op]!=top[ed]){
		if(dep[top[op]]>=dep[top[ed]]){
			re+=check(1,n-1,w[top[op]],w[op],1);
			op=fa[top[op]];
		}
		else{
			re+=check(1,n-1,w[top[ed]],w[ed],1);
			ed=fa[top[ed]];
		}
	}
	if(ed==op) return re;
	if(dep[ed]<dep[op]) swap(ed,op);
	return re+check(1,n-1,w[op],w[ed],1);
}
int t1[100010],t2[100010],p1[100010];
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&q,&s);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&t1[i],&t2[i],&p1[i]);
		n1++;edge[n1].to=t2[i];edge[n1].next=head[t1[i]];head[t1[i]]=n1;
		n1++;edge[n1].to=t1[i];edge[n1].next=head[t2[i]];head[t2[i]]=n1;
	}
	dfs1(1,1);
	top[1]=1;w[1]=0;dfs2(1,0);
	for(int i=1;i<=n-1;i++){
		if(dep[t1[i]]<dep[t2[i]]) swap(t1[i],t2[i]);
		add(w[t1[i]],p1[i],1,n-1,1);
	}
	int x1,x2,x3;
	for(int i=1;i<=q;i++){
		scanf("%d",&x1);
		if(x1==1){
			cout<<"type 1"<<endl;
			scanf("%d%d",&x2,&x3);
			add(w[t1[x2]],x3,1,n-1,1);
		}
		if(x1==0){
			cout<<"type 2"<<endl;
			scanf("%d",&x2);
			printf("%d\n",query(s,x2));
			s=x2;
		}
	}
}
