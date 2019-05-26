#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 51000
struct S{
	ll u,v,w,ne;
}e[N<<1];
ll n,m,tmp[N],sum,fir[N],dep[N],father[N][20],len[N],dis[N];
bool bo1=true,bo2=true,vis[N];
priority_queue<ll,vector<ll>,greater<ll> > q;
queue<ll> q1;
void add(ll u,ll v,ll w){
	e[++sum].ne=fir[u];
	fir[u]=sum;
	e[sum].u=u;
	e[sum].v=v;
	e[sum].w=w;
}
bool cmp(ll x,ll y){
	return x>y;
}
void dfs(ll x,ll fath){
	dep[x]=dep[fath]+1;
	father[x][0]=fath;
	ll st=log2(dep[x]);
	for(ll i=1;i<=st;i++)father[x][i]=father[father[x][i-1]][i-1];
	for(ll i=fir[x];i;i=e[i].ne){
		ll to=e[i].v;
		if(to!=fath){
			len[to]=len[x]+e[i].w;
			dfs(to,x);
		}
	}
}
ll lca(ll x,ll y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y]){
		ll st=log2(dep[x]-dep[y]);
		x=father[x][st];
	}
	if(x==y)return y;
	while(father[x][0]!=father[y][0]){
		ll st=log2(dep[x]);
		while(father[x][st]==father[y][st])st--;
		x=father[x][st];
		y=father[y][st];
	}
	return father[x][0];
}
void spfa(ll x){
	memset(vis,false,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
	dis[x]=0;
	vis[x]=true;
	q.push(x);
	while(!q1.empty()){
		ll st=q1.front();
		for(ll i=fir[st];i;i=e[i].ne){
			ll to=e[i].v;
			ll tmp=dis[st]+e[i].w;
			if(tmp<dis[to]){
				dis[to]=tmp;
				if(!vis[to]){
					q1.push(to);
					vis[to]=true;
				}
			}
		}
		q1.pop();
		vis[st]=false;
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<n;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		tmp[i]=w;
		if(u!=1)bo1=false;
		if(v!=u+1)bo2=false;
	}
	if(bo1){
		ll l=1,r=21000;
		sort(tmp+1,tmp+n,cmp);
		while(l<r){
			ll mid=(l+r+1)>>1,check=0,pre=0;
			for(ll i=1;i<n;i++){
				if(tmp[i]>=mid)check++;
				else {
					pre+=tmp[i];
					if(pre>=mid)check++,pre=0;
				}
			}
			if(check>=m)l=mid;
			else r=mid-1;
		}
		printf("%lld\n",l);
		return 0;
	}
	if(bo2){
		ll l=1,r=21000;
		while(l<r){
			ll mid=(l+r+1)>>1,pre=0,check=0;
			for(ll i=1;i<n;i++){
				if(pre<mid)pre+=tmp[i];
				if(pre>=mid)check++,pre=0;
			}
			if(check>=m)l=mid;
			else r=mid-1;
		}
		printf("%lld\n",l);
		return 0;
	}
	if(m==1){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			spfa(i);
			for(ll j=1;j<=n;j++)ans=max(ans,dis[j]);
		}
		printf("%lld\n",ans);
		return 0;
	}
	dfs(1,0);
	for(ll i=1;i<n;i++){
		for(ll j=i+1;j<=n;j++){
			ll fafa=lca(i,j);
			ll dis=len[i]+len[j]-2*len[fafa];
			q.push(dis);
			ll sz=q.size();
			if(sz>m)q.pop();
		}
	}
	ll ans=q.top();
	printf("%lld\n",ans);
}
