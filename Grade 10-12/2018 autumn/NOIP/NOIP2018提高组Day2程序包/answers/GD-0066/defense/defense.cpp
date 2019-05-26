#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct soren
{
	int n,t;
};
const int maxn=100010;
int a,b,c,d,c2,d2,i,ii,tot,h[maxn],w[maxn];
int mt[maxn],dp[maxn][2];
soren e[maxn*2];
char QAQ;
bool s;
void add(int u,int v)
{
	tot++;
	e[tot].t=v;
	e[tot].n=h[u];
	h[u]=tot;
}
void treedp(int u,int fa)
{
	int j;
	if (mt[u]!=1) dp[u][0]=0;
	if (mt[u]!=0) dp[u][1]=w[u];
	for (j=h[u];j!=0;j=e[j].n)
	 if (e[j].t!=fa)
	 {
	 	treedp(e[j].t,u);
	 	if (mt[u]!=1) if (mt[e[j].t]==0) {mt[u]=1; dp[u][0]=0x3F3F3F3F;}
		               else dp[u][0]=dp[u][0]+dp[e[j].t][1];
	 	if (mt[u]!=0)
	 	 {
	 		if (mt[e[j].t]==-1) dp[u][1]=min(dp[u][1]+dp[e[j].t][0],dp[u][1]+dp[e[j].t][1]);
	 		if (mt[e[j].t]==1) dp[u][1]=dp[u][1]+dp[e[j].t][1];
	 		if (mt[e[j].t]==0) dp[u][1]=dp[u][1]+dp[e[j].t][0];
	 	 } 
	 }
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&a,&b);
	QAQ=getchar();
	while (QAQ!='\n') QAQ=getchar();
	for (i=1;i<=a;i++)
	 scanf("%d",&w[i]);
	for (i=1;i<a;i++)
	{
		scanf("%d%d",&c,&d);
		add(c,d);
		add(d,c);
	}
	memset(mt,-1,sizeof(mt));
	for (i=1;i<=b;i++)
	{
		scanf("%d%d%d%d",&c,&d,&c2,&d2);
		if (d==0&&d2==0)
		{
			s=false;
			for (ii=h[c];ii!=0;ii=e[ii].n)
			 if (e[ii].t==c2) {s=true; break;}
			if (s) {printf("-1\n"); continue;}
		}
		mt[c]=d;
		mt[c2]=d2;
		memset(dp,0x3F,sizeof(dp));
		treedp(1,1);
		printf("%d\n",min(dp[1][0],dp[1][1]));
		memset(mt,-1,sizeof(mt));
	}
	return 0;
}
