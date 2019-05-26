#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll mp[N*2],lst[N*2],t[N],ln;
ll a[N],bj[N],f[N][2],n,m;
void dfs(ll x,ll la){
	f[x][0]=0;
	f[x][1]=a[x];
	for(ll c=lst[x];c;c=t[c]){
		ll y=mp[c];
		if(y==la)continue;
		dfs(y,x);
		f[x][0]+=f[y][1];
		if(bj[y]==0)f[x][0]-=f[y][1];
		ll mn=min(f[y][0],f[y][1]);
		if(bj[y]==1)mn=f[y][1];
		if(bj[y]==0)mn=f[y][0];
		f[x][1]+=mn;
	}
}
void add(ll x,ll y){
	mp[++ln]=y;t[ln]=lst[x];lst[x]=ln;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	char c=getchar();
	while(c<'A'||c>'C')c=getchar();
	char c1=getchar();
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]),bj[i]=-1;
	for(ll i=1;i<=n-1;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
	}
	for(ll i=1;i<=m;i++){
		ll x,y,bz,bz1;
		scanf("%lld%lld%lld%lld",&x,&bz,&y,&bz1);
		if(bz==0&&bz1==0){
			ll o=0;
			for(ll c=lst[x];c;c=t[c]){
				ll en=mp[c];
				if(en==y){
					o=1;
					printf("-1\n");
					break;
				}
			}
			if(o)continue;
		}
		bj[x]=bz;bj[y]=bz1;
		if(!bz){
			for(int c=lst[x];c;c=t[c])
				bj[mp[c]]=1;
		}
		if(!bz1){
			for(int c=lst[y];c;c=t[c])
				bj[mp[c]]=1;
		}
		dfs(1,0);
		ll ans=0;
		if(bj[1]==0)ans=f[1][0];
		if(bj[1]==1)ans=f[1][1];
		if(bj[1]==-1)ans=min(f[1][0],f[1][1]);
		printf("%lld\n",ans);
		bj[x]=bj[y]=-1;
		if(!bz){
			for(int c=lst[x];c;c=t[c])
				bj[mp[c]]=-1;
		}
		if(!bz1){
			for(int c=lst[y];c;c=t[c])
				bj[mp[c]]=-1;
		}
	}
	return 0;
}
