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
int n,m,T,op,num[1000010];ll all[1000010];
namespace seg{
	ll seg[5000010];int ans[5000010],tot;
	void build(){
		int i;
		for(tot=1;tot<=n+1;tot<<=1);
		for(i=1;i<=n;i++){
			seg[i+tot]=all[i];
			ans[i+tot]=0;
		}
		for(i=tot-1;i>=1;i--){
			seg[i]=max(seg[i<<1],seg[i<<1|1]);
			ans[i]=max(ans[i<<1],ans[i<<1|1]);
		}
	}
	inline ll query(int ql,int qr){
		ll re=0;int l,r;
		for(l=tot+ql-1,r=tot+qr+1;l^r^1;l>>=1,r>>=1){
			if(!(l&1)) re=max(re,seg[l^1]);
			if(r&1) re=max(re,seg[r^1]);
		}
		return re;
	}
	inline void change1(int pos,int val){
		num[pos]=val;
		all[pos]=((ll)val<<25ll)+(ll)pos;
		seg[tot+pos]=all[pos];
		for((pos+=tot)>>=1;pos>=1;pos>>=1) seg[pos]=max(seg[pos<<1],seg[pos<<1|1]);
	}
	inline void change2(int pos,int val){
		ans[tot+pos]=val;
		for((pos+=tot)>>=1;pos>=1;pos>>=1) ans[pos]=max(ans[pos<<1],ans[pos<<1|1]);
	}
	inline int getans(){
		return ans[1];
	}
}
inline void change(int pos){
	int l=max(1,pos-m),r=min(n,pos+m);
	if(seg::query(l,r)==all[pos]){
		int cur=0;
		if(pos>l) cur=max(cur,(int)(seg::query(l,pos-1)>>25ll));
		if(pos<r) cur=max(cur,(int)(seg::query(pos+1,r)>>25ll));
		seg::change2(pos,cur+num[pos]);
	}
	else seg::change2(pos,0);
}
inline void ask(int pos,int val){
	seg::change1(pos,val);
	change(pos);
	int l=max(1,pos-m),r=min(n,pos+m);
	if(l<pos) change(seg::query(l,pos-1)&((1<<25)-1));
	if(r>pos) change(seg::query(pos+1,r)&((1<<25)-1));
}
int main(){
	n=read();m=read();T=read();op=read();int i,t1,t2,last=0;
	for(i=1;i<=n;i++){
		num[i]=read();
		all[i]=((ll)num[i]<<25ll)+i;
	}
	seg::build();
	for(i=1;i<=n;i++) change(i);
	printf("%d\n",last=seg::getans());
	while(T--){
		t1=read();t2=read();
		t1^=(last*op);
		t2^=(last*op);
		ask(t1,t2);
		printf("%d\n",last=seg::getans());
	}
}
