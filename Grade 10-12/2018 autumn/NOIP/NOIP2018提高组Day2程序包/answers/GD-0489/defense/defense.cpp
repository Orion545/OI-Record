#include<iostream>
using namespace std;
#include<cstring>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>

int n,m;
char type[3];
long long p[100005];
int head[100005],tot;
int anc[100005][20],depth[100005];
long long dp[100005][2];

struct edge{
	int to,next;
}e[200005];

void build(int x,int y) {
	tot++;
	e[tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",type);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
	}
	for(int i=1;i<=m;i++) {
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(type[0]=='A') {
			if(abs(a-b)==1 && x==0 && y==0) {
				printf("-1\n");
				continue;
			}
			else {
				memset(dp,0,(sizeof dp));
				for(int i=1;i<=n;i++) {
					if(i!=a && i!=b) {
						dp[i][0]=dp[i-1][1];
						if(dp[i-1][1]==-1) dp[i][1]=dp[i-1][0]+p[i];
						else if(dp[i-1][0]==-1) dp[i][1]=dp[i-1][1]+p[i];
						else dp[i][1]=min(dp[i-1][1],dp[i-1][0])+p[i];
					}
					else {
						if(i==a) {
							if(x==0) {
								dp[i][0]=dp[i-1][1];
								dp[i][1]=-1;
							}
							else {
								dp[i][0]=-1;
								if(dp[i-1][1]==-1) dp[i][1]=dp[i-1][0]+p[i];
								else if(dp[i-1][0]==-1) dp[i][1]=dp[i-1][1]+p[i];
								else dp[i][1]=min(dp[i-1][1],dp[i-1][0])+p[i];
							}
						}
						else {
							if(y==0) {
								dp[i][0]=dp[i-1][1];
								dp[i][1]=-1;
							}
							else {
								dp[i][0]=-1;
								if(dp[i-1][1]==-1) dp[i][1]=dp[i-1][0]+p[i];
								else if(dp[i-1][0]==-1) dp[i][1]=dp[i-1][1]+p[i];
								else dp[i][1]=min(dp[i-1][1],dp[i-1][0])+p[i];
							}
						}
					}
				}
				if(dp[n][0]==-1) printf("%lld\n",dp[n][1]);
				else if(dp[n][1]==-1) printf("%lld\n",dp[n][0]);
				else printf("%lld\n",min(dp[n][0],dp[n][1]));
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
