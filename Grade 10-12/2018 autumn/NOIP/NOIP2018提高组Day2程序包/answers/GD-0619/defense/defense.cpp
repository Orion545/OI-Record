#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int x,y,next;
}a[210000];int len,last[110000];
inline void ins(int x,int y)
{
	len++;a[len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int aa,xx,bb,yy;
int p[110000];
int f[110000][3];
inline int mymin(int x,int y){return x<y?x:y;}
void treedp(int x,int fa)
{
	int sr=0;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)sr++,treedp(y,x);
	}
	f[x][0]=0;int z=0x3f3f3f3f;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)
		{
			z=mymin(z,f[y][1]-f[y][0]);
			f[x][0]+=mymin(f[y][1],f[y][0]);
			if(f[x][0]>0x3f3f3f3f)f[x][0]=0x3f3f3f3f;
		}
	}
	if(z>0)f[x][0]+=z;
	if(f[x][0]>0x3f3f3f3f)f[x][0]=0x3f3f3f3f;
	if((x==aa&&xx==1)||(x==bb&&yy==1))f[x][0]=0x3f3f3f3f;
	f[x][1]=p[x];
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)f[x][1]+=mymin(mymin(f[y][1],f[y][0]),f[y][2]);
		if(f[x][1]>0x3f3f3f3f)f[x][1]=0x3f3f3f3f;
	}
	if((x==aa&&xx==0)||(x==bb&&yy==0))f[x][1]=0x3f3f3f3f;
	f[x][2]=0;
	for(int k=last[x];k>0;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)f[x][2]+=f[y][0];
		if(f[x][2]>0x3f3f3f3f)f[x][2]=0x3f3f3f3f;
	}
	if((x==aa&&xx==1)||(x==bb&&yy==1)||sr>0)f[x][2]=0x3f3f3f3f;
}
char jmsq[111];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;scanf("%d%d%s",&n,&m,jmsq+1);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&aa,&xx,&bb,&yy);
		memset(f,-1,sizeof(f));
		treedp(1,0);
		int tt=mymin(f[1][0],f[1][1]);
		if(tt>=0x3f3f3f3f)tt=-1;
		printf("%d\n",tt);
	}
	return 0;
}
