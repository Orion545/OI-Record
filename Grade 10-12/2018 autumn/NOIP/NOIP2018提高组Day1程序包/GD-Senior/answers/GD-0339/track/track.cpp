#include<cstdio>
#include<algorithm>
#define N 50010
#define ll long long
using namespace std;
int head[N],to[N*2],nxt[N*2],len[N*2],a[N],p[N];
int n,m,eCnt;
ll esum,ans,DP[N],dp[N];
inline void add(int u,int v,int w){
	eCnt++;
	nxt[eCnt]=head[u];
	to[eCnt]=v;
	len[eCnt]=w;
	head[u]=eCnt;
}
void DFS(int x,int f){
	dp[x]=0;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==f)
			continue;
		DFS(y,x);
		dp[x]=max(dp[x],dp[y]+len[i]);
	}
}
//void DDFS(int x,int f,int w){
//	DP[x]=max(dp[x],DP[f]-w);
//	ans=max(ans,DP[x]);
//	for(int i=head[x];i;i=nxt[i]){
//		int y=to[i];
//		if(y==f)
//			continue;
//		DDFS(y,x,len[i]);
//	}
//}
void Solve(){
	for(int i=1;i<=n;i++){
		DFS(i,0);
//		DDFS(i,0,0);
		ans=max(ans,dp[i]);
	}
	printf("%lld",ans);
}
bool judge(int x){
	ll t=0,cnt=0;
	for(int i=1;i<=n;i++){
		t+=a[i];
		if(t>=x){
			t=0;
			cnt++;
		}
	}
	if(cnt>=m)
		return true;
	return false;
}
void Solve2(){
	ll l=1,r=esum,res;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid)){
			res=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%lld",res);
}
int F(int x,int L,int d,int f){
//	printf("%d %d %d %d\n",x,L,d,f);
	int res=0;
	if(d>=L){
		res++;
//			printf("%d %d %d %d\n",x,L,d,f);
		for(int i=head[i];i;i=nxt[i]){
			int y=to[i];
			if(y==f)
				continue;
			res+=F(y,L,len[i],x);
		}
		return res;
	}
	bool b=false;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==f)
			continue;
		if(b==false&&rand()%2){
			b=true;
			res+=F(y,L,d+len[i],x);
		}
		else
			res+=F(y,L,len[i],x);
	}
	return res;
}
bool check(int x){
	int res=0;
	int p=100;
	while(p--)
		for(int i=1;i<=n;i++)
			res=max(res,F(i,x,0,0));
	if(res>=m)
		return true;
	return false;
}

void Solve3(){
//	printf("S %d\n",F(1,10000,0,0));
	ll l=1,r=esum,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			res=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%lld",res);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool s1=true;
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		esum+=w;
		if(u!=v-1&&v!=u-1)
			s1=false;
		a[v]=w;
		add(u,v,w);
		add(v,u,w);
	}
	if(m==1){
		Solve();
		return 0;
	}
	if(s1){
		Solve2();
		return 0;
	}
	Solve3();
	return 0;
}
