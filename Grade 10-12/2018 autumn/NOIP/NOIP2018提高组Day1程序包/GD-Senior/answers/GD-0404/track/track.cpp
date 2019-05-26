#include<cstdio>
#include<cstring>
#define N 50011
using namespace std;
int next[N*2],head[N*2],edge[N*2],v[N*2];
int p[N],flow[N],total1=0,total,n,m;
bool bz[N],bp[N];
void insert(int x,int y,int z)
{
	total1++;
	next[total1]=head[x];
	head[x]=total1;
	edge[total1]=y;
	v[total1]=z;
}
void qsort(int l,int r)
{
	int i=l,j=r;
	int mid=p[(i+j)/2];
	while (i<=j)
	{
		while (p[i]<mid) i++;
		while (p[j]>mid) j--;
		if (i<=j)
		{
			int t=p[i];
			p[i]=p[j];
			p[j]=t;
			i++;
			j--;
		}
	}
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
}
void find(int k,int s,int father)
{
	int number=0;
	for (int i=head[k];i;i=next[i])
	{
		int y=edge[i];
		if (bp[y]==false)
		{
			bp[y]=true;
			find(y,s,k);
		}
	}
	for (int i=head[k];i;i=next[i])
	{
		int y=edge[i];
		if (y!=father)
		{
			number++;
			p[number]=flow[y]+v[i];
		}
	}
	qsort(1,number);
	memset(bz,false,sizeof(bz));
	int ans=number+1;
	while (number>=1&&p[number]>=s)
	{
		number--;
		total++;
	}
	for (int i=1;i<=number;i++)
	{
		if (bz[i]==true) continue;
		int l=i+1,r=number;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (p[mid]+p[i]>=s)
			{
				ans=mid;
				r=mid-1;
			}
			else
				l=mid+1;
		}
		while (bz[ans]==true&&ans<=number) ans++;
		if (ans<=number)
		{
			total++;
			bz[i]=true;
			bz[ans]=true;
		}
	}
	for (int i=number;i>=1;i--)
	{
		if (bz[i]==false)
		{
			flow[k]=p[i];
			break;
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int r=0;
	for (int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		r+=z;
		insert(x,y,z);
		insert(y,x,z);
	}
	int l=0;
	int ans=0;
	while (l<=r)
	{
		int mid=(l+r)/2;
		total=0;
		memset(bp,false,sizeof(bz));
		bp[1]=true;
		memset(flow,0,sizeof(flow));
		find(1,mid,0);
		if (total>=m)
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
