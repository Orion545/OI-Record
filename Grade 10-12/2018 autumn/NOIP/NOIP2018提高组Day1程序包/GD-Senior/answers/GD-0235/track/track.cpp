#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 50010
using namespace std;
ll ans,l,r,mid,x,y,z,tot,n,m,p,sum;
ll t[N*2],nx[N*2],s[N*2],ls[N],d[N];
bool bz[N],bzs;
void add(ll x,ll y,ll z){
	d[x]++;
	t[++t[0]]=y;
	s[t[0]]=z;
	nx[t[0]]=ls[x];
	ls[x]=t[0];
}
void dfs(int x,ll sum){
	if(ans<sum) ans=sum;
	for(int k=ls[x];k;k=nx[k]){
		if(!bz[t[k]]){
			bz[t[k]]=1;
			dfs(t[k],sum+s[k]);
			bz[t[k]]=0;
		}
	}
}
void dg(int x,ll z){
	if(sum>=tot*z) tot++;
	for(int k=ls[x];k;k=nx[k]){
		if(!bz[t[k]]){
			bz[t[k]]=1;
			sum+=s[k];
			dg(t[k],z);
			sum-=s[k];
			bz[t[k]]=0;
		}
	}
}
int check(ll x){
	sum=tot=0;
	for(int i=1;i<=n;i++){
		bz[i]=1;
		dg(i,x);
		bz[i]=0;
	}
	if(tot>m) return 1;
	return 0;
}
void dgs(int x,ll st,ll sum){
	ll sts=sum;
	if(sum>=st){
		tot++;
		sts=0;
	}
	for(int k=ls[x];k;k=nx[k]){
		if(!bz[t[k]]){
			bz[t[k]]=1;
			dgs(t[k],st,sts+s[k]);
			bz[t[k]]=0;
		}
	}
}
int pd(ll x){
	bz[p]=1;tot=0;
	dgs(p,x,0);
	bz[p]=0;
	if(tot>=m) return 1;
	return 0;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bzs=1;
	for(int i=1;i<=n-1;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		if(y!=x+1) bzs=0;
		add(x,y,z);add(y,x,z);
		r+=z;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			bz[i]=1;
			dfs(i,0);
			bz[i]=0;
		}
		printf("%lld",ans);
		return 0;
	}
	if(bzs){
		for(int i=1;i<=n;i++) if(d[i]==1) {p=i;break;}
		while(l<=r){
			mid=(l+r)>>1;
			if(pd(mid)){
				ans=mid;l=mid+1;
			}
			else r=mid-1;
		}
		printf("%lld",ans);
		return 0;
	}
	l=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;ans=mid;
		}
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
