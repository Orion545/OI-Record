#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=50010;
int n,m,x,y,z;
struct path{int y,nxt,w;}g[N<<1];int h[N];
int lst,len[N],f[1010][1010];
int MID;
int son[1010],sz[1010],idw[1010];
void dfs1(int x,int fa)
{sz[x]=1;
	for (int i=h[x];i;i=g[i].nxt) 
	if (g[i].y!=fa){ idw[g[i].y]=g[i].w;dfs1(g[i].y,x);sz[x]+=sz[g[i].y];if (sz[g[i].y]>sz[son[x]]) son[x]=g[i].y;	
	}
}
int t[1010];
void dp(int x,int fa)
{
	if (son[x]) 
	{dp(son[x],x);memcpy(f[x],f[son[x]],sizeof(f[son[x]]));len[x]=len[son[x]];
	for (int i=0;i<=len[son[x]];i++) f[x][i]+=idw[son[x]];if (f[x][len[x]]>MID) len[x]++;}
	for (int i=h[x];i;i=g[i].nxt)
	if (g[i].y!=fa&&g[i].y!=son[x])
	{
		dp(g[i].y,x);
		int mxl=len[x];
		memcpy(t,f[x],sizeof(f[x]));
		for (int j=0;j<=len[g[i].y];j++)
		{
			for (int k=0;k<=len[x];k++)
			{
				t[j+k]=max(f[x][j+k],max(f[x][k],f[g[i].y][j]+idw[g[i].y]));
				if (f[x][k]+f[g[i].y][j]+idw[g[i].y]>=MID) mxl=max(mxl,j+k+1); 
			}
		}
		memcpy(f[x],t,sizeof(t));len[x]=mxl;
	}
}
bool bo1,bo2,bo3;
int ans,id,id1;
void dfs_1(int x,int f,int c)
{
	if (c>ans) ans=c,id=x;
	for (int i=h[x];i;i=g[i].nxt)
	if (g[i].y!=f) dfs_1(g[i].y,x,c+g[i].w);
}
void work_1()
{
	ans=id=0;dfs_1(1,0,0);
	id1=id;ans=id=0;dfs_1(id1,0,0);
	printf("%d\n",ans);
}
bool cmp_2(path a,path b)
{return a.w==b.w?a.y<b.y:a.w<b.w;}
int cnt_2;
bool query_2(int mid)
{
	cnt_2=0;
	for (int i=n-1,j=0;i>j;i--)
	{
		while (g[i*2].w+g[j*2].w<mid) j++;
		if (j<i) j++,cnt_2++;
	} if (cnt_2>=m) return 1;return 0;
}
void work_2()
{
	sort(g+1,g+n*2-1,cmp_2);
	int L,R,mid,ret;L=0;R=5e8;ret=0;
	while (L<=R)
	{
		mid=L+R>>1;
		if (query_2(mid)) L=mid+1,ret=mid;else R=mid-1;
	}
	printf("%d\n",ret);
}
int cnt_3,val_3;
bool query_3(int mid)
{
	cnt_3=val_3=0;
	for (int i=1;i<n;i++) 
	{
		for (int j=h[i];j;j=g[j].nxt) 
		if (g[j].y==i+1)
		{
			if (val_3+g[j].w>=mid) cnt_3++,val_3=0; else val_3+=g[j].w;
		}
	}
	if (val_3>=mid) cnt_3++;if (cnt_3>=m) return 1;return 0;
}
void work_3()
{
	int L,R,mid,ret;L=0;R=5e8;ret=0;
	while (L<=R)
	{
		mid=L+R>>1;
		if (query_3(mid)) L=mid+1,ret=mid;else R=mid-1;
	}
	printf("%d\n",ret);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);if (m==1) bo1=1;bo2=bo3=1;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if (y!=x+1) bo3=0;
		if (x!=1&&y!=1) bo2=0;
		g[i*2-1]=path{y,h[x],z};h[x]=i*2-1;
		g[i*2]=path{x,h[y],z};h[y]=i*2;
	}
	if (bo1==1)
	{work_1();return 0;}
	if (bo2==1)
	{work_2();return 0;}
	if (bo3==1)
	{work_3();return 0;}
	dfs1(1,0);
	int L,R,ret=0;L=0;R=5e8;
	while (L<=R)
	{MID=L+R>>1;memset(len,0,sizeof(len));
	dp(1,0);
	if (len[1]>=m) ret=MID,L=MID+1;else R=MID-1;}
	cout<<ret;
	return 0;
}
