#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<stack>
#include<vector>
#define MOD 1000000007
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll inv[200010],fac[200010];
namespace topo{
	int first[200010],cnte;
	vector<int>e[200010];
	int inbound[200010],worked[200010];
	vector<int>appearance;
	inline void add(int u,int v){
		e[u].push_back(v);
		inbound[v]++;
	}
	int siz[200010];
	ll dfs(int u,int f){
		ll re=1;siz[u]=1;
		assert(u);
		for(auto v:e[u]){
			if(v==f) continue;
			(re*=dfs(v,u))%=MOD;
			siz[u]+=siz[v];
		}
		return re*inv[siz[u]]%MOD;
	}
	ll solve(){
		ll re=1,tmp;
		for(auto u:appearance){
			if(!inbound[u]&&!worked[u]){
				tmp=dfs(u,0);
				worked[u]=1;
				(re*=tmp%MOD)%=MOD;
			}
		}
		for(auto u:appearance){
			e[u].clear();
			inbound[u]=0;
			worked[u]=0;
		}
		return re;
	}
}
vector<int>e[200010];
stack<int>s;
bool vis[200010],on_circle[200010];int cnt1,cnt2,lped;
vector<int>circle;
void dfs(int u,int f){
	int i,v;cnt1++;s.push(u);
	vis[u]=1;
	for(i=0;i<e[u].size();i++){
		v=e[u][i];if(v==f||on_circle[v]) continue;
		cnt2++;
		if(!lped&&vis[v]){
			lped=1;
			while(s.top()!=v){ 
				circle.push_back(s.top());
				on_circle[s.top()]=1;
				s.pop();
			}
			circle.push_back(s.top());
			on_circle[s.top()]=1;
			s.pop();
		}
		else if(!vis[v]){
			dfs(v,u);
		}
	}
	if(!s.empty()&&s.top()==u) s.pop();
}
int control[200010];
void dfs2(int u,int f){
	int i,v;
	for(i=0;i<e[u].size();i++){
		v=e[u][i];
		if(v==f||on_circle[v]) continue;
		control[v]=u;
		dfs2(v,u);
	}
}
void adde(int u,int f){
	topo::appearance.push_back(u);
	for(auto v:e[u]){
		if(v==control[u]) break;
		topo::add(u,v);
	}
	for(auto v:e[u]){
		if(v==f||on_circle[v]) continue;
		adde(v,u);
	}
}
ll solve(int u){
	cnt1=cnt2=lped=0;
	dfs(u,0);
	cout<<"orzhwc "<<cnt1<<' '<<cnt2<<'\n';
	if(cnt1!=cnt2) return 0;
	int i;ll re=0;
	for(i=0;i<circle.size();i++){
		dfs2(circle[i],0);
	}
	//first
	for(i=0;i<circle.size();i++){
		control[circle[i]]=circle[(i+1)%circle.size()];
	}
	for(i=0;i<circle.size();i++){
		adde(circle[i],0);
	}
	re+=topo::solve();
	topo::appearance.clear();
	//second
	for(i=0;i<circle.size();i++){
		control[circle[i]]=circle[(i-1+circle.size())%circle.size()];
	}
	for(i=0;i<circle.size();i++){
		adde(circle[i],0);
	}
	re+=topo::solve();
	topo::appearance.clear();
	for(i=0;i<circle.size();i++) on_circle[i]=0;
	circle.clear();
	return re%MOD;
}
int n;
int main(){
	n=read();int i,t1,t2;
	memset(topo::first,-1,sizeof(topo::first));
	inv[1]=1;fac[1]=1;
	for(i=2;i<=n*2;i++) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(i=2;i<=n*2;i++) fac[i]=fac[i-1]*i%MOD;
	for(i=1;i<=n*2;i++){
		t1=read();t2=read();t2+=n;
		e[t1].push_back(t2);
		e[t2].push_back(t1);
	}
	for(i=1;i<=n*2;i++){
		if(e[i].size()) sort(e[i].begin(),e[i].end());
	}
	ll ans=1;
	for(i=1;i<=n*2;i++){
		if(!vis[i]) (ans=ans*solve(i))%=MOD;
	}
	cout<<(fac[2*n]*ans)%MOD<<'\n';
}
