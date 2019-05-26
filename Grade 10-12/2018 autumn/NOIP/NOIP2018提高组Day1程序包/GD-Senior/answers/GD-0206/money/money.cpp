#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=1e2+10,M=3e4+10,Mx=2147483640/2;
ll dis[M],a[N],b[N],n,m;
ll dt[M*10],bz[M],h[M];
void spfa(ll p){
	ll en=0;
	if(dis[p%a[1]]==Mx)h[++h[0]]=p%a[1];
	dis[p%a[1]]=min(dis[p%a[1]],p);
	for(int i=1;i<=h[0];i++){
		dt[++en]=h[i];bz[h[i]]=1;
	}
	for(ll st=1;st<=en;st++){
		ll x=dt[st];
		ll y=(x+p)%a[1];
		if(dis[x]+p<dis[y]){
			if(dis[y]==Mx)
				h[++h[0]]=y;
			dis[y]=dis[x]+p;
			if(bz[y])continue;
			bz[y]=1;
			dt[++en]=y;
		}
		bz[x]=0;
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--){
		memset(dis,127,sizeof(dis));
		memset(h,0,sizeof(h));
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(ll i=0;i<=a[1]-1;i++)dis[i]=Mx;
		b[1]=a[1];
		dis[0]=a[1];
		h[++h[0]]=0;
		m=1;
		for(ll i=2;i<=n;i++){
			if(dis[a[i]%a[1]]<=a[i])continue;
			b[++m]=a[i];
			spfa(a[i]);
		}
		printf("%lld\n",m);
	}
	return 0;
}
