#include<cstdio>
#define N 100001
using namespace std;
int total1,next[N*2],head[N*2],edge[N*2];
int f[N][3],p[N];
int n,m;
char ch[10001];
void insert(int x,int y)
{
	total1++;
	next[total1]=head[x];
	head[x]=total1;
	edge[total1]=y;
}
void dg(int k,int father,int p1,int p2,int q1,int q2)
{
	for (int i=head[k];i;i=next[i])
	{
		int y=edge[i];
		if (y!=father)
		{
			dg(y,k,p1,p2,q1,q2);
			if (f[y][0]<f[y][1])
			{
				if (f[y][0]<9999999)
					f[k][1]+=f[y][0];
			}
			else
				if (f[y][1]<9999999)
					f[k][1]+=f[y][1];
			if (f[y][1]<9999999)
				f[k][0]+=f[y][1];
		}
	}
	bool bo=false;
	for (int j=head[k];j;j=next[j])
		{
			int y1=edge[j];
			if ((y1==p1&&p2==0)||(y1==q1&&q1==0))
			{
				bo=true;
				break;
			}
		}
	f[k][1]+=p[k];
	if (p1==k)
	{
		if (p2==0) f[k][1]=9999999;
		else	f[k][0]=9999999;
	}
	if (q1==k)
	{
		if (q2==0) f[k][1]=9999999;
		else	f[k][0]=9999999;
	}
	if (bo) f[k][0]=999999;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",&ch);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	for (int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		insert(x,y);
		insert(y,x);
	}
	for (int i=1;i<=m;i++)
	{
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		for (int j=1;j<=n;j++)
		{
			f[j][0]=0;
			f[j][1]=0;
		}
		bool bo=false;
		if (x==0)
		for (int j=head[a];j;j=next[j])
		{
			int y1=edge[j];
			if (b==y1&&y==0)
			{
				bo=true;
				break;
			}
		}
		if (bo) 
		{
			printf("-1\n");
			continue;
		}
		dg(1,0,a,x,b,y);
		bo=false;
		for (int j=head[1];j;j=next[j])
		{
			int y1=edge[j];
			if ((y1==a&&x==0)||(y1==b&&y==0))
			{
				bo=true;
				break;
			}
		}
		if (bo)
		{
			printf("%d\n",f[1][1]);
			continue;
		}
		if (f[1][0]<f[1][1])
		printf("%d\n",f[1][0]);
		else printf("%d\n",f[1][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
