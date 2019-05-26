#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e5+5;
int n,top,sum;
int a[N],g[N],ans[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[i]);
	fo(i,1,n){
		while(a[i]<g[top])top--;
		ans[i]=g[top];
		g[++top]=a[i];
	}
	top=0;
	fd(i,n,1){
		while(a[i]<=g[top]&&top)top--;
		ans[i]=max(ans[i],g[top]);
		g[++top]=a[i];
	}
	fo(i,1,n)sum=sum+a[i]-ans[i];
	printf("%d\n",sum);
}
