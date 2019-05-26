#include <cstdio>
#include <algorithm>
#include <cstring>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;

const int A=25000;
int T,i,j,n,m,a[101];
bool f[A+1];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n); m=n;
		fo(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		memset(f,0,sizeof f);
		f[0]=1;
		fo(i,1,n)
		{
			if(f[a[i]]) {m--;continue;}
			fo(j,0,A-a[i]) f[j+a[i]]|=f[j];		
		}
		printf("%d\n",m);
	}
}
