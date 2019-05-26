#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<queue>
#include<set>
#include<map>
#define ll long long
#define mp (FAN)
#define inf 1000000000000000ll
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
ll n,m,q,first[300010],cnte=-1,vis[300010],go[300010],dis[50][300010],cnt;
ll dep[300010],dd[300010],st[300010][20];
set<ll>s;
map<ll,ll>M;
struct edge{
	ll to,next,w;
}a[300010];
inline void add(ll u,ll v,ll w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
struct FAN{
	ll val,node;
};
bool operator <(FAN l,FAN r){
	return l.val>r.val;
}
void dij(ll st){
	memset(go,0,sizeof(go));
    ll i,u,v,w,num=0;
    priority_queue<FAN>H;
    for(i=1;i<=n;i++) dis[cnt][i]=inf;
    dis[cnt][st]=0;H.push(mp{0,st});
    while(num<n&&(!H.empty())){
        u=H.top().node;H.pop();
        if(go[u]) continue;
//		cout<<u<<ends<<dis[cnt][u]<<endl;
        go[u]=1;num++;
        for(i=first[u];~i;i=a[i].next){
            v=a[i].to;w=a[i].w;
//			cout<<"	to "<<v<<ends<<dis[cnt][v]<<ends<<dis[cnt][u]+w<<endl;
            if(dis[cnt][v]>dis[cnt][u]+w){
//				cout<<"		renew"<<endl;
                dis[cnt][v]=dis[cnt][u]+w;
                H.push(mp{dis[cnt][v],v});
            }
        }
    }
//	cout<<"finish dij "<<st<<"\n";
//	for(i=1;i<=n;i++) cout<<i<<' '<<dis[cnt][i]<<'\n';
}
void dfs(ll u,ll f,ll w){
	ll i,v;go[u]=1;dep[u]=dep[f]+1;dd[u]=dd[f]+w;
	st[u][0]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[i]||go[v]) continue;
		vis[i]=vis[i^1]=1;dfs(v,u,a[i].w);
	}
}
void ST(){
	ll i,j;
	for(j=1;j<=18;j++){
		for(i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
ll getlca(ll l,ll r){
	ll i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=18;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=18;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			r=st[r][i];
			l=st[l][i];
		}
	}
	return st[l][0];
}
ll getdis(ll l,ll r){
	return dd[l]+dd[r]-2ll*dd[getlca(l,r)];
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();ll i,t1,t2,t3;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dfs(1,0,0);ST();
	for(i=0;i<=cnte;i++){
		if(!vis[i]){
//			cout<<"get not tree "<<i<<' '<<a[i].to<<' '<<a[i^1].to<<'\n';
			if(s.find(a[i].to)==s.end()){
				s.insert(a[i].to);cnt=s.size();
				M[a[i].to]=cnt;
				dij(a[i].to);
			}
			if(s.find(a[i^1].to)==s.end()){
				s.insert(a[i^1].to);cnt=s.size();
				M[a[i^1].to]=cnt;
				dij(a[i^1].to);
			}
		}
	}
	q=read();
	while(q--){
		t1=read();t2=read();
			ll ans=getdis(t1,t2);
		for(auto u:s){
//			cout<<"calcing "<<u<<' '<<getdis(t1,u)<<' '<<getdis(t2,u)<<' '<<dis[M[u]][t1]<<' '<<dis[M[u]][t2]<<'\n';
			ans=min(ans,min(getdis(t1,u),dis[M[u]][t1])+min(getdis(t2,u),dis[M[u]][t2]));
		}
		printf("%I64d\n",ans);
	}
}
/*
4 6
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4

*/
