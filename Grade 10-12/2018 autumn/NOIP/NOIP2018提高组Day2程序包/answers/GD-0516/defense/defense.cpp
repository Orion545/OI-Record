#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,from,to,a,b,x,y,limit,t[100500];
long long f[100500][2],p[100500];
vector<int> g[100500];
int fa[100500];
bool e[100500],hhh;
char ord[10];
void dfs_Init(int num)
{
  //printf("%d\n",num);
  e[num]=1;
  for (int i=0;i<g[num].size();i++)
   if (e[g[num][i]])fa[num]=g[num][i];
   else dfs_Init(g[num][i]);
}
bool dfs(int num)
{
  //printf(" %d\n",num);
  bool flag=(num==x||num==y||limit==0);
  for (int i=0;i<g[num].size();i++)
   if (g[num][i]!=fa[num]&&t[g[num][i]]==limit)
    flag|=dfs(g[num][i]);
  if (!flag)return 0;
  //printf(" %d\n",num);
  long long s0=f[num][0],s1=f[num][1];
  f[num][0]=0;
  f[num][1]=p[num];
  for (int i=0,tmp;i<g[num].size();i++)
   if ((tmp=g[num][i])!=fa[num]){
   	 f[num][1]+=min(f[tmp][1],f[tmp][0]);
   	 f[num][0]+=f[tmp][1];
   }
  if (num==x&&hhh)f[num][!a]=1ll<<55;
  if (num==y&&hhh)f[num][!b]=1ll<<55;
  if (s0==f[num][0]&&s1==f[num][1])return 0;
  return 1;
}
int main()
{
  freopen("defense.in","r",stdin);
  freopen("defense.out","w",stdout);
  scanf("%d%d%s",&n,&m,ord);
  for (int i=1;i<=n;i++)
   scanf("%lld",&p[i]);
  for (int i=1;i<n;i++){
  	scanf("%d%d",&from,&to);
  	g[from].push_back(to);
    g[to].push_back(from);
  }dfs_Init(1);
  dfs(1);
  for (int i=1;i<=m;i++){
  	scanf("%d%d%d%d",&x,&a,&y,&b);
    t[1]=limit=i;
  	int tmp=x;
  	while(fa[tmp]){
  	  t[tmp]=i;
  	  tmp=fa[tmp];
    }tmp=y;
  	while(fa[tmp]){
  	  t[tmp]=i;
  	  tmp=fa[tmp];
    }hhh=1;dfs(1);
  	long long ans=min(f[1][0],f[1][1]);
	printf("%lld\n",ans>1ll<<50 ? -1 : ans);
  	hhh=0;dfs(1);
  }return 0;
}
