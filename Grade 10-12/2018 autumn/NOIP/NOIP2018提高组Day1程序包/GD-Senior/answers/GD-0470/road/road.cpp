#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100050],tr[400050],tre[400050],xx;
int finds(int k,int l,int r,int x,int y)
{
	if(y<l||r<x)return 0;
	if(x<=l&&r<=y)return tre[k];
	int mid=(l+r)/2;
	int k1=finds(k+k,l,mid,x,y),k2=finds(k+k+1,mid+1,r,x,y);
	if(k1==0)return k2;
	if(k2==0)return k1;
	if(a[k1]<=a[k2])return k1;else return k2;
}
int work(int l,int r,int k)
{
	if(l>r)return 0;
	int p=finds(1,1,xx,l,r);
	int sum=a[p]-k;
	sum+=work(l,p-1,a[p])+work(p+1,r,a[p]);
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	xx=1;while(xx<n)xx+=xx;
	for(int i=1;i<=n;i++)tr[i+xx-1]=a[i],tre[i+xx-1]=i;
	for(int i=xx-1;i>0;i--)
	{
		tr[i]=min(tr[i+i],tr[i+i+1]);
		if(tr[i+i]>tr[i+i+1])tre[i]=tre[i+i+1];else tre[i]=tre[i+i];
	}
	int ans=work(1,n,0);
	printf("%d",ans);
	return 0;
}