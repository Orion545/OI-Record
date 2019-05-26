#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100005
#define maxd 10005
#define ll long long
using namespace std;
int n,mxd=0;
ll ans=0;
vector<int>xb[maxd];
bool vis[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int d;
		scanf("%d",&d);
		mxd=max(mxd,d);
		xb[d].push_back(i);
	}
	memset(vis,0,sizeof(vis));
	vis[0]=vis[n+1]=1;
	int last=1;
	for(int d=0;d<mxd;++d){
		for(int i=0;i<xb[d].size();++i){
			int xia=xb[d][i];
			vis[xia]=1;
			if(!vis[xia-1]&&!vis[xia+1])++last; 
			else if(vis[xia-1]&&vis[xia+1])--last;
		}
		ans+=last;
	}
	printf("%lld\n",ans);
	return 0;
}
