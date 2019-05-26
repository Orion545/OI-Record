 #include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> g[50500],l[50500];
int n,m,f[50500],from,to,cnt,
    h[50500],c[50500],len,limit;
bool e[50500];
void addLine(int from,int to,int len)
{
  g[from].push_back(to);
  l[from].push_back(len);
  g[to].push_back(from);
  l[to].push_back(len);
}
void dfs_Init(int num)
{
  e[num]=1;
  for (int i=0;i<g[num].size();i++)
   if (e[g[num][i]])f[num]=g[num][i];
   else dfs_Init(g[num][i]);
}
void dfs(int num)
{
  //printf(" %d %d\n",num,f[num]);
  for (int i=0;i<g[num].size();i++)
   if (g[num][i]!=f[num])
   	 dfs(g[num][i]);
  int tn=0;
  for (int i=0;i<g[num].size();i++)
   if (g[num][i]!=f[num]){
   c[++tn]=h[g[num][i]]+l[num][i];}
  if (tn==0){
  	h[num]=0;
  	return ;
  }sort(c+1,c+tn+1);
  //printf("- %d %d\n",c[num].size(),num);
  
  int last,tmp;
while(1){
  last=cnt;
  for (int i=1;i<=tn;i++)e[i]=0;
  int l=1,r=tn;
  while(r&&c[r]>=limit)
   {e[r]=1;r--;cnt++;}
  while(l<r){
    while(c[l]+c[r]<limit&&l<r)l++;
    while(c[l]+c[r-1]>=limit&&l<r-1)r--;
    if (c[l]+c[r]>=limit&&l<r){
	  e[l]=e[r]=1;
      l++;r--;cnt++;
    }
  }if (cnt==last)break;
  tmp=0;
  for (int i=1;i<=tn;i++)
   if (!e[i])c[++tmp]=c[i];
  tn=tmp;
} int maxx=0;
  for (int i=1;i<=tn;i++)
   if (!e[i])maxx=max(maxx,c[i]);
  h[num]=maxx;
}
bool check()
{
  cnt=0;
  dfs(1);
  //printf("!!!%d\n",cnt);
  if (cnt>=m)return 1;
  return 0;
}
int main()
{
  freopen("track.in","r",stdin);
  freopen("track.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (int RP=1;RP<n;RP++){
  	scanf("%d%d%d",&from,&to,&len);
  	addLine(from,to,len);
  }dfs_Init(1);
  //printf("%lld\n",limit);
  int l=0,r=1<<30;
  while(l<r){
    limit=(l+r+1)>>1;
    //printf("%lld\n",limit);
    if (check())l=limit;
    else r=limit-1;
  }printf("%d\n",l);
  return 0;
}
