#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 110000
struct S{
	ll u,v,ne;
}e[N<<1];
	ll n,m,fir[N],sum,p[N],dp[N][2],aa,bb,xx,yy; char s[2];
void add(ll u,ll v){
	e[++sum].ne=fir[u];
	fir[u]=sum;
	e[sum].u=u;
	e[sum].v=v;
}
void dfs(ll x,ll fath){
	ll minn=0;
	dp[x][0]=0;
	dp[x][1]=p[x];
	bool vis=false;
	for(ll i=fir[x];i;i=e[i].ne){
		ll to=e[i].v;
		if(to!=fath){
			dfs(to,x);
			vis=true;
		}
		minn+=min(dp[to][1],dp[to][0]);
	}
	if(x==aa||x==bb){
		if(xx){
			dp[x][0]=INT_MAX;
			dp[x][1]=minn+p[x];
		}
		else {
			dp[x][1]=INT_MAX;
			dp[x][0]=INT_MAX;
			for(ll i=fir[x];i;i=e[i].ne){
				ll to=e[i].v;
				if(to!=fath){
					if(dp[to][1]>dp[to][0])dp[x][0]=min(dp[x][0],dp[to][1]+minn-dp[to][0]);
					else dp[x][0]=min(dp[x][0],minn);
				}
			}
		}
		return;
	}
	if(vis)dp[x][0]=INT_MAX;
	for(ll i=fir[x];i;i=e[i].ne){
		ll to=e[i].v;
		if(to!=fath){
			if(dp[to][1]>dp[to][0])dp[x][0]=min(dp[x][0],dp[to][1]+minn-dp[to][0]);
			else dp[x][0]=min(dp[x][0],minn);
		}
	}
	dp[x][1]=minn+p[x];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)scanf("%lld",&p[i]);
	for(ll i=1;i<n;i++){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	if(s[0]=='A'){
		for(ll i=1;i<=m;i++){
			ll a,x,b,y,ans=INT_MAX;
			scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
			if(a>b)swap(a,b);
			if(b==a+1&&(!x)&&(!y)){
				printf("-1\n");
				continue;
			}
			memset(dp,0x7f,sizeof(dp));
			if(x)dp[a][1]=p[a];
			else dp[a][0]=0;
			for(ll i=a+1;i<=b-1;i++){
				dp[i][0]=dp[i-1][1];
				dp[i][1]=min(dp[i-1][0]+p[i],dp[i-1][1]+p[i]);
			}
			if(y){
				ans=min(ans,min(dp[b-1][0],dp[b-1][1])+p[b]);
				printf("%lld\n",ans);
			}
			else printf("%lld\n",dp[b-1][1]);
		}
		return 0;
	}
	for(ll i=1;i<=m;i++){
		ll a,x,b,y;
		scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
		aa=a;
		bb=b;
		xx=x;
		yy=y;
		dfs(1,0);
		ll re=min(dp[1][0],dp[1][1]);
		if(re>=INT_MAX){
			printf("-1\n");
		}
		else printf("%lld\n",re);
	}
}
