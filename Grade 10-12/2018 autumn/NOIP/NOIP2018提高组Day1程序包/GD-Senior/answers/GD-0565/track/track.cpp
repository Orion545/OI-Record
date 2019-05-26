#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#define maxn 50005
using namespace std;
int n,m;
int tot=0,t[maxn],nt[maxn],head[maxn],val[maxn],r[maxn];
bool vis1[maxn]={0},vis2[maxn]={0};
int deep[maxn],f[maxn],fv[maxn];

void build(int a,int b,int v)
{
	tot++;
	t[tot]=b;
	val[tot]=v;
	nt[tot]=head[a];
	r[b]++;
	head[a]=tot;
}

//int headshu[maxn],ntshu[maxn],tshu[maxn],totshu=0;
//void buildshu(int a,int b)
//{
//	totshu++;
//	tshu[totshu]=b;
//	nt[totshu]=headshu[a];
//	headshu[a]=totshu;
//}
queue<int> q;
void jianshu()
{
	q.push(1);
	deep[1]=0;
	f[1]=1;
	while(q.empty())
	{
		int qi=q.front();
		q.pop();
		for(int i=head[qi];i;i=nt[i])
		{
			if(vis2[t[i]]==1)
			{
				continue;
			}
			f[t[i]]=qi;
			deep[t[i]]=deep[qi]+1;
			fv[t[i]]=val[i];
		}
	}
}

int long1=-1,long2=-1;
int ld1,ld2;
void dfs1(int a,int anss)
{
	int ntanss;
	if(r[a]==1)
	{
		if(anss>long1)
		{
			long1=anss;
			ld1=a;
		}
		else{
			if(anss>long2)
			{
				long2=anss;
				ld2=a;
			}
		}
		return;
	}
	
	for(int i=head[a];i;i=nt[i])
	{
		if(vis1[t[i]]==1)
		{
			continue;
		}
		vis1[t[i]]=1;
		ntanss=val[i]+anss;
		dfs1(t[i],ntanss);
	}	
}

int lca1(int a,int b)
{
	int key=0;
	while(deep[a]<deep[b])
	{
		key+=fv[a];
		a=f[a];
	}
	while(deep[a]>deep[b])
	{
		key+=fv[b];
		b=f[b];
	}
	while(a!=b)
	{
		key+=fv[b];
		key+=fv[a];
		a=f[a];
		b=f[b];
	}
	return key;
}

int zhijin(){
	int chu;
	for(int i=1;i<n;i++)
	{
		if(r[i]>1)
		{
			chu=i;
			break;
		}
	}
	dfs1(chu,0);
	return lca1(ld1,ld2);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(int a,b,v,i=1;i<n;i++)
	{
		scanf("%d %d %d", &a, &b, &v);
		build(a,b,v);
		build(b,a,v);
	}
	jianshu();
	int ans=zhijin();
	printf("%d\n", ans);
}
