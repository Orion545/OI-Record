#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define X (5010)
#define mes(x,y) memset(x,y,sizeof x)
#define mcp(x,y) memcpy(x,y,sizeof x)
using namespace std;
inline void read(int &x)
{
	char ch=getchar();x=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,m,x[X*2],y[X*2],e[X];

void kp(int l,int r)
{
	int i=l,j=r,mid1=x[(l+r)/2],mid2=y[(l+r)/2];
	while (i<j)
	{
		while (x[i]<mid1 || (x[i]==mid1 && y[i]<mid2)) i++;
		while (x[j]>mid1 || (x[j]==mid1 && y[j]>mid2)) j--;
		if (i<=j)
		{
			swap(x[i],x[j]);
			swap(y[i],y[j]);
			i++,j--;
		}
	}
	if (i<r) kp(i,r);
	if (l<j) kp(l,j);
}

int f[X],st=0;

void dfs(int now,int from)
{
	if (f[now])
	{
		f[now]=from;
		st=now;
		return;
	}
	else
		f[now]=from;
	for (int i=e[now];i<=e[now+1]-1;i++)
	{
		int s=y[i];
		if (s!=from)
			dfs(s,now);
		if (st) return;
	}
}

int A,B,ans[X],l,bz;

void getans(int now,int from)
{
	++l;
	if (now<ans[l])
		bz=2;
	if (now>ans[l] && bz!=2)
	{
		bz=1;
		return;
	}
	ans[l]=now;
	for (int i=e[now];i<=e[now+1]-1;i++)
	{
		int s=y[i];
		if (!((A==now && B==s)||(B==now && A==s)) && s!=from)
			getans(s,now);
		if (bz==1) return;
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n),read(m);
	int i;
	for (i=1;i<=m;i++)
		read(x[i]),read(y[i]),x[i+m]=y[i],y[i+m]=x[i];
	kp(1,m*2);
	for (i=1;i<=m*2;i++)
		if (x[i]>x[i-1])
			e[x[i]]=i;
	e[n+1]=m*2+1;
	mes(ans,127);
	if (n==m)
	{
		dfs(1,0);
		A=st,B=f[st],l=bz=0;
		getans(1,0);
		for (i=f[st];i!=st;i=f[i])
		{
			A=i,B=f[i],l=bz=0;
			getans(1,0);
		}
	}
	//C
	else
	{
		A=B=bz=l=0;
		getans(1,0);
	}
	//T
	for (i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}














