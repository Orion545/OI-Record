#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
inline int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int n,m,root;
namespace t{
	int ch[200010][2],w[200010],siz[200010],key[200010],rev[200010],cnt=0;
	inline void pushrev(int cur){
		if(!cur) return;
		swap(ch[cur][0],ch[cur][1]);
		rev[cur]^=1;
	}
	inline void push(int cur){
		if(!rev[cur]) return;
		pushrev(ch[cur][0]);
		pushrev(ch[cur][1]);
		rev[cur]=0;
	}
	inline int newnode(int val){
		int cur=++cnt;
		ch[cur][0]=ch[cur][1]=0;
		w[cur]=val;siz[cur]=1;key[cur]=random(1,1e9);
//		cout<<"newnode "<<val<<' '<<key[cur]<<'\n';
		return cur;
	}
	void split(int &curl,int &curr,int cur,int lim){
		if(!cur){curl=curr=0;return;}
		push(cur);
//		cout<<"split "<<cur<<' '<<siz[cur]<<' '<<ch[cur][0]<<' '<<siz[ch[cur][0]]<<' '<<lim<<'\n';
		if(siz[ch[cur][0]]+1>lim) curr=cur,split(curl,ch[curr][0],ch[cur][0],lim);
		else curl=cur,split(ch[curl][1],curr,ch[cur][1],lim-siz[ch[cur][0]]-1);
		if(curl) siz[curl]=siz[ch[curl][0]]+siz[ch[curl][1]]+1;
		if(curr) siz[curr]=siz[ch[curr][0]]+siz[ch[curr][1]]+1;
//		cout<<"finish split "<<curl<<' '<<ch[curl][0]<<' '<<ch[curl][1]<<' '<<curr<<' '<<ch[curr][0]<<' '<<ch[curr][1]<<'\n';
	}
	void merge(int &cur,int curl,int curr){
		if(!curl||!curr){cur=curl^curr;return;}
		push(curl);push(curr);
//		cout<<"merge "<<curl<<' '<<curr<<' '<<key[curl]<<' '<<key[curr]<<' '<<siz[curl]<<' '<<siz[curr]<<'\n';
		if(key[curl]<key[curr]) cur=curl,merge(ch[cur][1],ch[curl][1],curr);
		else cur=curr,merge(ch[cur][0],curl,ch[curr][0]);
		if(cur) siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+1;
//		cout<<"finish merge "<<cur<<' '<<ch[cur][0]<<' '<<ch[cur][1]<<' '<<siz[cur]<<'\n';
	}
	void reverse(int l,int r){
		//split to [1,l)+[l,r]+(r,n], mark[l,r]
//		cout<<"**********************reverse "<<l<<' '<<r<<'\n';
		int le,mid,ri;
		split(mid,ri,root,r);
		split(le,mid,mid,l-1);
		pushrev(mid);
		merge(le,le,mid);
		merge(root,le,ri);
	}
	void dfs(int cur){
		if(!cur) return;
		push(cur);
		dfs(ch[cur][0]);
		printf("%d ",w[cur]);
		dfs(ch[cur][1]);
	}
}
int main(){
	n=read();m=read();int i,t1,t2;root=0;
	for(i=1;i<=n;i++) t::merge(root,root,t::newnode(i));
	while(m--){
		t1=read();t2=read();
		t::reverse(t1,t2);
	}
	t::dfs(root);
	puts("");
}
