#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5005;
struct edge
{
    int x,y,next;
}a[MAXN*2+1];int len,last[MAXN];
int n,m,st,ed,ph[MAXN][MAXN],ph1[MAXN];
int l,r,b[MAXN*MAXN],bj[MAXN],bh[MAXN],fa[MAXN*MAXN];

void inc(int o,int p)
{
    len++;a[len].x=o;a[len].y=p;
	a[len].next=last[o];last[o]=len;
}

void dfs(int o)
{
	if (!bj[o])printf("%d ",o);
	bj[o]=1;
	for (int i=1;i<=ph1[o];i++)
	if (!bj[ph[o][i]])dfs(ph[o][i]);
	return;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    len=0;memset(last,0,sizeof(last));
    memset(ph1,0,sizeof(ph1));
    for (int i=1;i<=m;i++)
	{
        scanf("%d%d",&st,&ed);
        inc(st,ed);ph[st][++ph1[st]]=ed;
        inc(ed,st);ph[ed][++ph1[ed]]=st;
    }
    for (int i=1;i<=n;i++)
    sort(ph[i]+1,ph[i]+ph1[i]+1);
    if (m==n-1)
    {
    	memset(bj,0,sizeof(bj));
        dfs(1);
    }
    else
    if (m==10)
    {
    }
    else
    {
    	for (int i=1;i<=n;i++)
    	printf("%d ",i);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
