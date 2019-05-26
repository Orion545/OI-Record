#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<set>
#define id(i,j) (i-1)*m+j
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
int n,m,q,r[1000010],c[1000010],num[1000010],gl[1000010],gr[1000010],ori[1000010];
set<int>st;
//gl[i]: the ith PERSON's contribution LEFT BOUND PERSON to the WHITE law
//gr[i]: gl[i]'s black counterpart
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
namespace seg{
	//segtree hosts the minimum value in a certain range, as well as the number this minval occurs in the same range
	int minn[4000010],mincnt[4000010],lazy[4000010];
	inline void push(int l,int r,int num){
		if(l==r||!lazy[num]) return;
		lazy[num<<1]+=lazy[num];
		minn[num<<1]+=lazy[num];
		lazy[num<<1|1]+=lazy[num];
		minn[num<<1|1]+=lazy[num];
		lazy[num]=0;
	}
	inline void update(int num){
		if(minn[num<<1]!=minn[num<<1|1]){
			if(minn[num<<1]<minn[num<<1|1]) minn[num]=minn[num<<1],mincnt[num]=mincnt[num<<1];
			else minn[num]=minn[num<<1|1],mincnt[num]=mincnt[num<<1|1];
		}
		else minn[num]=minn[num<<1],mincnt[num]=mincnt[num<<1]+mincnt[num<<1|1];
//		cout<<"		update "<<num<<' '<<minn[num]<<' '<<mincnt[num]<<'\n';
	}	
	void build(int l,int r,int num){
//		cout<<"build "<<l<<' '<<r<<' '<<num<<'\n';
		if(l==r){minn[num]=ori[l];mincnt[num]=1;return;}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		update(num);
	}
	void change(int l,int r,int ql,int qr,int num,int val){
		if(ql>qr) return;
//		cout<<"	change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<val<<'\n';
		push(l,r,num);
		if(l>=ql&&r<=qr){minn[num]+=val;lazy[num]+=val;return;}
		int mid=(l+r)>>1;
		if(mid>=ql) change(l,mid,ql,qr,num<<1,val);
		if(mid<qr) change(mid+1,r,ql,qr,num<<1|1,val);
		update(num);
	}
}
inline int getwhite(int i,int j){
	int maxn=n*m+1,secmax=n*m+1,k,t1,t2,cur;
	for(k=0;k<4;k++){
		t1=i+dx[k];t2=j+dy[k];
		if(t1<1||t1>n||t2<1||t2>m) continue;
		cur=id(t1,t2);
		if(num[cur]<maxn) secmax=maxn,maxn=num[cur];
		else if(num[cur]<secmax) secmax=num[cur];
	}
	return secmax;
}
inline int getblack(int i,int j){
	int maxn=n*m+1,t1,t2,cur,k;
	for(k=0;k<2;k++){
		t1=i+dx[k];t2=j+dy[k];
		if(t1<1||t1>n||t2<1||t2>m) continue;
		cur=id(t1,t2);
		maxn=min(maxn,num[cur]);
	}
	return maxn;
}

void check(int i,int j,int liml,int limr){
	//goes an update for the person at POSITION(i,j)
	int tmp=id(i,j);
//	cout<<"recheck "<<i<<' '<<j<<' '<<num[tmp]<<' '<<gl[num[tmp]]<<' '<<gr[num[tmp]]<<'\n';

	if(gl[num[tmp]]<num[tmp]) seg::change(1,n*m,max(liml,gl[num[tmp]]),min(num[tmp],limr)-1,1,-1);
	gl[num[tmp]]=getwhite(i,j);
	if(gl[num[tmp]]<num[tmp]) seg::change(1,n*m,max(liml,gl[num[tmp]]),min(num[tmp],limr)-1,1,1);

	if(num[tmp]<gr[num[tmp]]) seg::change(1,n*m,max(num[tmp],liml),min(gr[num[tmp]],limr)-1,1,-1);
	gr[num[tmp]]=getblack(i,j);
	if(num[tmp]<gr[num[tmp]]) seg::change(1,n*m,max(num[tmp],liml),min(gr[num[tmp]],limr)-1,1,1);
//	cout<<"finish recheck "<<i<<' '<<j<<' '<<num[tmp]<<' '<<gl[num[tmp]]<<' '<<gr[num[tmp]]<<'\n';
}
int main(){
	n=read();m=read();q=read();
	int i,j,k,t1,t2,cur,tmp,maxn,secmax,tl,tr;
	//MIND:I made a huge mistake here, all the maxn/secmax in this program must be rechanged to minn/secmin, but i'm too lazy to do it, so i'll left this note.
	for(i=1;i<=n*m;i++){
		t1=read();t2=read();
		t1++;t2++;
		r[i]=t1;c[i]=t2;
		num[id(t1,t2)]=i;
	}
	for(tmp=1;tmp<=n*m;tmp++){
		i=r[tmp];j=c[tmp];ori[tmp]=ori[tmp-1];
		gl[tmp]=getwhite(i,j);if(gl[tmp]<tmp) ori[tmp]--;
		gr[tmp]=getblack(i,j);if(gr[tmp]>tmp) ori[tmp]++;
		for(k=0;k<4;k++){
			t1=i+dx[k];t2=j+dy[k];
			if(t1<1||t1>n||t2<1||t2>m) continue;
			cur=num[id(t1,t2)];
			if(cur<tmp&&getblack(t1,t2)==tmp) ori[tmp]--;
			if(cur>tmp&&getwhite(t1,t2)==tmp) ori[tmp]++;
		}
//		cout<<"begin "<<i<<' '<<j<<' '<<tmp<<' '<<gl[tmp]<<' '<<gr[tmp]<<'\n';
	}
//	for(i=1;i<=n*m;i++) cout<<i<<' '<<ori[i]<<'\n';
	seg::build(1,n*m,1);
	assert(seg::minn[1]!=0);
	while(q--){
		tl=read();tr=read();tl++;tr++;
		if(tl>tr) swap(tl,tr);
		//swap PERSON tl and tr
//		cout<<"*************swap person "<<tl<<' '<<tr<<' '<<r[tl]<<' '<<c[tl]<<' '<<r[tr]<<' '<<c[tr]<<'\n';
		st.clear();
		st.insert(tl);st.insert(tr);
		i=r[tl];j=c[tl];
		for(k=0;k<4;k++){
			t1=i+dx[k];t2=j+dy[k];
			if(t1<1||t1>n||t2<1||t2>m) continue;
			st.insert(num[id(t1,t2)]);
		}
		i=r[tr];j=c[tr];
		for(k=0;k<4;k++){
			t1=i+dx[k];t2=j+dy[k];
			if(t1<1||t1>n||t2<1||t2>m) continue;
			st.insert(num[id(t1,t2)]);
		}
		swap(r[tl],r[tr]);
		swap(c[tl],c[tr]);
		swap(num[id(r[tl],c[tl])],num[id(r[tr],c[tr])]);
		for(set<int>::iterator it=st.begin();it!=st.end();it++) check(r[*it],c[*it],tl,tr);
		assert(seg::minn[1]!=0);
		if(seg::minn[1]!=1) puts("0");
		else printf("%d\n",seg::mincnt[1]);
	}
}
