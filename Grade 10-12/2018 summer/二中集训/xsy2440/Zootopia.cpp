#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 20160501
#define inv2 10080251
ll Sum2[100010];
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
//tree division
int n,first[100010],ori[100010],dep[100010],size[100010],son[100010],top[100010],pos[100010],back[100010],fa[100010];
struct edge{
	int to,next;
}e[200010];int cnte,clk;
inline void addedge(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs1(int u,int f){
	int i,v;
	dep[u]=dep[f]+1;
	fa[u]=f;
	size[u]=1;
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[son[u]]<size[v]) son[u]=v;
	}
}
void dfs2(int u,int t){
	int i,v;
	top[u]=t;
	clk++;
	pos[u]=clk;
	back[clk]=u;
//	cout<<"dfs2 "<<u<<' '<<top[u]<<' '<<pos[u]<<' '<<t<<' '<<son[u]<<'\n';
	if(son[u]) dfs2(son[u],t);
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==son[u]||v==fa[u]) continue;
		dfs2(v,v);
	}
}
//segment tree with lazy tag stablized
ll add[12000010];int ch[12000010][2],root[200010],now,cnt,tot;
struct node{
	ll sum0,sum1,sum2,siz;
	node(ll s0=0,ll s1=0,ll s2=0,ll s=0){sum0=s0;sum1=s1;sum2=s2;siz=s;}
	bool empty(){return (sum1==0&&sum2==0&&sum0==0&&siz==0);}
}a[12000010],rev[12000010];
ll sqr(ll x){
	return x*x%MOD;
}
ll S1(ll x){
//	cout<<"			S1 "<<x<<' '<<x*(x+1)%MOD*inv2%MOD<<'\n';
	return x*(x+1)%MOD*inv2%MOD;
}
ll S2(ll x){
//	cout<<"			S2 "<<x<<' '<<Sum2[x]<<'\n';
	return Sum2[x]; 
}
void merge(node &cur,node l,node r){
	if(l.empty()){cur=r;return;}
	if(r.empty()){cur=l;return;}
//	cout<<"		merge "<<l.sum0<<' '<<l.sum1<<' '<<l.sum2<<' '<<l.siz<<' '<<r.sum0<<' '<<r.sum1<<' '<<r.sum2<<' '<<r.siz<<'\n';
	cur.siz=l.siz+r.siz;
	cur.sum0=(l.sum0+r.sum0)%MOD;
	cur.sum1=(l.sum1+r.sum1+r.sum0*l.siz)%MOD;
	cur.sum2=(l.sum2+r.sum2+r.sum1*2*l.siz+r.sum0*sqr(l.siz))%MOD;
}
int build(int l,int r){
	int cur=++cnt;
	if(l==r){
		a[cur].siz=rev[cur].siz=1;
		a[cur].sum0=a[cur].sum1=a[cur].sum2=ori[back[l]];
		rev[cur].sum0=rev[cur].sum1=rev[cur].sum2=ori[back[l]];
		return cur;
	}
	int mid=(l+r)>>1;
	ch[cur][0]=build(l,mid);
	ch[cur][1]=build(mid+1,r);
	merge(a[cur],a[ch[cur][0]],a[ch[cur][1]]);
	merge(rev[cur],rev[ch[cur][1]],rev[ch[cur][0]]);
	return cur;
}
node get0(int l,int r,int ql,int qr,int cur,ll tmp){
	node re;
//	cout<<"	get0 "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<' '<<add[cur]<<' '<<a[cur].sum0<<' '<<tmp<<'\n';
	if(l>=ql&&r<=qr){
		re=a[cur];
		(re.sum0+=re.siz*tmp)%=MOD;
		(re.sum1+=S1(re.siz)*tmp)%=MOD;
		(re.sum2+=S2(re.siz)*tmp)%=MOD;
//		cout<<"	return here! "<<re.siz<<' '<<re.sum0<<' '<<re.sum1<<' '<<re.sum2<<'\n';
		return re;
	}
	int mid=(l+r)>>1;
	if(mid>=qr) return get0(l,mid,ql,qr,ch[cur][0],tmp+add[cur]);
	else{
		if(mid<ql) return get0(mid+1,r,ql,qr,ch[cur][1],tmp+add[cur]);
		else{
			merge(re,get0(l,mid,ql,qr,ch[cur][0],tmp+add[cur]),get0(mid+1,r,ql,qr,ch[cur][1],tmp+add[cur]));
		}
	}
	return re;
}
node get1(int l,int r,int ql,int qr,int cur,ll tmp){
	node re;
//	cout<<"	get1 "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<cur<<' '<<add[cur]<<' '<<rev[cur].sum0<<' '<<tmp<<'\n';
	if(l>=ql&&r<=qr){
		re=rev[cur];
		(re.sum0+=re.siz*tmp)%=MOD;
		(re.sum1+=S1(re.siz)*tmp)%=MOD;
		(re.sum2+=S2(re.siz)*tmp)%=MOD;
//		cout<<"	return here! "<<re.siz<<' '<<re.sum0<<' '<<re.sum1<<' '<<re.sum2<<'\n';
		return re;
	}
	int mid=(l+r)>>1;
	if(mid>=qr) return get1(l,mid,ql,qr,ch[cur][0],tmp+add[cur]);
	else{
		if(mid<ql) return get1(mid+1,r,ql,qr,ch[cur][1],tmp+add[cur]);
		else{
			merge(re,get1(mid+1,r,ql,qr,ch[cur][1],tmp+add[cur]),get1(l,mid,ql,qr,ch[cur][0],tmp+add[cur]));
		}
	}
	return re;
}
int change(int l,int r,int ql,int qr,int pre,int val){
	int cur=++cnt;
	a[cur]=a[pre];rev[cur]=rev[pre];
	ch[cur][0]=ch[pre][0];ch[cur][1]=ch[pre][1];add[cur]=add[pre];
	(a[cur].sum0+=(qr-ql+1)*val)%=MOD;
	(rev[cur].sum0+=(qr-ql+1)*val)%=MOD;
	(a[cur].sum1+=val*(S1(qr-l+1)-S1(ql-l)+MOD))%=MOD;
	(rev[cur].sum1+=val*(S1(r-ql+1)-S1(r-qr)+MOD))%=MOD;
	(a[cur].sum2+=val*(S2(qr-l+1)-S2(ql-l)+MOD))%=MOD;
	(rev[cur].sum2+=val*(S2(r-ql+1)-S2(r-qr)+MOD))%=MOD;
//	cout<<"change "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<val<<' '<<add[cur]<<' '<<a[cur].siz<<' '<<a[cur].sum0<<'\n';
	if(l==ql&&r==qr){
		(add[cur]+=val)%=MOD;
		return cur;
	}
	int mid=(l+r)>>1;
	if(mid>=ql) ch[cur][0]=change(l,mid,ql,min(mid,qr),ch[pre][0],val);
	if(mid<qr) ch[cur][1]=change(mid+1,r,max(mid+1,ql),qr,ch[pre][1],val);
//	merge(a[cur],a[ch[cur][0]],a[ch[cur][1]]);
//	merge(rev[cur],rev[ch[cur][1]],rev[ch[cur][0]]);
	return cur;
}
ll ask(int l,int r){
	node re0(0,0,0,0),re1(0,0,0,0),rev0(0,0,0,0),rev1(0,0,0,0),tmp;int p=1;
	//pos==1: l=l,r=r
	//pos==0: l=r,r=l
//	cout<<"enter ask "<<l<<' '<<r<<'\n';
	while(top[l]!=top[r]){
		if(dep[top[l]]>dep[top[r]]) swap(l,r),p^=1;
//		cout<<"	ask "<<l<<' '<<r<<' '<<top[l]<<' '<<top[r]<<' '<<fa[top[l]]<<' '<<fa[top[r]]<<'\n';
		if(!p){
			tmp=get1(1,n,pos[top[r]],pos[r],now,0);
			merge(re0,re0,tmp);
			tmp=get0(1,n,pos[top[r]],pos[r],now,0);
			merge(rev0,tmp,rev0);
		}
		else{
			tmp=get0(1,n,pos[top[r]],pos[r],now,0);
			merge(re1,tmp,re1);
			tmp=get1(1,n,pos[top[r]],pos[r],now,0);
			merge(rev1,rev1,tmp);
		}
		r=fa[top[r]];
	}
	if(dep[l]>dep[r]) swap(l,r),p^=1;
	if(p){
		merge(re0,re0,get0(1,n,pos[l],pos[r],now,0));
		merge(re1,re0,re1);
		merge(rev0,get1(1,n,pos[l],pos[r],now,0),rev0);
		merge(rev1,rev1,rev0);
	}
	else{
		merge(re1,get1(1,n,pos[l],pos[r],now,0),re1);
		merge(re1,re0,re1);
		merge(rev1,rev1,get0(1,n,pos[l],pos[r],now,0));
		merge(rev1,rev1,rev0);
	}
//	cout<<"finish query "<<re1.siz<<' '<<re1.sum0<<' '<<re1.sum1<<' '<<re1.sum2<<' '<<rev1.sum1<<'\n';
//	system("pause");
	return (((sqr(re1.siz)+3*re1.siz+2)*inv2%MOD*re1.sum0%MOD)-((2ll*re1.siz+3)*inv2%MOD*re1.sum1%MOD)+(inv2*re1.sum2%MOD)-rev1.sum1+MOD*2)%MOD;
}
void modify(int l,int r,int val){
//	cout<<"modify "<<l<<' '<<r<<' '<<val<<' '<<now<<'\n';
	int pre=now;
	while(top[l]!=top[r]){
		if(dep[top[l]]>dep[top[r]]) swap(l,r);
//		cout<<"	mod "<<l<<' '<<r<<'\n';
		pre=change(1,n,pos[top[r]],pos[r],pre,val);
		r=fa[top[r]];
	}
	if(dep[l]>dep[r]) swap(l,r);
	root[++tot]=change(1,n,pos[l],pos[r],pre,val);
	now=root[tot];
}
int main(){
	memset(first,-1,sizeof(first));
	ll i,t1,t2,t3,tt;ll lastans=0;
	Sum2[0]=0;
	for(i=1;i<=100000;i++) Sum2[i]=(Sum2[i-1]+i*i)%MOD;
	n=read();int Q=read();
	for(i=1;i<n;i++){
		t1=read(),t2=read();
		addedge(t1,t2);
	}
	for(i=1;i<=n;i++) ori[i]=read();
	dfs1(1,0);dfs2(1,1);
	now=root[0]=build(1,n);
//	cout<<"CHECK\n";
	while(Q--){
		tt=read();
		if(tt==1){
			t1=read();t2=read();t3=read();
			t1^=lastans;t2^=lastans;
			modify(t1,t2,t3);
		}
		if(tt==2){
			t1=read();t2=read();
			t1^=lastans;t2^=lastans;
			printf("%lld\n",lastans=ask(t1,t2));
		}
		if(tt==3){
			t1=read();t1^=lastans;
			now=root[t1];
		}
		assert(cnt<=10000000);
	}
}
/*
5 6
1 2
2 3
3 4
4 5
1 2 3 4 5
1 1 5 2
3 0
1 1 3 2
1 3 4 2
3 2
2 1 5

5 4
1 2
1 3
2 4
3 5
1 1 1 2 2
1 1 4 2
2 1 4
3 12
2 13 8

5 4
1 2
2 3
2 4
3 5
3 4 2 5 1
2 5 4

*/
