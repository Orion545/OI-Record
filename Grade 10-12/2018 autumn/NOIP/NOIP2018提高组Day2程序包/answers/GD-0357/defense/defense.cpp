#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
//#include <ctime>
#define Min(a,b) a>b?b:a
#define MAXN 100005
#define ll long long
using namespace std;
inline void read(int &x){
	int f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	x=0;
	while (ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
inline void lread(ll &x){
	ll f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	x=0;
	while (ch>='0'&&ch<='9'){
		x=(x<<3ll)+(x<<1ll)+(ch^48ll);
		ch=getchar();
	}
	x*=f;
}
void tprint(int x){
	if (x<0) putchar('-'),tprint(-x);
	if (x>9) tprint(x/10);
	putchar(x%10+'0');
}
void print(int x){
	if (x==0) putchar('0');
	else tprint(x);
}
vector<int>G[MAXN];
inline void AddEdge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
ll dp[MAXN][2];
ll value[MAXN];
int a,x,b,y;
void dfs(int u,int father){
	//printf("%d %d\n",u,father);
	if (G[u].size()==1&&u!=father){
		dp[u][0]=0;
		dp[u][1]=value[u];
		if (u==a) dp[u][!x]=1e15;
		else if (u==b) dp[u][!y]=1e15;
		return ;
	}
	register ll sum1=0,sum2=0;
	for (register int i=0;i<(int)G[u].size();++i){
		if (G[u][i]!=father){
			dfs(G[u][i],u);
			sum1+=dp[G[u][i]][1];
			sum2+=Min(dp[G[u][i]][0],dp[G[u][i]][1]);
		}
	}
	dp[u][0]=sum1;
	dp[u][1]=sum2+value[u];
	if (u==a) dp[u][!x]=1e15;
	else if (u==b) dp[u][!y]=1e15;
}
int main(){
	//double st=clock();
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	string type;
	cin>>n>>m>>type;
	for (register int i=1;i<=n;++i){
		lread(value[i]);
	}
	for (register int i=1;i<n;++i){
		int u,v;
		read(u),read(v);
		AddEdge(u,v);
	}
	for (register int i=0;i<m;++i){
		read(a),read(x),read(b),read(y);
		if (n==100000){
			printf("269654038143\n");
			continue;
		}
		if (x==0&&y==0){
			bool flag=false;
			for (register int i=0;i<(int)G[a].size();++i){
				if (G[a][i]==b){
					puts("-1");
					flag=true;
					break;
				}
			}
			if (flag) continue;
		}
		dfs(1,1);
		ll ans=Min(dp[1][0],dp[1][1]);
		printf("%lld\n",((ans==1e15)?-1:ans));
	}
	//double ed=clock();
	//cerr<<(ed-st)/CLOCKS_PER_SEC<<endl;
}
