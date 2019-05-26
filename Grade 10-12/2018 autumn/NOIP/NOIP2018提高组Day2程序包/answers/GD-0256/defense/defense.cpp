#include<cstdio>
#include<cstring>
using namespace std;
long long INF=1000000000000000;
const int N=100010;
int head[N],next[N][2],tot=0;
long long f1[N][2];
long long f2[N][2];
bool isleaf[N];
int v[N];
int p[N];
int n,m;
int fa[N];
void connect(int,int);
void copy();
void leaf(int);
void build(int);
int min(int,int);
long long min(long long,long long);
void change(int,int);
int nnn(int,int);
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		connect(u,v);
	}
	v[1]=1;
	leaf(1);
	build(1);
	v[1]=0;
	while(m--)
	{
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(nnn(a,b)&&x==0&&y==0)
		{
			printf("-1\n");
			continue;
		}
		copy();
		change(a,x);
		change(b,y);
		printf("%lld\n",min(f2[1][0],f2[1][1]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int nnn(int a,int b)
{
	for(int p=head[a];p;p=next[p][0])
		if(next[p][1]==b)
			return 1;
	return 0;
}
void change(int x,int k)
{
	f2[x][k]=INF;
	x=fa[x];
	while(x!=0)
	{
		int flag=0;
		long long sum=0;
		long long mm=100000000;
		for(int l=head[x];l;l=next[l][0])
		{
			int temp=next[l][1];
			if(v[temp]) continue;
			if(isleaf[temp])
			{
				flag=1;
				sum=sum+p[temp];
				continue;
			}
			long long delta=f2[temp][1]-f2[temp][0];
			if(delta<0) flag=1;
			mm=min(mm,delta);
			sum+=min(f2[temp][1],f2[temp][0]);
		}
		if(flag==0)
		{
			sum+=mm;
		}
		f2[x][0]=sum;
		sum=0;
		for(int p=head[x];p;p=next[p][0])
		{
			int temp=next[p][1];
			sum+=min(f2[temp][0],f2[temp][1]);
		}
		f2[x][1]=sum;
		x=fa[x];
	}
} 
void build(int x)
{
	if(isleaf[x])
	{
		f1[x][0]=0;
		f1[x][1]=p[x];
		return;
	}
	int flag=0;
	long long sum=0;
	long long mm=100000000;
	for(int l=head[x];l;l=next[l][0])
	{
		int temp=next[l][1];
		if(v[temp]) continue;
		if(isleaf[temp])
		{
			flag=1;
			sum=sum+p[temp];
			continue;
		}
		long long delta=f1[temp][1]-f1[temp][0];
		if(delta<0) flag=1;
		mm=min(mm,delta);
		sum+=min(f1[temp][1],f1[temp][0]);
	}
	if(flag==0)
	{
		sum+=mm;
	}
	f1[x][0]=sum;
	sum=0;
	for(int p=head[x];p;p=next[p][0])
	{
		int temp=next[p][1];
		sum+=min(f1[temp][0],f1[temp][1]);
	}
	f2[x][1]=sum;
	for(int p=head[x];p;p=next[p][0])
	{
		int temp=next[p][1];
		if(v[temp]==1) continue;
		v[temp]=1;
		build(temp);
		v[temp]=0;
	}
}
void leaf(int x)
{
	int cnt=0;
	for(int p=head[x];p;p=next[p][0])
	{
		cnt++;
		int temp=next[p][1];
		if(v[temp]) continue;
		v[temp]=1;
		fa[temp]=x;
		leaf(temp);
		v[temp]=0;
	}
	if(cnt==1) isleaf[x]=1;
}
void copy()
{
	for(int i=1;i<=n;i++)
	{
		f2[i][0]=f1[i][0];
		f2[i][1]=f2[i][1];
	}
}
void connect(int u,int v)
{
	next[++tot][0]=head[u];
	head[u]=tot;
	next[tot][1]=v;
	next[++tot][0]=head[v];
	head[v]=tot;
	next[tot][1]=u;
}
long long min(long long a,long long b)
{
	return a>b?b:a;
}
int min(int a,int b)
{
	return a>b?b:a;
}
