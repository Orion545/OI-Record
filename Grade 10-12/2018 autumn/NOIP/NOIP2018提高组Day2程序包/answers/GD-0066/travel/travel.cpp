#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5010;
struct soren
{
	int n,t,w;	
};
int a,b,c,d,p,i,tot,nm[10];
int ans[maxn];
bool s[maxn],map[maxn][maxn];
void dfs(int u)
{
	int j;
	s[u]=false;
	tot++;
	ans[tot]=u;
	for (j=1;j<=a;j++)
	 if (map[u][j]&&s[j]) dfs(j); 
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&a,&b);
	memset(map,false,sizeof(map));
	for (i=1;i<=b;i++)
	{
		scanf("%d%d",&c,&d);
		map[c][d]=true;
		map[d][c]=true;
	}
	memset(s,true,sizeof(s));
	dfs(1);
	for (i=1;i<=a;i++)
	 printf("%d ",ans[i]);
	return 0;
}
