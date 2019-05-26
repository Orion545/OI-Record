#include<cstdio>
#include<cstring>
#define N 5012
using namespace std;
int p[N],h[N][N],ans[N],total[N],a[N],b[N];
int total1,number,n,m;
bool bz[N];
void qsort(int p,int l,int r)
{
	int i=l,j=r;
	int mid=h[p][(i+j)/2];
	while (i<=j)
	{
		while (h[p][i]<mid) i++;
		while (h[p][j]>mid) j--;
		if (i<=j)
		{
			int t=h[p][i];
			h[p][i]=h[p][j];
			h[p][j]=t;
			i++;
			j--;
		}
	}
	if (i<r) qsort(p,i,r);
	if (l<j) qsort(p,l,j);
}
void dg(int k,int father)
{
	number++;
	ans[number]=k;
	for (int i=1;i<=h[k][0];i++)
	{
		int y=h[k][i];
		if (bz[y]==false)
		{
			bz[y]=true;
			dg(y,k);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (m==n-1)
	{
		for (int i=1;i<=n-1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			h[x][0]++;
			h[x][h[x][0]]=y;
			h[y][0]++;
			h[y][h[y][0]]=x;
		}
		for (int i=1;i<=n;i++)
		{
			qsort(i,1,h[i][0]);
		}
		memset(ans,0,sizeof(ans));
		number=0;
		memset(bz,false,sizeof(bz));
		bz[1]=true;
		dg(1,0);
		for (int i=1;i<=n;i++)
		{
			printf("%d ",ans[i]);
		}
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		for (int i=1;i<=n;i++)
		{
			total[i]=9999999;
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				h[j][0]=0;
			}
			for (int j=1;j<=n;j++)
			{
				if (i==j) continue;
				h[a[j]][0]++;
				h[a[j]][h[a[j]][0]]=b[j];
				h[b[j]][0]++;
				h[b[j]][h[b[j]][0]]=a[j];
			}
			for (int i=1;i<=n;i++)
			{
				qsort(i,1,h[i][0]);
			}
			memset(ans,0,sizeof(ans));
			number=0;
			memset(bz,false,sizeof(bz));
			bz[1]=true;
			dg(1,0);
			if (number!=n) continue;
			bool bo=false;
			for (int j=1;j<=n;j++)
			{
				if (ans[j]<total[j])
				{
					bo=true;
					break;
				}
				if (ans[j]>total[j])
				{
					bo=false;
					break;
				}
			}
			if (bo==true)
			{
				for (int j=1;j<=n;j++)
				{
					total[j]=ans[j];
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			printf("%d ",total[i]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
