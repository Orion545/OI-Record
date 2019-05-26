#include<cstdio>
#include<algorithm>
using namespace std;


int n;
int a[1000100];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
	int cnt=n,ans=0,u=0;
	while(cnt&&u++<20)
	{
		int l=0,r=0;
		while(r<n)
		{
			while(!a[r+1]&&r<n)
			r++;
			if(r<n) r++;
			else break;
			l=r;
			
			while(a[r+1]&&r<n)
			r++;
		
			int minn=2e9;
			for(int i=l;i<=r;i++)
			minn=min(a[i],minn);
			for(int i=l;i<=r;i++)
			{
				a[i]-=minn;
				if(a[i]==0)
				cnt--;
			}
			
			ans+=minn;
		}
	}
	
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
