#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
using namespace std;

struct B{
	int x,y,id;
} b[10001];
int a[10001][3];
int ls[5001];
int ans[5001];
int now[5001];
bool bz[5001];
int n,m,i,j,k,l,len,del,tot;

bool cmp(B a,B b)
{
	return a.x<b.x || a.x==b.x && a.y>b.y;
}

void pd()
{
	int i;
	bool bz=0;
	
	fo(i,1,n)
	if (ans[i]>now[i])
	{
		bz=1;
		break;
	}
	else
	if (ans[i]<now[i])
	return;
	
	if (bz)
	{
		fo(i,1,n)
		ans[i]=now[i];
	}
}

void New(int x,int y,int z)
{
	++len;
	a[len][0]=y;
	a[len][1]=ls[x];
	a[len][2]=z;
	ls[x]=len;
}

void dfs(int t)
{
	int i;
	
	bz[t]=1;
	now[++tot]=t;
	
	for (i=ls[t]; i; i=a[i][1])
	if (!bz[a[i][0]] && a[i][2]!=del)
	dfs(a[i][0]);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	l=0;
	fo(i,1,m)
	{
		scanf("%d%d",&j,&k);
		++l;
		b[l].x=j;
		b[l].y=k;
		b[l].id=i;
		++l;
		b[l].x=k;
		b[l].y=j;
		b[l].id=i;
	}
	
	sort(b+1,b+l+1,cmp);
	fo(i,1,l)
	New(b[i].x,b[i].y,b[i].id);
	
	ans[1]=n+1;
	
	if (m==n)
	{
		fo(del,1,m)
		{
			memset(bz,0,sizeof(bz));
			tot=0;
			dfs(1);
			
			if (tot==n)
			pd();
		}
	}
	else
	del=-1,dfs(1),pd();
	
	printf("%d",ans[1]);
	fo(i,2,n)
	printf(" %d",ans[i]);
	printf("\n");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
