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
ll fa[3000010],ch[3000010][2],root[500010];ll liml[3000010],limr[3000010],siz[3000010],cnt=0;
void update(ll cur){
	siz[cur]=siz[ch[cur][0]]+siz[ch[cur][1]]+limr[cur]-liml[cur]+1;
}
ll newnode(ll f,ll l,ll r){
	ll cur=++cnt;
//	cout<<"		newnode "<<f<<' '<<l<<' '<<r<<' '<<cur<<'\n';
	fa[cur]=f;liml[cur]=l;limr[cur]=r;siz[cur]=limr[cur]-liml[cur]+1;ch[cur][0]=ch[cur][1]=0;
	return cur;
}
ll get(ll cur){return ch[fa[cur]][1]==cur;}
void rotate(ll x){
	ll f=fa[x],ff=fa[f],son=get(x);
//	cout<<"		rotate "<<x<<' '<<f<<' '<<ff<<' '<<son<<'\n';
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(ff) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(ll num,ll x,ll to){
	for(ll f;(f=fa[x])!=to;rotate(x)){
		if(fa[f]!=to)
			rotate((get(f)==get(x))?f:x);
	}
	if(!to) root[num]=x;
}
ll rk,used;
ll getpos(ll cur){
//	cout<<"	getpos "<<cur<<' '<<siz[ch[cur][0]]<<' '<<siz[cur]<<' '<<rk<<' '<<used<<'\n';
	assert(rk>0);assert(cur);
	if(siz[ch[cur][0]]<rk&&(siz[cur]-siz[ch[cur][1]])>=rk){
		rk-=siz[ch[cur][0]];
		used+=siz[ch[cur][0]];
		return cur;
	}
	if(siz[ch[cur][0]]>=rk) return getpos(ch[cur][0]);
	else{
		rk-=(siz[cur]-siz[ch[cur][1]]);
		used+=(siz[cur]-siz[ch[cur][1]]);
		return getpos(ch[cur][1]);
	}
}
ll cut(ll num,ll val){
//	cout<<"cut "<<num<<' '<<val<<'\n';
	rk=val;used=0;
	ll pos=getpos(root[num]),inrk=rk;
	ll sizl=used,sizr=used+limr[pos]-liml[pos]+2;
	rk=sizl;used=0;
	ll x=getpos(root[num]);
	rk=sizr;used=0;
	ll y=getpos(root[num]);
//	cout<<"cut mid "<<pos<<' '<<x<<' '<<y<<' '<<inrk<<'\n';
	splay(num,x,0);splay(num,y,x);
	assert(ch[y][0]==pos);assert(ch[pos][0]==0);assert(ch[pos][1]==0);
	ll nl=0,nr=0;
	if(inrk>1) nl=newnode(0,liml[pos],liml[pos]+inrk-2);
	if(inrk<(limr[pos]-liml[pos]+1)) nr=newnode(0,liml[pos]+inrk,limr[pos]);
	if((!nl)&&(!nr)){ch[y][0]=0;}
	else if((!nl)||(!nr)){ch[y][0]=(nl+nr);fa[nl+nr]=y;}
	else{
		ch[y][0]=nl;fa[nl]=y;
		ch[nl][1]=nr;fa[nr]=nl;
		update(nl);
	}
	update(y);update(x);
	return inrk+liml[pos]-1;
}
void insert(ll num,ll vall,ll valr){
//	cout<<"insert "<<num<<' '<<vall<<' '<<valr<<'\n';
	ll u=root[num];
	while(ch[u][1]) u=ch[u][1];
	if(ch[u][0]){
		u=ch[u][0];
		while(ch[u][1]) u=ch[u][1];
		ch[u][1]=newnode(u,vall,valr);
		splay(num,ch[u][1],0);
	}
	else{
		ch[u][0]=newnode(u,vall,valr);
		splay(num,ch[u][0],0);
	}
}
ll n,m,q;ll x[300010];
void build(ll &cur,ll l,ll r,ll f){
	if(l>r){cur=0;return;}
	cur=++cnt;ll mid=(l+r)>>1;
//	cout<<"build "<<cur<<' '<<l<<' '<<r<<' '<<f<<' '<<x[mid]<<'\n';
	liml[cur]=limr[cur]=x[mid];fa[cur]=f;siz[cur]=1;ch[cur][0]=ch[cur][1]=0;
	build(ch[cur][0],l,mid-1,cur);
	build(ch[cur][1],mid+1,r,cur);
	update(cur);
}
int main(){
	n=read();m=read();q=read();ll i,t1,t2,ans;
	for(i=1;i<=n;i++) root[i]=newnode(0,n*m+1,n*m+1);
	for(i=1;i<=n;i++){
		insert(i,0,0);
		insert(i,m*(i-1)+1,m*i-1);
		x[i]=m*i;
	}
	x[0]=0;x[n+1]=n*m+1;
	build(root[n+1],0,n+1,0);
	while(q--){
		t1=read();t2=read();
//		cout<<"********begin query "<<t1<<' '<<t2<<'\n';
		if(t2==m){
//			cout<<"enter sp\n";
			ans=cut(n+1,t1+1);
//			cout<<"getans "<<ans<<'\n';
			printf("%lld\n",ans);
			insert(n+1,ans,ans);
		}
		else{
//			cout<<"enter normal\n";
			ans=cut(t1,t2+1);
//			cout<<"getans "<<ans<<'\n';
			printf("%lld\n",ans);
			insert(n+1,ans,ans);
			ans=cut(n+1,t1+1);
//			cout<<"cutdown "<<ans<<'\n';
			insert(t1,ans,ans);
		}
	}
}
