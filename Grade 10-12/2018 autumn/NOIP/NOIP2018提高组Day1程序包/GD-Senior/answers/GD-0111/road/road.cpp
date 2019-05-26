#include <iostream>
#include <cstdlib>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
using namespace std;

int d[100001];
int n,i,j,k,l,ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	
	l=0;
	fo(i,1,n) 
	{
		scanf("%d",&j);
		
		if (d[l]>=j)
		{
			ans+=(d[l]-j);
			while (l && d[l]>=j) l--;
		}
		d[++l]=j;
	}
	ans+=d[l];
	
	printf("%d\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
