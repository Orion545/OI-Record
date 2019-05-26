#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m;
namespace seg2{
	int ch[25000010][2],add[25000010];ll seg[25000010],cnt=0;
	inline void insert(int &cur,int l,int r,int ql,int qr){
		if(!cur) cur=++cnt;
		seg[cur]+=(qr-ql+1);
//		cout<<"	insert "<<l<<' '<<r<<' '<<ql<<' '<<qr<<'\n';
		if(l>=ql&&r<=qr){add[cur]++;return;}
		int mid=(l+r)>>1;
		if(mid>=ql) insert(ch[cur][0],l,mid,ql,min(mid,qr));
		if(mid<qr) insert(ch[cur][1],mid+1,r,max(mid+1,ql),qr);
	}
	inline ll query(int cur,int l,int r,int ql,int qr,ll tmp){
		if(!cur) return tmp*(qr-ql+1);
//		cout<<"	query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<seg[cur]<<' '<<add[cur]<<'\n';
		if(l==ql&&r==qr) return tmp*(qr-ql+1)+seg[cur];
		int mid=(l+r)>>1;ll re=0;
		if(mid>=ql) re+=query(ch[cur][0],l,mid,ql,min(mid,qr),tmp+add[cur]);
		if(mid<qr) re+=query(ch[cur][1],mid+1,r,max(mid+1,ql),qr,tmp+add[cur]);
		return re;
	}
}
namespace seg1{
	int root[400010];
	inline void insert(int l,int r,int num,int pos,int ql,int qr){
		seg2::insert(root[num],1,n,ql,qr);
		if(l==r) return;
		int mid=(l+r)>>1;
		if(mid>=pos) insert(l,mid,num<<1,pos,ql,qr);
		else insert(mid+1,r,num<<1|1,pos,ql,qr);
	}
	inline int query(int l,int r,int num,ll lim,int ql,int qr){
		if(l==r) return l;
		int mid=(l+r)>>1;ll tmp=seg2::query(root[num<<1|1],1,n,ql,qr,0);
//		cout<<"query "<<l<<' '<<r<<' '<<lim<<' '<<tmp<<'\n';
		if(tmp>=lim) return query(mid+1,r,num<<1|1,lim,ql,qr);
		else return query(l,mid,num<<1,lim-tmp,ql,qr);
	}
}
int main(){
	n=read();m=read();int i,t1,t2,t3,t4;
	while(m--){
		t1=read();t2=read();t3=read();t4=read();
		if(t1==1) seg1::insert(1,n*2+1,1,t4+n+1,t2,t3);
		else printf("%d\n",seg1::query(1,n*2+1,1,t4,t2,t3)-n-1);
	}
}
