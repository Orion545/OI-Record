#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define next DEEP_DARK_FANTASY
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
int n,m,k,posl[300010],posr[300010],val[300010],ans[300010],next[300010],head[300010];
namespace BIT{
	ll a[300010];
	void add(int x,ll val){
		if(!x) return; 
//		cout<<"add "<<x<<' '<<val<<'\n';
		for(;x<=n;x+=(x&(-x))) a[x]+=val;
	}
	ll sum(int x){
		ll re=0;
		for(;x;x^=(x&(-x))) re+=a[x];
		return re;
	}
};
struct query{
	int id,head;ll lim;
}q[300010],tmp[2][300010];
void solve(int l,int r,int ql,int qr){
//	cout<<"*************solve "<<l<<' '<<r<<' '<<ql<<' '<<qr<<'\n';
	if(ql>qr) return;
	int i,cntl=0,cntr=0,pos,mid=(l+r)>>1;ll cur;
	if(l==r){
		for(i=ql;i<=qr;i++){
//			cout<<"-----give ans "<<i<<' '<<q[i].id<<' '<<l<<'\n';
			ans[q[i].id]=l;
		}
		return;
	}
	for(i=l;i<=mid;i++){
		if(posl[i]<=posr[i]){
			BIT::add(posl[i],val[i]);
			BIT::add(posr[i]+1,-val[i]);
		}
		else{
			BIT::add(posl[i],val[i]);
			BIT::add(posr[i]+1,-val[i]);
			BIT::add(1,val[i]);
		}
	}
	for(i=ql;i<=qr;i++){
		cur=0;
		for(pos=q[i].head;pos;pos=next[pos]){
			cur+=BIT::sum(pos);
			if(cur>=q[i].lim) break;
		}
//		cout<<"check solve "<<l<<' '<<mid<<' '<<' '<<q[i].id<<' '<<cur<<' '<<q[i].lim<<'\n';
		if(cur>=q[i].lim) tmp[0][++cntl]=q[i];
		else q[i].lim-=cur,tmp[1][++cntr]=q[i];
	}
	for(i=l;i<=mid;i++){
		if(posl[i]<=posr[i]){
			BIT::add(posl[i],-val[i]);
			BIT::add(posr[i]+1,val[i]);
		}
		else{
			BIT::add(posl[i],-val[i]);
			BIT::add(posr[i]+1,+val[i]);
			BIT::add(1,-val[i]);
		}
	}
	for(i=ql;i<=ql+cntl-1;i++) q[i]=tmp[0][i-ql+1];
	for(i=ql+cntl;i<=qr;i++) q[i]=tmp[1][i-ql-cntl+1];
//	cout<<"finish doing solve "<<l<<' '<<r<<' '<<ql<<' '<<qr<<":\n";
//	for(i=ql;i<=qr;i++) cout<<q[i].id<<'\n';
	solve(l,mid,ql,ql+cntl-1);
	solve(mid+1,r,ql+cntl,qr);
}
int main(){
	m=read();n=read();int i,tmp;
	for(i=1;i<=n;i++){
		tmp=read();
		next[i]=head[tmp];
		head[tmp]=i;
	}
	for(i=1;i<=m;i++){
		q[i].lim=read();
		q[i].id=i;
		q[i].head=head[i];
	}
	k=read();
	for(i=1;i<=k;i++){
		posl[i]=read();
		posr[i]=read();
		val[i]=read();
	}
	solve(1,k+1,1,m);
	for(i=1;i<=m;i++){
		if(ans[i]==k+1) puts("NIE");
		else printf("%d\n",ans[i]);
	}
}
