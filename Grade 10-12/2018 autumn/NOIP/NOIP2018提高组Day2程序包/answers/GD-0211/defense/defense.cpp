#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<bitset>

using namespace std;

#define N 5005
#define REP(i,a,b)	for(long long i=a;i<=b;i++)
#define DOW(i,a,b)	for(long long i=a;i>=b;i--)
#define CL(a,b)	memset(a,b,sizeof(a))


struct edge{
	long long fr,to,nex,id;
}E[N<<1];

long long head[N];
void add(long long i,long long j){
	static long long t=0;
	E[++t]=(edge){i,j,head[i]};
	head[i]=t;
}

long long dp[N][2],v[N],cann[N],mus[N];
vector<long long>vec[N];
#define INF 0x3f3f3f3f
void dfs(long long now,long long fa){
//	F[now][0]=fa;
	for(long long i=head[now];i;i=E[i].nex){
		if(E[i].to!=fa){
			dfs(E[i].to,now);
		}
	}
//	REP(i,1,17)F[now][i]=F[F[now][i-1]][i-1];
	long long P=0;
	dp[now][0]=dp[now][1]=INF;
	if(!cann[now]){
		for(long long i=head[now];i;i=E[i].nex){
			if(E[i].to!=fa){
				if(dp[E[i].to][0]<dp[E[i].to][1])P+=dp[E[i].to][0];
				else P+=dp[E[i].to][1],vec[now].push_back(E[i].to);
			}
		}
		dp[now][1]=P+v[now];
	}
	if(!mus[now]){
		dp[now][0]=0;
		for(long long i=head[now];i;i=E[i].nex){
			if(E[i].to!=fa){
				dp[now][0]+=dp[E[i].to][1];
			}
		}
	}
}

char S[5];

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	long long n,m;
	scanf("%lld %lld %s",&n,&m,S);
	REP(i,1,n)scanf("%lld",&v[i]);
	REP(i,1,n-1){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		add(x,y);add(y,x);
	}
	REP(i,1,m){
		long long a,x,b,y;
		scanf("%lld %lld %lld %lld",&a,&x,&b,&y);
		if(x)mus[a]=1;
		else cann[a]=1;
		if(y)mus[b]=1;
		else cann[b]=1;
		dfs(1,0);
		long long ans=min(dp[1][0],dp[1][1]);
		printf("%lld\n",ans>=INF?-1:ans);
		mus[a]=cann[a]=mus[b]=cann[b]=0;
	}
	
	
	return 0;
}
