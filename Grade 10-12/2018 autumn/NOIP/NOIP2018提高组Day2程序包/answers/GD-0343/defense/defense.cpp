#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,val[100001],hed[100001];
struct node{
	int to,nxt;
}edg[200001];
namespace tre
{
	int dp[2001][2],a,x,b,y;
	void dfs(int nw,int fa)
	{
		int i;
		for(i=hed[nw];i;i=edg[i].nxt)
			if(edg[i].to!=fa){
				dfs(edg[i].to,nw);
				dp[nw][0]+=dp[edg[i].to][1];
				dp[nw][1]+=min(dp[edg[i].to][0],dp[edg[i].to][1]);
			}
		dp[nw][1]+=val[nw];
		if(nw==a)
			dp[nw][x^1]=3e8;
		if(nw==b)
			dp[nw][y^1]=3e8;
	}
	void main()
	{
		int i;
		bool fla;
		while(m--){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			memset(dp,0,sizeof(dp));
			fla=0;
			if(x==0&&y==0&&a!=b)
				for(i=hed[a];i;i=edg[i].nxt)
					if(edg[i].to==b)
						fla=1;
			if(fla)
				printf("-1\n");
			else{
				dfs(1,-1);
				printf("%d\n",min(dp[1][0],dp[1][1]));
			}
		}
	}
}
inline void ade(const int i,const int &a,const int &b)
{
	edg[i].to=b;
	edg[i].nxt=hed[a];
	hed[a]=i;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int i,a,b;
	char typ[10];
	scanf("%d%d%s",&n,&m,typ);
	for(i=1;i<=n;i++)
		scanf("%d",val+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		ade(i,a,b);
		ade(i+n,b,a);
	}
	tre::main();
	return 0;
}
