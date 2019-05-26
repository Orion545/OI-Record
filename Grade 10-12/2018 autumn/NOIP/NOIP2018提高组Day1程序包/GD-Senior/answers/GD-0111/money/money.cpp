#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define max(a,b) (a>b?a:b)
using namespace std;

int a[101];
int A[101];
bool f[25001];
int T,n,i,j,k,l,ans,Max;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	for (;T;T--)
	{
		Max=0;
		scanf("%d",&n);
		fo(i,1,n)
		scanf("%d",&a[i]),Max=max(Max,a[i]);
		
		sort(a+1,a+n+1);
		
		memset(f,0,sizeof(f));
		ans=0;
		f[0]=1;
		fo(i,1,n)
		if (!f[a[i]])
		{
			++ans;
			
			fo(j,0,Max-a[i])
			if (f[j])
			f[j+a[i]]=1;
		}
		
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
