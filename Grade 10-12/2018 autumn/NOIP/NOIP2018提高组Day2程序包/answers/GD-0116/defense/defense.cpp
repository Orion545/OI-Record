#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#define N 100005
#define Maxn 1000005

using namespace std;
int line[N*2],head[N],tail[N],dep[N];
int z[N],fa[N],f[N][2],son[N];
char c[3];
bool check[N],cc[N];
int n,m,aa,bb,xx,yy,cnt;

struct E
{
	int x,y;
}; E e[2*N];

struct D
{
	int b,d;	
}; D ddep[N];

bool cmp(E a,E b)
{
	return a.x<b.x;
}

bool cmp2(D xx,D yy)
{
	return xx.d>yy.d;
} 

void dfs_dep(int x,int depp,int father)
{
	bool ccheck=false;
	if (x!=father) fa[x]=father;
	check[x]=true;
	dep[x]=depp+1;
	for (int i=head[x];i<=tail[x];i++)
	if (not(check[e[i].y])) dfs_dep(e[i].y,depp+1,x),ccheck=true;
	if (not (ccheck))line[++cnt]=x;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(check,false,sizeof(check));
	scanf("%d%d",&n,&m);
	scanf("%s",c);
	for (int i=1;i<=n;i++)
	scanf("%d",&z[i]);
	int tot=0;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&xx,&yy);
		e[++tot].x=xx; e[tot].y=yy;
		e[++tot].x=yy; e[tot].y=xx;
	}
	sort(e+1,e+tot+1,cmp);
	tot=1;
	head[1]=1;
	for (int i=2;i<=2*(n-1);i++) 
	if (tot!=e[i].x) tail[tot]=i-1,head[++tot]=i;
	tail[tot]=2*(n-1);
	cnt=0;
	dfs_dep(1,0,1);
	memset(check,false,sizeof(check));
	memset(cc,false,sizeof(cc));
	for (int i=1;i<=n;i++)
	{
		ddep[i].b=i;
		ddep[i].d=dep[i];
	}
	sort(ddep+1,ddep+n+1,cmp2);
	for (int i=1;i<=n;i++)
	{
		son[fa[i]]++;
	}
	for (int i=1;i<=m;i++)
	{
		memset(f,0,sizeof(f));
		memset(cc,false,sizeof(cc));
		scanf("%d%d%d%d",&aa,&xx,&bb,&yy);
		if (fa[aa]==bb||fa[bb]==aa)
		{
			printf("-1\n");
			continue;
		}
		if (ddep[1].b!=aa&&ddep[1].b!=bb)
		f[ddep[1].b][0]=0, f[ddep[1].b][1]=z[ddep[1].b];
		else 
		if (ddep[1].b==aa) 
		{
			if (xx==1) f[aa][1]=z[aa],f[aa][0]=Maxn;
			if (xx==0) f[aa][0]=0,f[aa][1]=Maxn;
		}
		else 
		{
			if (yy==1) f[bb][1]=z[bb],f[bb][0]=Maxn;
			if (yy==0) f[bb][0]=0;f[bb][1]=Maxn;
		}
		int beginn;
		for (int i=2;i<=n;i++)
		{
			if (ddep[i].d==ddep[i-1].d&&ddep[i].b!=aa&&ddep[i].b!=bb) 
			f[ddep[i].b][0]=0,f[ddep[i].b][1]=z[ddep[i].b];
			else 
			if (ddep[i].d==ddep[i-1].d&&ddep[i].b==aa)
			{
				if (xx==1) f[aa][1]=z[aa],f[aa][0]=Maxn;
				if (xx==0) f[aa][0]=0,f[aa][1]=Maxn;
			}
			else 
			if (ddep[i].d==ddep[i-1].d&&ddep[i].b==bb)
			{
				if (yy==1) f[bb][1]=z[bb],f[bb][0]=Maxn;
				if (yy==0) f[bb][0]=0;f[bb][1]=Maxn;
			}
			else break;
		}
		for (int i=1;i<=cnt;i++)
		{
			if (line[i]!=aa&&line[i]!=bb)
			f[line[i]][0]=0,f[line[i]][1]=z[line[i]];
			else 
			if (line[i]==aa)
			{
				if (xx==1) f[aa][1]=z[aa],f[aa][0]=Maxn;
				if (xx==0) f[aa][0]=0,f[aa][1]=Maxn;
			}
			else
			if (line[i]==bb)
			{
				if (yy==1) f[bb][1]=z[bb],f[bb][0]=Maxn;
				if (yy==0) f[bb][0]=0;f[bb][1]=Maxn;
			}
		}
		for (int i=1;i<=n;i++)
		{
			int p=ddep[i].b;
			if (fa[p]!=aa&&fa[p]!=bb)
			{
				f[fa[p]][0]+=f[p][1];
				f[fa[p]][1]+=min(f[p][0],f[p][1]);
				if (not (cc[fa[p]])) f[fa[p]][1]+=z[fa[p]],cc[fa[p]]=true;
			}
			else 
			if (fa[p]==aa)
			{
				if (xx==1) 
				{
					f[fa[p]][1]+=min(f[p][0],f[p][1]);
					f[fa[p]][0]=Maxn;
					if (not (cc[fa[p]])) f[fa[p]][1]+=z[fa[p]],cc[fa[p]]=true;
				}
				if (xx==0) f[fa[p]][0]+=f[p][1], f[fa[p]][1]=Maxn;
			}
			else 
			if (fa[p]==bb)
			{
				if (yy==1) 
				{
					f[fa[p]][1]+=min(f[p][0],f[p][1]);
					f[fa[p]][0]=Maxn;
					if (not (cc[fa[p]])) f[fa[p]][1]+=z[fa[p]],cc[fa[p]]=true;
				}
				if (yy==0) f[fa[p]][0]+=f[p][1], f[fa[p]][1]=Maxn;
			}
		}
		printf("%d\n",min(f[1][0],f[1][1]));
	}
}
