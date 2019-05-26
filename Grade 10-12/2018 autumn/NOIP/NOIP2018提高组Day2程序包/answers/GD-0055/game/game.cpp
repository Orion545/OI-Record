#include<cstdio>
#include<cstdlib>
#include<cstring>
#define ll long long

int a[10][10],n,m,s1[10],s2[10],w[100];
ll ans,mod=1000000007;
int small()
{
	int i;
	//for(i=1;i<=n+m-1;i++)printf("%d ",s1[i]);printf("\n");
	//for(i=1;i<=n+m-1;i++)printf("%d ",s2[i]);printf("\n\n");
	for(i=1;i<=n+m-1;i++)
	{
		if(s1[i]<s2[i])return 100;
		if(s1[i]>s2[i])return 50;
	}
	return 100;
}
int dfs2(int x,int y,int tf)
{
	int ne;
	s2[x+y-1]=a[x][y];//printf("%d %d %d %d\n",x,y,n,m);
	if(x==n&&y==m)
	{//printf("*****\n");
		return small();
	}
	else
	{
		if(y<m&&x>=w[x+y]||y<m&&tf==0)
		{//printf("%d %d\n",y,m);
			if(tf==0)ne=0;
			else if(x>w[x+y])ne=0;
				 else ne=1;
			if(dfs2(x,y+1,ne)==50)return 50;
		}
		if(x<n&&x+1>=w[x+y]||x<n&&tf==0)
		{
			if(tf==0)ne=0;
			else if(x+1>w[x+y])ne=0;
				 else ne=1;
			if(dfs2(x+1,y,ne)==50)return 50;
		}
	}
	return 100;
}
int dfs1(int x,int y)
{
	s1[x+y-1]=a[x][y];
	w[x+y-1]=x;
	if(x==n&&y==m)
	{//printf("*****\n");
		return dfs2(1,1,1);
	}
	else
	{
		if(y<m)
		{
			if(dfs1(x,y+1)==50)return 50;
		}
		if(x<n)
		{
			return dfs1(x+1,y);
		}
	}
	return 100;
}
int dg(int x,int y)
{
	int i,j;
	if(x>n)
	{
		if(dfs1(1,1)==100)
		{
			ans++;
			/*for(i=1;i<=n;i++)
			{
				for(j=1;j<=m;j++)printf("%d ",a[i][j]);printf("\n");
			}
			printf("\n");*/
		}
	}
	else
	{
		a[x][y]=0;
		if(y<m)dg(x,y+1);
		else dg(x+1,1);
		a[x][y]=1;
		if(y<m)dg(x,y+1);
		else dg(x+1,1);
	}
}
int main()
{
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
int i,j,t;
scanf("%d %d",&n,&m);
if(n>m){t=n;n=m;m=t;}
if(n==1)
{
	ans=1;
	for(i=1;i<=m;i++)ans=(ans*2)%mod;
	printf("%lld",ans);return 0;
}
if(n==2)
{
	ans=4;
	for(i=1;i<m;i++)ans=(ans*3)%mod;
	printf("%lld",ans);return 0;
}
dg(1,1);
printf("%lld",ans);
return 0;
}
