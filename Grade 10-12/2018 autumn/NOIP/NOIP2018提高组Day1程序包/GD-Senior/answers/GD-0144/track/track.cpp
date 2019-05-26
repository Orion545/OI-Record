#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct jgt
{
	int c,to,next;
}qxx[100010];
int head[50010],f[50010],a[50010][2],n,m,temp=1;

int cmp(const void *a,const void *b)
{
	return ((int*)a)[0] - ((int*)b)[0];
}

void add(int x,int y,int z)
{
	qxx[temp].to=y;
	qxx[temp].c=z;
	qxx[temp].next=head[x];
	head[x]=temp++;
}

void dg(int k,int shang)
{
	for (int i=head[k];i;i=qxx[i].next)
	if (qxx[i].to!=shang)
	{
		f[qxx[i].to]=f[k]+qxx[i].c;
		dg(qxx[i].to,k);
	}
}

void M1()
{
	for (int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	
	dg(1,0);
	
	int mx=0,x;
	for (int i=1;i<=n;i++)
	if (f[i]>mx)
	{
		mx=f[i];
		x=i;
	}
	
	for (int i=1;i<=n;i++)
	f[i]=0;
	dg(x,0);
	
	for (int i=1;i<=n;i++)
	mx=max(mx,f[i]);
	
	printf("%d\n",mx);
}

bool pd(int k)
{
	int sum=0,p=0;
	for (int i=1;i<n;i++)
	{
		sum=sum+a[i][1];
		if (sum>=k)
		{
			p++;
			sum=0;
		}
	}
	
	if (p>=m) return true;
	return false;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	if (m==1)
	{
		M1();
		return 0;
	}
	
	for (int i=1;i<n;i++)
	{
		int x;
		scanf("%d%d%d",&a[i][0],&x,&a[i][1]);
	}
	
	
	qsort(a+1,n-1,sizeof(int)*2,cmp);
	
	int l=0,r=500000000,mid,ans;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (pd(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
