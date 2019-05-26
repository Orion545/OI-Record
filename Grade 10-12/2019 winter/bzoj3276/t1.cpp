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
ll n,type,first[200010],cnte=-1,fa[200010];
ll f[200010],p[200010],q[200010],lim[200010],dis[200010];

struct edge{
	ll to,next,w,ban;
}a[200010];
inline void add(ll u,ll v,ll w){
//	cout<<"add edge "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnte]=(edge){v,first[u],w,0};first[u]=cnte;
}

namespace con{
	struct pt{
		ll x,y;
		pt(){x=y=0;}
		pt(ll l,ll r){x=l;y=r;}
	}s[200010];
	ll top=0;
	double slope[200010];
	inline double gets(pt x,pt y){
		return (double)(x.y-y.y)/(x.x-y.x);
	}
	void insert(ll x){
//		cout<<"	insert "<<x<<'\n';
		pt cur=pt(dis[x],f[x]);
		double tmp=((200000-top)?gets(cur,s[top]):1e15);
		while(200000-top>=2&&tmp>(slope[top]+1e-4)) tmp=gets(cur,s[++top]);
		s[--top]=cur;
		slope[top]=tmp;
	}
	pt query(double sl){
		int re=lower_bound(slope+top,slope+200000,sl)-slope;
		return s[re];
	}
}

void getdis(ll u,ll f,ll w){
	dis[u]=dis[f]+w;
	for(ll i=first[u];~i;i=a[i].next) getdis(a[i].to,u,a[i].w);
}

ll siz[200010],son[200010],sum;
void getroot(ll u,ll &root){
	ll i,v;
	siz[u]=1;son[u]=0;
//	cout<<"getroot "<<u<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(a[i].ban) continue;
		getroot(v,root);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(siz[u]!=1&&son[u]<son[root]) root=u;
//	cout<<"finish getroot "<<u<<' '<<siz[u]<<' '<<son[u]<<' '<<root<<' '<<son[root]<<'\n';
}

ll lis[200010],cntl;
void getp(ll u){
	ll i,v;lis[++cntl]=u;
	for(i=first[u];~i;i=a[i].next){
		if(!a[i].ban) getp(a[i].to);
	}
}
inline bool cmp(ll l,ll r){
	return dis[l]-lim[l]>dis[r]-lim[r];
}

ll vis[200010];
void divcon(ll u,ll cursum){
	if(cursum==1){
//		cout<<"reach end "<<u<<' '<<f[u]<<'\n';
		return;
	}
	assert(cursum<=n);assert(cursum>0);
	ll i,j,cur,v,root;
	vis[u]=1;

	sum=cursum;root=0;
	getroot(u,root);
//	cout<<"divcon "<<u<<' '<<cursum<<' '<<root<<'\n';

	for(i=first[root];~i;i=a[i].next) a[i].ban=1;
	divcon(u,cursum-siz[root]+1);

	cntl=0;
	for(i=first[root];~i;i=a[i].next) getp(a[i].to);
	sort(lis+1,lis+cntl+1,cmp);

	using namespace con;
	for(i=1,j=root,top=200000;i<=cntl;i++){
		cur=lis[i];
		for(;j!=fa[u]&&dis[j]>=dis[cur]-lim[cur];j=fa[j]) insert(j);
		if(top!=200000){
			pt tmp=query(p[cur]);
			f[cur]=min(f[cur],tmp.y+p[cur]*(dis[cur]-tmp.x)+q[cur]);
//			cout<<"	query "<<cur<<' '<<tmp.x<<' '<<tmp.y<<' '<<f[cur]<<'\n';
		}
	}
	for(i=first[root];~i;i=a[i].next) divcon(a[i].to,siz[a[i].to]);
}

int main(){
	memset(first,-1,sizeof(first));
	n=read();type=read();ll i,t1,t2,t3,t4,t5;son[0]=n+1;
	for(i=2;i<=n;i++){
		t1=read();t2=read();t3=read();t4=read();t5=read();
		fa[i]=t1;
		p[i]=t3;
		q[i]=t4;
		lim[i]=t5;
		add(fa[i],i,t2);
	}
	for(i=1;i<=n;i++) f[i]=1e18;
	f[1]=0;
	getdis(1,0,0);
	divcon(1,n);
	for(i=2;i<=n;i++) printf("%lld\n",f[i]);
}
