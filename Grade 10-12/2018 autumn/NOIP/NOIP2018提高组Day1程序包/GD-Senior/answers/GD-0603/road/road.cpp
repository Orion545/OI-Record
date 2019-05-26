#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmin(a,b) (a=(a<b)?a:b)
#define cmax(a,b) (a=(a>b)?a:b)
using namespace std;
typedef long long ll;
typedef double db;
const int N=1e5+5;
int n,a[N],i,j,ans,f[20][N],Log[N],k;
int get(int x,int y)
{
	int z=Log[y-x+1];
	int b=f[z][x],c=f[z][y-(1<<z)+1];
	if (a[b]<a[c]) return b;
	return c;
}
void dfs(int l,int r,int ht)
{
	if (l>r) return ;
	int mn=get(l,r);
	ans=ans+a[mn]-ht;
	dfs(l,mn-1,a[mn]);
	dfs(mn+1,r,a[mn]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) 
	{
		scanf("%d",a+i);
		f[0][i]=i;
		Log[i]=trunc(log(i)/log(2));
	}
	fo(j,1,Log[n])
		fo(i,1,n-(1<<j)+1)
		{
			if (a[f[j-1][i]]<a[f[j-1][i+(1<<j-1)]]) k=i;else k=i+(1<<j-1);
			f[j][i]=f[j-1][k];
		}
	dfs(1,n,0);
	printf("%d",ans);
}
