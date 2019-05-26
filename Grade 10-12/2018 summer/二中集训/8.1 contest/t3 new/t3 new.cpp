#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll unsigned long long
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
const ll LIM=0-1;
int n,Q,K,first[200010],dep[200010],son[200010],siz[200010],top[200010],pos[200010],back[200010];
int op[200010],cnte,cntn,fa[200010];ll val[200010];
struct data{
	ll f0,f1,inv0,inv1;
	data(){f0=f1=inv0=inv1=0;}
}a[800010];
struct edge{
	int to,next;
}e[200010];
inline void add(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs1(int u,int f){
	int i,v;dep[u]=dep[f]+1;siz[u]=1;son[u]=0;fa[u]=f;
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs1(v,u);siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int t){
	int i,v;top[u]=t;pos[u]=++cntn;back[cntn]=u;
//	cout<<"dfs2 "<<u<<' '<<top[u]<<' '<<son[u]<<' '<<pos[u]<<'\n';
	if(son[u]) dfs2(son[u],t);
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(pos[v]) continue;
		dfs2(v,v);
	}
}
ll calc(ll num,int x){
	if(op[x]==1) return num&val[x];
	if(op[x]==2) return num|val[x];
	if(op[x]==3) return num^val[x];
}
data update(data l,data r){
	data re;
	re.f0=((l.f0&r.f1)|((~l.f0)&r.f0));
	re.f1=((l.f1&r.f1)|((~l.f1)&r.f0));
	re.inv0=((r.inv0&l.inv1)|((~r.inv0)&l.inv0));
	re.inv1=((r.inv1&l.inv1)|((~r.inv1)&l.inv0));
	return re;
}
void build(int l,int r,int num){
//	cout<<"build "<<l<<' '<<r<<' '<<num<<'\n'; 
	if(l==r){
		a[num].f0=a[num].inv0=calc(0,back[l]);
		a[num].f1=a[num].inv1=calc(LIM,back[l]);
//		cout<<"	reach end "<<back[l]<<' '<<a[num].f0<<' '<<a[num].f1<<'\n';
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,num<<1);build(mid+1,r,(num<<1)+1);
	a[num]=update(a[num<<1],a[(num<<1)+1]);
}
void change(int l,int r,int num,int pos){
	if(l==r){
		a[num].f0=a[num].inv0=calc(0,back[l]);
		a[num].f1=a[num].inv1=calc(LIM,back[l]);
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=pos) change(l,mid,num<<1,pos);
	else change(mid+1,r,(num<<1)+1,pos);
	a[num]=update(a[num<<1],a[(num<<1)+1]);
}
data query(int l,int r,int ql,int qr,int num){
	if(l==ql&&r==qr) return a[num];
	int mid=(l+r)>>1;data re;
	if(mid>=qr) re=query(l,mid,ql,qr,num<<1);
	else{
		if(mid<ql) re=query(mid+1,r,ql,qr,(num<<1)+1);
		else re=update(query(l,mid,ql,mid,num<<1),query(mid+1,r,mid+1,qr,(num<<1)+1));
	}
	return re;
}
data ans1[100010],ans2[100010];int cnt1,cnt2;
data solve(int x,int y){
	cnt1=cnt2=0;
	while(top[x]!=top[y]){
//		cout<<"solve "<<x<<' '<<y<<' '<<top[x]<<' '<<top[y]<<'\n';
		if(dep[top[x]]>=dep[top[y]]){
			ans1[++cnt1]=query(1,n,pos[top[x]],pos[x],1);
			x=fa[top[x]];
		}
		else{
			ans2[++cnt2]=query(1,n,pos[top[y]],pos[y],1);
			y=fa[top[y]];
		}
	}
	if(dep[x]>dep[y]) ans1[++cnt1]=query(1,n,pos[y],pos[x],1);
	else ans2[++cnt2]=query(1,n,pos[x],pos[y],1);
	data re;int i;
//	cout<<"finish query "<<cnt1<<' '<<cnt2<<'\n';
	for(i=1;i<=cnt1;i++) swap(ans1[i].f0,ans1[i].inv0),swap(ans1[i].f1,ans1[i].inv1);
	if(cnt1){
		re=ans1[1];
		for(i=2;i<=cnt1;i++) re=update(re,ans1[i]);
		if(cnt2) re=update(re,ans2[cnt2]);
	}
	else re=ans2[cnt2];
	for(i=cnt2-1;i>=1;i--) re=update(re,ans2[i]);
//	cout<<"finish solve "<<re.f0<<' '<<re.f1<<' '<<re.inv0<<' '<<re.inv1<<'\n';
	return re;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();Q=read();K=read();int i,t1,t2,opt;ll t3,ans,tmp0,tmp1;
	for(i=1;i<=n;i++) op[i]=read(),val[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs1(1,0);dfs2(1,1);
	build(1,n,1);
//	cout<<"LIMIT "<<LIM<<'\n'; 
	while(Q--){
		opt=read();t1=read();t2=read();t3=read();
		if(opt==2){
			op[t1]=t2;val[t1]=t3;
			change(1,n,1,pos[t1]);
		}
		else{
			data re=solve(t1,t2);ans=0;
			for(i=63;i>=0;i--){
				tmp0=(re.f0>>i)&1ull;
				tmp1=(re.f1>>i)&1ull;
				if(tmp0>=tmp1||(1ull<<i)>t3) ans|=(tmp0?(1ull<<i):0);
				else ans|=(tmp1?(1ull<<i):0),t3-=(1ull<<i);
			}
			printf("%llu\n",ans);
		}
	}
}
