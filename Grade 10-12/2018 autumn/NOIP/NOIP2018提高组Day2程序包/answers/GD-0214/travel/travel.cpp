#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char ch;
void read(int&n)
{
	for(ch=getchar();ch<'0' || ch>'9';ch=getchar());
	for(n=0;'0'<=ch && ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
}
const int N=5003;
struct node
{
	int x,y;
}a[N*2];
bool cmp(node a,node b)
{
	return a.x<b.x || (a.x==b.x && a.y>b.y);
}
int n,m,nxt[N*2],to[N*2],fa[N],lst[N],tot;
int b[N],ans[N],id,xx,yy;
bool bz[N];
void write(int x){if(x>9)write(x/10);putchar(x%10+48);}
bool ok(int x,int y)
{
	if(x>y)swap(x,y);
	return (xx^x)||(yy^y);
}
void dfs(int x)
{
	bz[b[++id]=x]=0;
	for(int i=lst[x];i;i=nxt[i])
		if((to[i]^fa[x]) && ok(x,to[i]) && bz[to[i]])fa[to[i]]=x,dfs(to[i]);
}
void ins(int x,int y)
{
	nxt[++tot]=lst[x];
	to[tot]=y;lst[x]=tot;
}
bool pd()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]>ans[i])return 0;
		if(b[i]<ans[i])return 1;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++)
		read(a[i].x),read(a[i].y),
		a[i+m].x=a[i].y,a[i+m].y=a[i].x;
	sort(a+1,a+1+m+m,cmp);
	memset(lst,0,sizeof(lst));
	for(int i=1;i<=m+m;i++)
		ins(a[i].x,a[i].y);
	if(n==m)
	{
		memset(ans,127,sizeof(ans));
		for(int i=1;i<=n;i++)
			for(int j=lst[i];j;j=nxt[j])
				if(to[j]<i)
				{
					xx=to[j];yy=i;
					memset(bz,1,sizeof(bz));
					id=0;dfs(1);
					if(id==n && pd())memcpy(ans,b,sizeof(ans));
				}
	}else memset(bz,1,sizeof(bz)),id=0,dfs(1),memcpy(ans,b,sizeof(ans));
	for(int i=1;i<=n;i++)
		write(ans[i]),putchar(' ');
	return 0;
}
