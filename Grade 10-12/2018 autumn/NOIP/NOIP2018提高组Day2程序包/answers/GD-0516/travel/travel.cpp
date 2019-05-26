#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,from,to,tn,limit,cnt,
    ans[5050],t[5050];
struct Line
{int to,r;};
bool cmp(Line A,Line B)
{return A.to<B.to;}
vector<Line> g[5050];
bool e[5050];
char flag;
void dfss(int num)
{
  if (e[num])return ;
  ans[++tn]=num;
  e[num]=1;
  for (int i=0;i<g[num].size();i++)
   dfss(g[num][i].to);
}
void dfs(int num)
{
  if (e[num]||flag==2)return ;
  //printf("%d\n",num);
  t[++tn]=num;
  if (num<ans[tn])flag=1;
  if (num>ans[tn]&&!flag){
  	flag=2;
  	return ;
  }e[num]=1;
  for (int i=0;i<g[num].size();i++)
   if (g[num][i].r!=limit)
    dfs(g[num][i].to);
}
void addLine(int from,int to,int cnt)
{
  g[from].push_back((Line){to,cnt});
  g[to].push_back((Line){from,cnt});
}
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (int i=1;i<=m;i++){
  	scanf("%d%d",&from,&to);
  	addLine(from,to,i);
  }for (int i=1;i<=n;i++)
  	sort(g[i].begin(),g[i].end(),cmp);
  if (m==n-1)
  	dfss(1);
  else{
  	ans[1]=2;
  	for (int i=1;i<=n;i++){
  	  for (int j=1;j<=n;j++)e[j]=0;
	  flag=0;tn=0;limit=i;
  	  dfs(1);
  	  if (flag==1&&tn==n)
  	   for (int j=1;j<=n;j++)
  	  	ans[j]=t[j];
  	 // printf("--=%d\n",tn);
  	}
  }
  for (int i=1;i<=n;i++)
   printf("%d ",ans[i]);
  return 0;
}
