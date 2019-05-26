/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
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
ll n;
int first[100010],cnte=1;
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int visp[100010],pri[100010],cntp;ll mu[100010];
vector<int>fac[100010];
void init(){
	int i,j,k,len=100000;visp[1]=1;mu[1]=1;
	for(i=2;i<=len;i++){
		if(!visp[i]) pri[++cntp]=i,mu[i]=-1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>len) break;
			visp[k]=1;
			if(i%pri[j]==0){mu[k]=0;break;}
			mu[k]=-mu[i];
		}
//		if(i<=30) cout<<i<<' '<<visp[i]<<' '<<mu[i]<<'\n';
	}
	for(i=2;i<=len;i++){
		k=i;
		for(j=1;j<=cntp;j++){
			if(k%pri[j]) continue;
//			if(i<=30) cout<<"initfac "<<i<<' '<<k<<' '<<pri[j]<<'\n';
			fac[i].push_back(pri[j]);
			while(k%pri[j]==0) k/=pri[j];
			if(k==1) break;
		}
	}
}
inline int gcd(int l,int r){
	if(!r) return l;
	return gcd(r,l%r);
}
int vis[100010],siz[100010],son[100010],sum,root,w[100010];
void getroot(int u,int f){
	int i,v;
	siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
ll cnt[100010],ans;int added[100010];
vector<int>seq;
void addg(int g){
	if(g==1) return;
	int i,s,len=fac[g].size(),tmp;
	for(s=1;s<(1<<len);s++){
		tmp=1;
		for(i=0;i<len;i++) if(s&(1<<i)) tmp*=fac[g][i];
//		cout<<"	added "<<tmp<<'\n';
		if(!cnt[tmp]) added[tmp]=1,seq.push_back(tmp);
		cnt[tmp]++;
	}
}
void addcnt(int u,int f,int g){
	int i,v;
	g=gcd(g,w[u]);
//	cout<<"addcnt "<<u<<' '<<f<<' '<<g<<'\n';
	addg(g);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]||v==f) continue;
		addcnt(v,u,g);
	}
}
void dfs(int u,int cursum){
	int i,j,v;vis[u]=1;
	addcnt(u,0,w[u]);
	for(i=0;i<seq.size();i++) ans-=mu[seq[i]]*cnt[seq[i]]*(cnt[seq[i]]-1)/2ll;
	for(i=0;i<seq.size();i++) added[seq[i]]=cnt[seq[i]]=0;
	seq.clear();
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		addcnt(v,u,w[u]);
		for(j=0;j<seq.size();j++) ans+=mu[seq[j]]*cnt[seq[j]]*(cnt[seq[j]]-1)/2ll;
		for(j=0;j<seq.size();j++) added[seq[j]]=cnt[seq[j]]=0;
		seq.clear();
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=((siz[v]>siz[u])?cursum-siz[u]:siz[v]);
		root=0;son[root]=sum;
		getroot(v,u);
		dfs(root,sum);
	}
}
int main(){
//	freopen("in.in","r",stdin);
	memset(first,-1,sizeof(first));
	init();
	n=read();int i,j,t1,t2;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++){
		t1=read();w[i]=1;
		for(j=0;j<fac[t1].size();j++) w[i]*=fac[t1][j];
//		cout<<"input "<<i<<' '<<w[i]<<' '<<t1<<' '<<fac[t1].size()<<'\n';
	}
	sum=n;root=0;son[root]=n;
	getroot(1,0);
	dfs(root,n);
//	cout<<ans<<'\n';
	printf("%lld\n",n*(n-1)/2-ans);
}
/*

3
1 2
1 3
2 10 5

7
1 2
1 3
2 4
2 5
3 6
3 7
2 4 4 14 14 7 7

*/
