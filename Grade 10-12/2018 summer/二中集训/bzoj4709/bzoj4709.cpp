#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define inf 1e15
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
ll n,f[100010],num[10010],c[100010],a[100010],siz[100010],pre[100010],pos[100010];
vector<ll>q[10010];
ll X[100010],Y[100010];
ll sqr(ll x){
	return x*x;
}
inline double getk(ll x,ll y){
	if(X[x]==X[y]) return inf;
	else return ((double)Y[x] - Y[y]) / ((double)X[x] - X[y]) ; 
}
int main(){
	n=read();ll i,x,k,j;
	for(i=1;i<=n;i++){
		a[i]=read();
		pre[i]=pos[a[i]];
		pos[a[i]]=i;
		c[i]=++num[a[i]];
		if(!pre[i]) q[a[i]].push_back(0);
	}
//	cout<<"finish read in\n";
//	memset(siz,-1,sizeof(siz));
	for(i=1;i<=n;i++){
		x=a[i];k=2*c[i];
		X[i]=c[pre[i]]*a[i];
		Y[i]=a[i]*sqr(c[pre[i]])+f[i-1];
		while(siz[x]>0&&getk(q[x][siz[x]-1],q[x][siz[x]])<getk(q[x][siz[x]],i)-1e-7)
			siz[x]--,q[x].pop_back();
		q[x].push_back(i),siz[x]++;
		while(siz[x]>0&&getk(q[x][siz[x]-1],q[x][siz[x]])-1e-7<k)
			siz[x]--,q[x].pop_back();
		j=q[x][siz[x]];
		f[i]=a[i]*sqr(c[i])+(-2ll*c[i]*(c[pre[j]]*a[j])+a[j]*sqr(c[pre[j]])+f[j-1]);
//		cout<<i<<' '<<a[i]<<' '<<f[i]<<'\n';
	}
	cout<<f[n];
}
