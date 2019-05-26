#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,n,m,x,y,bz,bz1;
int ans[5010],xx[5010],yy[5010];
struct CZC{int x,y,z;}edg[10010];
bool cmp(CZC a,CZC b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
int dfs(int p,int q)
{
	++ans[0];
	if(!bz)
	{
		if(ans[ans[0]]<p)
		{
			bz1=1;
			return 0;
		}
		if(ans[ans[0]]>p)
		{
			bz=1;
			ans[ans[0]]=p;
		}
	}
	else ans[ans[0]]=p;
	for(int i=xx[p];i<=yy[p]&&bz1==0;++i)
		if(edg[i].z!=x&&edg[i].y!=q) dfs(edg[i].y,p);
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m<n)
	{
		m=0;
		for(i=1;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			++m;
			edg[m].x=x,edg[m].y=y;
			++m;
			edg[m].x=y,edg[m].y=x;
		}
		stable_sort(edg+1,edg+m+1,cmp);
		xx[1]=j=1,yy[n]=m;
		for(i=2;i<=m;++i)
			if(edg[i].x^edg[i-1].x)
			{
				yy[j]=i-1;
				xx[++j]=i;
			}
		bz=1,x=-1,dfs(1,0);
	}
	else
	{
		m=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d%d",&x,&y);
			++m;
			edg[m].x=x,edg[m].y=y,edg[m].z=i;
			++m;
			edg[m].x=y,edg[m].y=x,edg[m].z=i;
			ans[i]=10000;
		}
		stable_sort(edg+1,edg+m+1,cmp);
		xx[1]=j=1,yy[n]=m;
		for(i=2;i<=m;++i)
			if(edg[i].x^edg[i-1].x)
			{
				yy[j]=i-1;
				xx[++j]=i;
			}	
		for(i=1;i<=n;++i)
		{
			x=i;
			ans[0]=bz=bz1=0;
			dfs(1,0);
		}
	}
	for(i=1;i<n;++i) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
