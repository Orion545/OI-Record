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
bool vis[100010];
int a[400010];//segment tree
int dfs1(int k,int from){
//	cout<<"in pt "<<k<<" from pt "<<from<<endl;
	int p=head[k],maxn=0,sum=0,tmp=0,ttmp=0;
	fa[k]=from;dep[k]=dep[from]+1;vis[k]=1;
	while(p!=-1){
		if(vis[edge[p].to]) goto skip1;
		tmp=dfs1(edge[p].to,k);
		if(maxn<=tmp){
			maxn=tmp;ttmp=edge[p].to;
		}
		sum+=tmp;
		skip1:p=edge[p].next;
	}
	size[k]=sum+1;son[k]=ttmp;
	return size[k];
}
void dfs2(int k,int last,int ffa){
//	cout<<"in pt "<<k<<endl;
	vis[k]=1;
	top[k]=ffa;
	w[k]=++last;
	if(son[k]) dfs2(son[k],last,ffa);
	else return;
	int p=head[k];
	while(p!=-1){
		if(vis[edge[p].to]==1) goto skip2;
		if(son[k]==edge[p].to) goto skip2;
		else{
			top[edge[p].to]=edge[p].to;w[edge[p].to]=++last;
			dfs2(edge[p].to,last,edge[p].to);
		}
		skip2:p=edge[p].next;
	}
}
void add(int pt,int c,int l,int r,int num){
	int mid=(l+r)/2;
	if(pt>r||pt<l) return;
	if(pt==l&&pt==r){
		a[num]=c;return;
	}
	if(l<=pt&&pt<=mid){
		add(pt,c,l,mid,num*2);
		a[num]=a[num*2]+a[num*2+1];return;
	}
	if(mid+1<=pt&&pt<=r){
		add(pt,c,mid+1,r,num*2+1);
		a[num]=a[num*2]+a[num*2+1];
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
			re+=check(1,n,w[top[op]],w[op],1);
			op=fa[top[op]];
		}
		else{
			re+=check(1,n,w[top[ed]],w[ed],1);
			ed=fa[top[ed]];
		}
	}
	if(ed==op) return re;
	if(dep[ed]<dep[op]) swap(ed,op);
	return re+check(1,n,w[son[op]],w[ed],1);
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
	dfs1(1,0);//cout<<"finish dfs 1"<<endl;
	memset(vis,0,sizeof(vis));
	top[1]=1;w[1]=1;dfs2(1,0,1);//cout<<"finish dfs 2"<<endl; 
//	for(int i=1;i<=n;i++) cout<<top[i]<<ends<<w[i]<<endl;cout<<endl;
	for(int i=1;i<=n-1;i++){
		if(dep[t1[i]]<dep[t2[i]]) swap(t1[i],t2[i]);
//		cout<<"swap in "<<i<<ends<<t1[i]<<ends<<t2[i]<<endl;
		add(w[t1[i]],p1[i],1,n,1);
	}
	//cout<<"finish edge swap"<<endl;
	for(int i=1;i<=10;i++) cout<<a[i]<<ends; cout<<endl;
	int x1,x2,x3;
	for(int i=1;i<=q;i++){
		scanf("%d",&x1);
		if(x1==1){
//			cout<<"type 1"<<endl;
			scanf("%d%d",&x2,&x3);
			add(w[t1[x2]],x3,1,n,1);
			for(int i=1;i<=10;i++) cout<<a[i]<<ends; cout<<endl;
		}
		if(x1==0){
//			cout<<"type 2"<<endl;
			scanf("%d",&x2);
			printf("%d\n",query(s,x2));
			s=x2;
		}
	}
}
