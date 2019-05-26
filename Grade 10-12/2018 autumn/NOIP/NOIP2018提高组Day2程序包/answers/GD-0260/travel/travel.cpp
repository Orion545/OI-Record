#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=5010;
struct node{
	int y,next;
}a[maxn*2];int len,first[maxn];
struct edge{
	int x,y;
}e[maxn*2];
int n,m,ans[maxn],tot,in[maxn];
bool v[maxn];

void read(int &sum)
{
	char ch=getchar();int f=0;sum=0;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	(ch=='-')&&(f=1,ch=getchar());
	while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
	(f)&&(sum=-sum);
}
bool cmp(edge a,edge b)
{
	if(a.x!=b.x) return a.x<b.x;
	return a.y>b.y;
}
void ins(int x,int y) {a[++len]=(node){y,first[x]};first[x]=len;}
void dfs_1(int x,int fa)
{
	ans[++tot]=x;
	for(int i=first[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y!=fa) dfs_1(y,x);
	}
}
void dfs_2(int x,int fa,int bro)
{
	ans[++tot]=x;v[x]=true;
	int son[maxn],sontot=0,lst=-1;
	for(int i=first[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y!=fa)
		{
			son[++sontot]=y;
			if(in[y]==1) lst=y;
		}
	}
	for(int i=first[x];i;i=a[i].next)
	{
		int y=a[i].y,yy=a[a[i].next].y,k=a[i].next;
		if(y==fa) continue;
		while(v[yy]) yy=a[a[k].next].y,k=a[k].next;
		if(lst!=-1 && y>lst && y>bro) break;
		if(yy==5005) yy=bro;
		if(y!=fa) in[y]--;
		if(!v[y] && y!=fa)
		{
			if(lst==-1 && y>bro) break;
			dfs_2(y,x,yy);
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		read(x);read(y);
		e[i*2-1]=(edge){x,y};
		e[i*2]=(edge){y,x};
	}
	sort(e+1,e+1+2*m,cmp);
	memset(first,len=0,sizeof first);
	memset(in,tot=0,sizeof in);
	for(int i=1;i<=2*m;i++)
		ins(e[i].x,e[i].y),in[e[i].y]++;
	if(m==n-1)
	{
		dfs_1(1,0);
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
	else
	{
		memset(v,false,sizeof v);
		ans[++tot]=1;v[1]=true;a[0].y=5005;
		for(int i=first[1];i;i=a[i].next)
		{
			int yy=a[a[i].next].y;
			if(a[i].next==0) yy=5005;
			dfs_2(a[i].y,1,yy);
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}
}
