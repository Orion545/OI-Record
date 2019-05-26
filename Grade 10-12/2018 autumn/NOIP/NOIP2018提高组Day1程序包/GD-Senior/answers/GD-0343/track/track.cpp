#include<cstdio>

int n,m,hed[50001];
struct node{
	int to,dis,nxt;
}edg[100001];
namespace m1
{
	int ans=0,dp[30001];
	void dfs(int n,int fa)
	{
		int i,maxn=0;
		for(i=hed[n];i;i=edg[i].nxt)
			if(edg[i].to!=fa){
				dfs(edg[i].to,n);
				if(dp[edg[i].to]+edg[i].dis+maxn>ans)
					ans=dp[edg[i].to]+maxn+edg[i].dis;
				if(dp[edg[i].to]+edg[i].dis>maxn)
					maxn=dp[edg[i].to]+edg[i].dis;
			}
		dp[n]=maxn;
	}
	void main()
	{
		dfs(1,-1);
		printf("%d",ans);
	}
}
namespace li
{
	int len[50001];
	void main()
	{
		int i,j,l=0,r=1e9,mid,nw;
		for(i=1;i<=n;i++)
			for(j=hed[i];j;j=edg[j].nxt)
				if(edg[j].to==i+1)
					len[i]=edg[j].dis;
		while(l<r){
			mid=(l+r+1)>>1;
			j=0,nw=0;
			for(i=1;i<=n;i++){
				nw+=len[i];
				if(nw>=mid)
					j++,nw=0;
			}
			if(j>=m)
				l=mid;
			else
				r=mid-1;
		}
		printf("%d",l);
	}
}
inline void ade(const int i,const int &a,const int &b,const int &c)
{
	edg[i].to=b;
	edg[i].dis=c;
	edg[i].nxt=hed[a];
	hed[a]=i;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i,a,b,c;
	bool lian=1,c1=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		c1&=(c==1);
		lian&=(b==(a+1));
		ade(i,a,b,c);
		ade(i+n,b,a,c);
	}
	if(m==1){
		m1::main();
		return 0;
	}
	if(lian){
		li::main();
		return 0;
	}
	return 0;
}
