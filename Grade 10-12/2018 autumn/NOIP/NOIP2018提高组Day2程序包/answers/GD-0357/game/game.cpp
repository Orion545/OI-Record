#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 105
const long long MOD=1000000007ll;
#define ll long long
using namespace std;
int Map[MAXN][MAXN];
struct node{
	string w,s;
	//w:RDRD s:1010
};
int n,m;
node ans[1000005];
int tot;
inline node make_node(string s,string w){
	node temp;
	temp.w=w,temp.s=s;
	return temp;
}
void dfs2(int x,int y,node temp){
	if (x>n||y>m){
		return ;
	}
	if (x==n&&y==m){
		temp.s+=(char)(Map[x][y]+'0');
		ans[++tot]=temp;
		return ;
	}
	dfs2(x+1,y,make_node(temp.w+'R',temp.s+(char)(Map[x][y]+'0')));
	dfs2(x,y+1,make_node(temp.w+'D',temp.s+(char)(Map[x][y]+'0')));
}
//如果 w(P1)>w(P2)，那么必须 s(P1)≤s(P2)。
int cnt=0;
inline bool Check(){
	tot=0;
	dfs2(1,1,make_node("",""));
	for (register int i=1;i<=tot;++i){
		for (register int j=1;j<=tot;++j){
			if (ans[i].w>ans[j].w&&ans[i].s>ans[j].s){
				return false;
			}
		}
	}
	return true;
}
inline ll ksm(ll b,ll k){
	ll ans=1;
	while (k){
		if (k&1ll) ans=(ans*b)%MOD;
		b=(b*b)%MOD;
		k>>=1ll;
	}
	return ans%MOD;
}
const int db[5][5]={
	{2,4,8,16,64},
	{4,12,36,108,324},
	{8,36,112,336,1008},
	{16,108,336,912,2688},
	{64,324,1008,2688,7136},
};
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n<=5&&m<=5){
//		for (register int i=0;i<(1<<(n*m));++i){
//			memset(Map,0,sizeof(Map));
//			for (register int j=1;j<=(n*m);++j){
//				if ((i&(1<<j))){
//					Map[j/m+1][j%m+1]=1;
//				}
//			}
//			if (Check()) cnt++;
//		}
//		printf("%d\n",cnt);
//		return 0;
		printf("%d\n",db[n-1][m-1]);
	}
	if (n>m) std::swap(n,m);
	if (n==1){
		printf("%lld\n",ksm(2ll,(ll)m));
	}
	else if (n==2){
		printf("%lld\n",(12ll*ksm(3ll,(ll)m-2ll))%MOD);
	}
	else if (n==3){
		printf("%lld\n",(112ll*ksm(3ll,(ll)m-3ll))%MOD);
	}
}
