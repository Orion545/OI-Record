#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<ctime>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,ch[10000010][2],siz[10000010],key[10000010],w[10000010],sum[10000010],cnt,root[200010],rt;
int rev[10000010],tot=0;
int newnode(int val){
	int cur=++cnt;ch[cur][0]=ch[cur][1]=0;
	siz[cur]=1;w[cur]=sum[cur]=val;key[cur]=rand();return cur;
}
int copy(int b){
	int a=newnode(0);
	ch[a][0]=ch[b][0];ch[a][1]=ch[b][1];siz[a]=siz[b];
	w[a]=w[b];sum[a]=sum[b];key[a]=key[b];rev[a]=rev[b];
	return a;
}
void update(int pos){
	if(!pos) return;
	assert(siz[0]==0&&w[0]==0&&sum[0]==0);
	siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]]+1;
	sum[pos]=w[pos]+sum[ch[pos][0]]+sum[ch[pos][1]];
}
void pushrev(int pos){
	if(!pos) return;
	swap(ch[pos][0],ch[pos][1]);
	rev[pos]^=1;
}
void push(int pos){
	if(rev[pos]){
		if(ch[pos][0]) ch[pos][0]=copy(ch[pos][0]),pushrev(ch[pos][0]);
		if(ch[pos][1]) ch[pos][1]=copy(ch[pos][1]),pushrev(ch[pos][1]);
		rev[pos]=0;
	}
}
void split_rank(int cur,int &l,int &r,int rk){
//	cout<<"		split_rank "<<cur<<' '<<l<<' '<<r<<' '<<rk<<' '<<w[cur]<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<'\n';
	if(!cur){l=r=0;return;}
	int now;now=copy(cur);push(now);
	if(siz[ch[cur][0]]<rk) l=copy(now),split_rank(ch[now][1],ch[l][1],r,rk-siz[ch[now][0]]-1);
	else r=copy(now),split_rank(ch[now][0],l,ch[r][0],rk);
	update(l);update(r);
}
void merge(int &cur,int l,int r){
//	cout<<"		merge "<<cur<<' '<<l<<' '<<r<<' '<<w[l]<<' '<<w[r]<<'\n';
	if(!l||!r){cur=l+r;return;}
	if(key[l]<key[r]) push(l),cur=copy(l),merge(ch[cur][1],ch[l][1],r);
	else push(r),cur=copy(r),merge(ch[cur][0],l,ch[r][0]);
	update(cur);
}
void insert(int pos,int val){
//	cout<<"insert "<<pos<<' '<<val<<'\n';
	int x=0,y=0,z=newnode(val);
	split_rank(root[rt],x,y,pos);
	merge(x,x,z);merge(root[rt],x,y);
}
void dfs(int u){
	if(ch[u][0]) dfs(ch[u][0]);
	cout<<"	dfs "<<u<<' '<<w[u]<<' '<<sum[u]<<'\n';
	if(ch[u][1]) dfs(ch[u][1]);
}
void reverse(int l,int r){
//	cout<<"reverse "<<l<<' '<<r<<' '<<rt<<'\n';
	int x=0,y=0,z=0;
	split_rank(root[rt],x,y,r);
	split_rank(x,x,z,l-1);
//	dfs(z);
	pushrev(z);rt=++tot;
	merge(x,x,z);merge(root[rt],x,y);
}
int getsum(int l,int r){
//	cout<<"getsum "<<l<<' '<<r<<'\n';
	int x=0,y=0,z=0,re;
	split_rank(root[rt],x,y,r);
	split_rank(x,x,z,l-1);
	re=sum[z];
	merge(x,x,z);merge(root[rt],x,y);
	return re;
}
int main(){
	srand(time(NULL));
	n=read();int i,t1,t2,t3;
	m=read();
	for(i=1;i<=n;i++) t1=read(),insert(i-1,t1);
	for(i=1;i<=m;i++){
		t1=read();
		if(t1==1){
			t2=read();t3=read();
			reverse(t2,t3);
		}
		if(t1==2){
			t2=read();t3=read();
			printf("%d\n",getsum(t2,t3));
		}
		if(t1==3) rt=read();
	}
}
/*
5
12
1 2 3 4 5
2 2 4
2 1 5
1 2 4
2 1 3
2 3 5
1 1 5
2 1 5
2 1 3
2 3 5
3 1
2 1 3
2 3 5

*/
