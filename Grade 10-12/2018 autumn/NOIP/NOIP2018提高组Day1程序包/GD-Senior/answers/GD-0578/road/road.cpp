#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define N 101000
using namespace std;
int n,a[N],las[N],nxt[N],to[N],tot=0,ans=0,m;
void putin(int x,int y)
{
	nxt[++tot]=las[x];las[x]=tot;to[tot]=y;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;scanf("%d",&n);
	fo(i,1,n)
	{
		int x;scanf("%d",&x);
		if(x!=a[m]) a[++m]=x,putin(a[m],m);
	}
	a[0]=a[n+1]=0;
	int w=1;
	fo(i,0,10000)
	{
		for(int j=las[i];j;j=nxt[j])
		{
			int k=to[j];
			if(a[k-1]>i&&a[k+1]>i) w++;
			if(a[k-1]<=i&&a[k+1]<i) w--;
		}
		ans+=w;
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
