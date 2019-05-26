#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n,m,cnt=0,ch[10000];
int f[10000],vis[10000];
vector <int> map[10000];
void dfs(int num)
{
	if (ch[num]==0)
	{
		ch[num]=1;	
		f[++cnt]=num;
	}
	int len=map[num].size();
	for (int i=0;i<len;i++)
	{
		if (vis[map[num][i]]==0)
		{
			vis[map[num][i]]=1;
			dfs(map[num][i]);
			vis[map[num][i]]=0;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	for (int i=1;i<=n;i++) f[i]=1e9;
	for (int i=1;i<=n;i++)
	{
		int len=map[i].size();
		for (int j=0;j<len;j++)
			for (int k=0;k<len;k++)
				if (map[i][k]>map[i][j])
				{
					int temp=map[i][k];
					map[i][k]=map[i][j];
					map[i][j]=temp;
				}
	}
	vis[1]=1;
	dfs(1);
	for (int i=1;i<=n;i++) printf("%d ",f[i]);
	printf("\n");
	return 0;
}
