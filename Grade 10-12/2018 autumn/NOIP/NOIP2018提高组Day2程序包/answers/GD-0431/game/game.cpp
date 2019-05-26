#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

typedef long long LL;
const int MOD=1000000007;
const int N=2000005;

struct data {int x,y,w,z;} ;

int f[N][64],n,m;
int rc[100][100],ans;

bool check(int x,int y) {
	rep(i,1,n) {
		int tmp1=(1<<i)-1;
		int wjp=y&tmp1; wjp>>=1;
		int tmp2=(1<<(i-1))-1;
		int lxf=x&tmp2;
		if (lxf>wjp) return false;
	}
	return true;
	x<<=1;
	rep(i,1,n-1) {
		int a=(x>>i)&1;
		int b=(y>>i)&1;
		if (a>b) return false;
	}
	return true;
}

bool baba(data p1,data p2) {
	if (p1.w>p2.w&&p1.z>p2.z) return false;
	if (p1.w<p2.w&&p1.z<p2.z) return false;
	return true;
}

bool check() {
	std:: queue <data> que;
	std:: vector <data> vec;
	que.push((data) {1,1,rc[1][1],0});
	for (;!que.empty();) {
		data now=que.front(); que.pop();
		if (now.x==n&&now.y==m) {
			vec.push_back(now);
		}
		if (now.x!=n) {
			que.push((data) {now.x+1,now.y,now.w*2+0,now.z*2+rc[now.x+1][now.y]});
		}
		if (now.y!=m) {
			que.push((data) {now.x,now.y+1,now.w*2+1,now.z*2+rc[now.x][now.y+1]});
		}
	}
	for (int i=0;i<vec.size();++i) {
		for (int j=1;j<vec.size();++j) {
			if (!baba(vec[i],vec[j])) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int x,int y) {
	if (x==n+1) {
		ans+=check();
		(ans>=MOD)?(ans-=MOD):0;
		return ;
	}
	rc[x][y]=1;
	if (y==m) dfs(x+1,1);
	else dfs(x,y+1);
	rc[x][y]=0;
	if (y==m) dfs(x+1,1);
	else dfs(x,y+1);
}

int main(void) {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (m<n) std:: swap(n,m);
	if (n*m<14) {
		dfs(1,1); printf("%d\n", ans);
		return 0;
	}
	if (n==3) {
		LL ans=112;
		rep(i,4,m) ans=1LL*ans*3%MOD;
		printf("%lld\n", ans);
		return 0;
	}
	int lim=(1<<n)-1;
	rep(i,0,lim) f[1][i]=1;
	rep(i,2,m) {
		rep(j,0,lim) {
			rep(k,0,lim) {
				if (check(j,k)) {
					f[i][j]=f[i][j]+f[i-1][k];
					(f[i][j]>=MOD)?(f[i][j]-=MOD):0;
				}
			}
		}
	}
	int ans=0;
	rep(i,0,lim) ans=(ans+f[m][i])%MOD;
	printf("%d\n", ans);
	return 0;
}
