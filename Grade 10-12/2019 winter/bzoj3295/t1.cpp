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
int n,m,dellis[100010],a[100010],pos[100010],del[100010];
namespace BIT{
	int a[100010];
	inline void add(int x){
		for(;x<=n;x+=(x&(-x))) a[x]++;
	}
	inline int sum(int x){
		int re=0;
		for(;x;x^=(x&(-x))) re+=a[x];
		return re;
	}
}
namespace seg2{
	int seg[11000010],ch[11000010][2],cnt;
	inline void insert(int &cur,int l,int r,int pos){
		if(!cur) cur=++cnt;
		seg[cur]++;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(mid>=pos) insert(ch[cur][0],l,mid,pos);
		else insert(ch[cur][1],mid+1,r,pos);
	}
	inline int query(int cur,int l,int r,int ql,int qr){
		if(!cur) return 0;
		if(l>=ql&&r<=qr) return seg[cur];
		int mid=(l+r)>>1,re=0;
		if(mid>=ql) re+=query(ch[cur][0],l,mid,ql,qr);
		if(mid<qr) re+=query(ch[cur][1],mid+1,r,ql,qr);
		return re;
	}
}
namespace seg1{
	int root[400010];
	inline void insert(int l,int r,int num,int val,int pos){
		seg2::insert(root[num],1,n,pos);
		if(l==r) return;
		int mid=(l+r)>>1;
		if(mid>=val) insert(l,mid,num<<1,val,pos);
		else insert(mid+1,r,num<<1|1,val,pos);
	}
	inline int query(int l,int r,int num,int ql,int qr,int qll,int qrr){
		if(ql>qr||qll>qrr) return 0;
		if(l>=ql&&r<=qr) return seg2::query(root[num],1,n,qll,qrr);
		int mid=(l+r)>>1,re=0;
		if(mid>=ql) re+=query(l,mid,num<<1,ql,qr,qll,qrr);
		if(mid<qr) re+=query(mid+1,r,num<<1|1,ql,qr,qll,qrr);
		return re;
	}
}
ll out[100010];
int main(){
	n=read();m=read();int i;ll ans=0;
	for(i=1;i<=n;i++){
		a[i]=read();
		pos[a[i]]=i;
	}
	for(i=1;i<=m;i++){
		dellis[i]=read();
		del[dellis[i]]=1;
	}
	for(i=1;i<=n;i++){
		if(del[i]) continue;
		ans+=BIT::sum(n)-BIT::sum(pos[i]);
		BIT::add(pos[i]);
		seg1::insert(1,n,1,i,pos[i]);
	}
	for(i=m;i>=1;i--){
		ans+=(ll)(seg1::query(1,n,1,1,dellis[i]-1,pos[dellis[i]]+1,n)+seg1::query(1,n,1,dellis[i]+1,n,1,pos[dellis[i]]-1));
		out[i]=ans;
		seg1::insert(1,n,1,dellis[i],pos[dellis[i]]);
	}
	for(i=1;i<=m;i++) printf("%lld\n",out[i]);
}
