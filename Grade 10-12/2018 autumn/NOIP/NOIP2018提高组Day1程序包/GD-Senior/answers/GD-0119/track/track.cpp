#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{int v,fr,l;}e[100010];
int tail[50010],len[50010],n,m,cnt=0,ans=0;
int have[50010],sy;
bool bz[50010];

void add(int u,int v,int l) {e[++cnt]=(node){v,tail[u],l}; tail[u]=cnt;}

void dfs_mb(int x,int fa,int div)
{
	for (int p=tail[x];p;p=e[p].fr)
		if (e[p].v!=fa)
		{
			len[e[p].v]+=e[p].l,dfs_mb(e[p].v,x,div);
			sy+=len[e[p].v]/div;len[e[p].v]%=div;
		}
	int tot=0;
	for (int p=tail[x];p;p=e[p].fr)
		if (e[p].v!=fa && len[e[p].v]) have[++tot]=len[e[p].v];
	sort(have+1,have+tot+1);
	memset(bz,0,tot+1);
	int zd=0;
	for (int i=tot;i>0;i--)
		if (!bz[i])
		{
			int z=1,y=i-1,mi,ok=tot+1;
			while (z<=y)
			{
				mi=z+y>>1;
				if (have[mi]+have[i]>=div) ok=mi,y=mi-1;
				else z=mi+1;
			}
			while (bz[ok] && ok<=tot) ok++;
			if (ok<=tot) sy++,bz[ok]=1;
			else if (have[i]>zd) zd=have[i];
		}
	len[x]+=zd;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int le=1,r=0,mid;
	for (int i=1,a,b,l;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&l);r+=l;
		add(a,b,l),add(b,a,l);
	}
	while (le<=r)
	{
		mid=le+r>>1;sy=0;
		memset(len,0,sizeof(len));
		dfs_mb(1,0,mid);
		if (sy>=m) ans=mid,le=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
