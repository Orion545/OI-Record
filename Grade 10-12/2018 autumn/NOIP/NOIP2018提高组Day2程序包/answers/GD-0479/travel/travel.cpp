#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=2e9;
bool vis[5005];
int knw[5005];
int ccnt=0;
vector<int> a[5005];
bool cmp(const int& x,const int& y)
{
	return x<y;
}
void dfs(int u,int fa)
{
	int cnt=0;
	int knw[5005];
	printf("%d ",u);
	for(int i=0;i<a[u].size();i++)
	{
		cnt++;
		knw[cnt]=a[u][i];
	}
	sort(knw+1,knw+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(knw[i]!=fa&&!vis[knw[i]])
		{
			vis[knw[i]]=true;
			dfs(knw[i],u);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	int ti;
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vis[1]=true;
	if(m!=n) dfs(1,1);
	if(m==n)
	{
		int tt=n;
		int curr=1;
		for(int j=1;j<=n;j++)
		{
			printf("%d ",curr);
			for(int i=0;i<a[curr].size();i++)
			{
				if(!vis[a[curr][i]])
				{
					ccnt++;
					knw[ccnt]=a[curr][i];
					vis[a[curr][i]]=true;
				}
			}
			curr=INF;
			for(int i=1;i<=ccnt;i++)
			{
				if(knw[i]<curr) 
				{
					ti=i;
					curr=knw[i];
				}
			}
			if(j!=n)
			{
				knw[ti]=INF;
			}
		}
	}
	return 0;
}
