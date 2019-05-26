#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	int mx=0;
	fo(i,1,n) scanf("%d",&a[i]);
	fd(i,n,1) a[i]-=a[i-1];
	int ans=0;
	fo(i,1,n) if(a[i]>0) ans+=a[i];
	printf("%d",ans); 
}
