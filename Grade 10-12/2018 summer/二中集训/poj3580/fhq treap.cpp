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
int n,m,ch[200010][2],siz[200010],key[200010],w[200010],minn[200010],cnt,root;
int rev[200010],lazy[200010];
int newnode(int val){
	int cur=++cnt;ch[cur][0]=ch[cur][1]=0;
	siz[cur]=1;w[cur]=minn[cur]=val;key[cur]=rand();return cur;
}
void update(int pos){
	siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]]+1;
	minn[pos]=w[pos];
	if(ch[pos][0]) minn[pos]=min(minn[pos],minn[ch[pos][0]]);
	if(ch[pos][1]) minn[pos]=min(minn[pos],minn[ch[pos][1]]);
}
void pushrev(int pos){
	if(!pos) return;
	swap(ch[pos][0],ch[pos][1]);
	rev[pos]^=1;
}
void pushlazy(int pos,int val){
	if(!pos) return;
	minn[pos]+=val;w[pos]+=val;
	lazy[pos]+=val;
}
void push(int pos){
	int lc=ch[pos][0],rc=ch[pos][1];
	if(rev[pos]){
		pushrev(lc);
		pushrev(rc);
		rev[pos]=0;
	}
	if(lazy[pos]){
		pushlazy(ch[pos][0],lazy[pos]);
		pushlazy(ch[pos][1],lazy[pos]);
		lazy[pos]=0;
	}
}
void split_rank(int cur,int &l,int &r,int rk){
//	cout<<"	split_rank "<<cur<<' '<<l<<' '<<r<<' '<<val<<' '<<w[cur]<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<'\n';
	push(cur);
	if(!cur){l=r=0;return;}
	if(siz[ch[cur][0]]<rk) l=cur,split_rank(ch[cur][1],ch[l][1],r,rk-siz[ch[cur][0]]-1);
	else r=cur,split_rank(ch[cur][0],l,ch[r][0],rk);
	update(cur);
}
void merge(int &cur,int l,int r){
//	cout<<"	merge "<<cur<<' '<<l<<' '<<r<<'\n';
	push(l);push(r);
	if(!l||!r){cur=l+r;return;}
	if(key[l]<key[r]) cur=l,merge(ch[cur][1],ch[l][1],r);
	else cur=r,merge(ch[cur][0],l,ch[r][0]);
	update(cur);
}
void insert(int pos,int val){
	int x=0,y=0,z=newnode(val);
	split_rank(root,x,y,pos);
	merge(x,x,z);merge(root,x,y);
}
void del(int pos){
	int x=0,y=0,z=0;
	split_rank(root,x,y,pos);
	split_rank(x,x,z,pos-1);
	merge(root,x,y);
}
void add(int l,int r,int val){
	int x=0,y=0,z=0;
	split_rank(root,x,y,r);
	split_rank(x,x,z,l-1);
	pushlazy(z,val);
	merge(x,x,z);merge(root,x,y);
}
void reverse(int l,int r){
	int x=0,y=0,z=0;
	split_rank(root,x,y,r);
	split_rank(x,x,z,l-1);
	pushrev(z);
	merge(x,x,z);merge(root,x,y);
}
void revolve(int l,int r,int t){
	int x=0,y=0,lp=0,rp=0;
	split_rank(root,x,y,r);
	split_rank(x,x,lp,l-1);
	split_rank(lp,lp,rp,(r-l+1)-t);
	merge(rp,rp,lp);
	merge(x,x,rp);merge(root,x,y);
}
int getmin(int l,int r){
	int x=0,y=0,z=0,re;
	split_rank(root,x,y,r);
	split_rank(x,x,z,l-1);
	re=minn[z];
	merge(x,x,z);merge(root,x,y);
	return re;
}
int main(){
	n=read();int i,t1,t2,t3;char s[10];
	for(i=1;i<=n;i++) t1=read(),insert(i-1,t1);
	m=read();
	for(i=1;i<=m;i++){
		scanf("%s",s);
		if(s[0]=='A'){
			t1=read();t2=read();t3=read();
			add(t1,t2,t3);
		}
		if(s[0]=='I'){
			t1=read();t2=read();
			insert(t1,t2);
		}
		if(s[0]=='D'){
			t1=read();
			del(t1);
		}
		if(s[0]=='R'&&s[3]=='E'){
			t1=read();t2=read();
			reverse(t1,t2);
		}
		if(s[0]=='R'&&s[3]=='O'){
			t1=read();t2=read();t3=read();
			t3%=(t2-t1+1);t3+=(t2-t1+1);t3%=(t2-t1+1);
			if(t3) revolve(t1,t2,t3);
		}
		if(s[0]=='M'){
			t1=read();t2=read();
			printf("%d\n",getmin(t1,t2));
		}
	}
}
