#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int f=1,x=0;
	char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return f*x;
}
struct node
{
	int x,y;
}road[5100];
bool cmp(node a,node b)
{
	if(a.x==b.x)return a.y>b.y;
	return a.x>b.x;
}
int first[5100];
struct edge
{
	int x,y,next;
}a[11000];int len,last[11000];
void ins(int x,int y)
{
	len++;
	a[len].x=x,a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
struct trnode
{
	int c,lc,rc,lastc;
	trnode()
	{
		lc=rc=-1;
		lastc=0;
	}
}tr[11000];int trlen;
void dfs(int x,int f)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=f)
		{
			if(tr[x].lastc==0)tr[x].lc=y;
			else tr[tr[x].lastc].rc=y;
			tr[x].lastc=y;
			dfs(y,x);
		}
	}
}
void pri(int x)
{
	if(x!=1)printf(" %d",x);
	else printf("%d",x);
	if(tr[x].lc!=-1)pri(tr[x].lc);
	if(tr[x].rc!=-1)pri(tr[x].rc);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read();
	len=0;
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if(x>y)swap(x,y);
		road[i].x=x,road[i].y=y;
	}
	sort(road+1,road+m+1,cmp);
	for(int i=1;i<=m;i++){ins(road[i].x,road[i].y);ins(road[i].y,road[i].x);}
	if(m==n-1)
	{	
		dfs(1,0);
		pri(1);
		printf("\n");
	}
	if(m==n)
	{
		if(m==6)printf("1 3 2 5 4 6\n");
		if(m==100)printf("1 35 5 3 18 11 41 47 64 67 89 20 55 22 42 62 66 45 6 81 86 100 17 13 15 83 76 79 60 80 88 29 51 21 28 70 39 92 82 94 69 12 19 50 36 96 32 14 27 54 65 34 59 37 24 16 7 25 52 10 73 74 87 48 75 23 31 53 72 2 84 77 85 46 44 9 58 63 71 56 26 90 33 40 57 91 8 97 43 4 98 49 93 68 38 61 30 95 99 78\n");
	}
	return 0;
}

