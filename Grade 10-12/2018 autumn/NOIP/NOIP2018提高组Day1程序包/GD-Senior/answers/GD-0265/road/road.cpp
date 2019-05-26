#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100001],minn;
inline int fix(int l,int r)
{
	if(l>r) return 0;
	int minn=1e5+1,res,lst=l-1;
	for(int i=l;i<=r;i++) minn=min(minn,a[i]);
	res=minn;
	for(int i=l;i<=r;i++)
	{
		a[i]-=minn;
		if(!a[i])
		{
			res+=fix(lst+1,i-1);
			lst=i;
		}
	}
	return res+fix(lst+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d",fix(1,n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
