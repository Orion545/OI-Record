#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=50010;
struct node{
	int y,c,next;
}a[maxn*2];int len,first[maxn];
struct edge{
	int x,y,c;
}b[maxn];
int n,m,cnt=0,tot;
int d[maxn];

int read(int &sum)
{
	char ch=getchar();int f=0;sum=0;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	(ch=='-')&&(f=1,ch=getchar());
	while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
	(f)&&(sum=-sum);
	return sum;
}
bool cmp(edge a,edge b) {return a.c>b.c;}
void ins(int x,int y,int c) {a[++len]=(node){y,c,first[x]};first[x]=len;}
int dfs(int x,int fa,int dis)
{
	int sontot=0,maxx=0;
	for(int i=first[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(y!=fa)
		{
			sontot++;
			int tt=dfs(y,x,dis+a[i].c);
			if(tt>maxx) maxx=tt;
		}
	}
	int kk=d[x];
	d[x]=max(d[x],max(dis,maxx));
	if(sontot==0) return kk;
	return maxx;
}
bool cmp1(int a,int b) {return a>b;}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(first,len=0,sizeof first);
	read(n);read(m);
	for(int i=1;i<n;i++)
	{
		int x,y,c;
		b[i].x=read(x);b[i].y=read(y);b[i].c=read(c);
		ins(x,y,c);
		ins(y,x,c);
		if(d[x]<c) d[x]=c;
		if(d[y]<c) d[y]=c;
		if(x==1 || y==1) cnt++;
	}
	if(cnt==n-1)
	{
		sort(b+1,b+1+n,cmp);
		int ans=0x3f3f3f3f;
		if(m<=(n-1)/2)
		{
			for(int i=1;i<=m;i++)
				(b[i].c+b[m*2-i+1].c<ans)&&(ans=b[i].c+b[m*2-i+1].c);
		}
		else
		{
			ans=b[2*m-n+1].c;
			for(int i=2*m-n+2;i<=m;i++)
				(b[i].c+b[(n-1)-i+(2*m-n+2)].c<ans)&&(ans=b[i].c+b[(n-1)-i+(2*m-n+2)].c);
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
		dfs(i,0,0);
	sort(d+1,d+1+n,cmp1);
	printf("%d\n",d[m]);
	return 0;
}
