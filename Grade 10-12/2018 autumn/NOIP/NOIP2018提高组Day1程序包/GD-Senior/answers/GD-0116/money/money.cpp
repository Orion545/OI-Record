#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
#define N 1005
#define M 25005

using namespace std;
int a[N],b[N];
int t2[M];
int n,maxa,tot,ans,T;
bool key,key2;

bool cmp(int a,int b)
{
	return a<b;
}

void dfs(int x,int y)
{
	for (int i=1;i<=n;i++)
	{
		if (x==0) t2[y]=2,key2=true;
		if (y!=a[i]&&x-a[i]>=0&&not(key2)) dfs(x-a[i],y);
	}
}

void work(int x)
{
	int p=2;
	while (p*x<=maxa)
	{
		t2[p*x]=2;
		p++;
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for (int k=1;k<=T;k++)
	{
		maxa=0;
		ans=0;
		memset(t2,0,sizeof(t2));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			t2[a[i]]=1;
			if (a[i]>maxa) maxa=a[i];	
		}
		sort(a+1,a+n+1,cmp);
		key=false;
		if (a[1]==1) printf("1\n"),key=true;
		if (not(key))
		for (int i=1;i<=n;i++)
		if (t2[a[i]]==1) work(a[i]);
		tot=0;
		if (not (key))
		for (int i=1;i<=maxa;i++)
		if (t2[i]==1) b[++tot]=i;
		if (not(key)) 
		for (int i=1;i<=tot;i++)
		if (t2[b[i]]==1)
		key2=false,dfs(b[i],b[i]);
		if (not(key))
		for (int i=1;i<=tot;i++)
		if (t2[b[i]]==1) ans++;
		if (not(key))
		printf("%d\n",ans);
	}
}
