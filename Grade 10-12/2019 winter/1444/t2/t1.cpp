#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
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
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
int n,cnt;
pair<int,int>p1[100010],p2[100010];
int val[200010],dis[200010],p[200010],ch[200010][2],id[200010],root[200010];
inline int newnode(int w,int d){
	int cur=++cnt;
	dis[cur]=1;ch[cur][0]=ch[cur][1]=0;
	val[cur]=w;id[d]=cur;p[cur]=d;
	return cur;
}
inline int merge(int x,int y){
	if(!x||!y) return x^y;
	if(val[x]>val[y]) swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	if(dis[ch[x][0]]<dis[ch[x][1]]) swap(ch[x][0],ch[x][1]);
	dis[x]=dis[ch[x][1]]+1;
	return x;
}
inline ll solve(pair<int,int>*lis){
	cnt=0;int i,l,r,w,d;ll ans=1,tot=1;
	for(i=1;i<=n;i++) root[i]=0;
	for(i=1;i<=n;i++){
		l=lis[i].first;r=lis[i].second;
		root[l]=merge(root[l],newnode(r,i));
		(tot*=((r-l+1)*1ll))%=MOD;
	}
	for(i=1;i<=n;i++){
		while(root[i]&&val[root[i]]<i) root[i]=merge(ch[root[i]][0],ch[root[i]][1]);
//		cout<<"enter solve "<<i<<' '<<root[i]<<' '<<val[root[i]]<<endl;
		if(!root[i]) return 0;
		w=val[root[i]];d=id[root[i]];root[i]=merge(ch[root[i]][0],ch[root[i]][1]);
		if(w<n) root[w+1]=merge(root[w+1],root[i]);
		if(d^i){
			ans*=-1;
			id[p[i]]=d;
			p[d]=p[i];
		}
	}
	if(ans<0) ans+=MOD;
	return ans*qpow(tot,MOD-2)%MOD;
}
int main(){
	int T=read(),i;
	while(T--){
		n=read();
		for(i=1;i<=n;i++){
			p1[i].first=read();p1[i].second=read();
			p2[i].first=read();p2[i].second=read();
		}
		printf("%lld\n",solve(p1)*solve(p2)%MOD);
	}
}
