#include<cstdio>
#include<cstring>
using namespace std;
struct node{
	int next,point;
}r[200001];int last[100001];
long long f[100001][2];
int deep[100001],ft[100001];
int a[100001],n,m;
int xa,xb,ya,yb;
void link(int x,int y,int k) {r[k].next=last[x];r[k].point=y;last[x]=k;}
int min(int x,int y) {return x<y?x:y;}
void dg(int k)
{
	int flag=true;
	for (int i=last[k];i;i=r[i].next)
	if (!deep[r[i].point])
	{
		deep[r[i].point]=deep[k]+1;
		ft[r[i].point]=k;flag=false;
		dg(r[i].point);
	}
	if (flag)
	{
		if (k!=xa&&k!=ya)
		{
			f[ft[k]][1]=min(f[ft[k]][1],a[ft[k]]);
		}
		else if (k==xa&&(!xb)||k==ya&&(!yb)) f[ft[k]][1]=a[ft[k]];
		if (k!=xa&&k!=ya)
		{
			f[ft[k]][0]=min(f[ft[k]][0],a[k]);
			f[ft[k]][1]=min(f[ft[k]][1],a[k]+a[ft[k]]);
		}
		else if (k==xa&&(xb)||k==ya&&(yb))
		{
			f[ft[k]][0]=a[k];
			f[ft[k]][1]=a[k]+a[ft[k]];
		}
	}
	else
	{
		if (k!=xa&&k!=ya)
		{
			f[ft[k]][1]=min(f[ft[k]][1],f[k][0]+a[ft[k]]);
		}
		else if (k==xa&&(!xb)||k==ya&&(!yb))
		{
			f[ft[k]][1]=f[k][0]+a[ft[k]];
		}
		if (k!=xa&&k!=ya)
		{
			f[ft[k]][0]=min(f[ft[k]][0],f[k][1]+a[k]);
			f[ft[k]][1]=min(f[ft[k]][1],f[k][1]+a[ft[k]]);
		}
		else if (k==xa&&(xb)||k==ya&&(yb))
		{
			f[ft[k]][0]=f[k][1]+a[k];
			f[ft[k]][1]=f[k][1]+a[ft[k]];
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int x,y;
	scanf("%d%d",&n,&m);
	getchar();getchar();getchar();
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) scanf("%d%d",&x,&y),link(x,y,i),link(y,x,i+n);
	for (int i=1;i<=m;i++)
	{
		memset(deep,0,sizeof(deep));
		memset(f,100,sizeof(f));
		scanf("%d%d%d%d",&xa,&xb,&ya,&yb);
		deep[1]=1;ft[1]=0;dg(1);
		printf("%d\n",min(f[1][0],f[1][1]));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
