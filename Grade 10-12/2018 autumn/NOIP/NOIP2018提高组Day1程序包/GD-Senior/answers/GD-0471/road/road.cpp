#include<cstdio>
using namespace std;
int a[100002],b[100002],c[100002],ft[100002],n;
void qsort(int l,int r)
{
	int i=l,j=r,mid=b[(l+r)/2],h;
	while (i<=j)
	{
		while (b[i]>mid) i++;
		while (b[j]<mid) j--;
		if (i<=j)
		{
			h=b[i];b[i]=b[j];b[j]=h;
			h=c[i];c[i]=c[j];c[j]=h;
			i++;j--;
		}
	}
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
	return;
}
int getfather(int k)
{
	if (k<=0||k>n||ft[k]==0) return 0;
	if (ft[k]==k) return k;
	int x=getfather(ft[k]);
	ft[k]=x;return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i],c[i]=i;
	int p=0,l=1;
	qsort(1,n);
	for (int i=10000;i>=1;i--)
	{
		while (b[l]==i)
		{
			int x=getfather(c[l]-1),y=getfather(c[l]+1);
			if (x&&y) ft[x]=ft[c[l]]=y,p--;
			else
			{
				if (x) ft[c[l]]=x;
				else if (y) ft[c[l]]=y;
				else ft[c[l]]=c[l],p++;
			}
			l++;
		}
		ans+=p;
		if (l>n)
		{
			ans+=i-1;
			break;
		}
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
