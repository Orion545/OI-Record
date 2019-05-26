#include<cstdio>
int a[10][10],n,m,i,j,k,ans;
const int mo=1e9+7;
void go(int x,int y,bool c)
{
	if (x==n+1)
	{
		ans=(ans+1)%mo;
		return;
	}
	if (x==1)
	{
		a[x][y]=0;
		if (y==m)
		go(x+1,1,true);
		else
		go(x,y+1,true);
		a[x][y]=1;
		if (y==m)
		go(x+1,1,false);
		else
		go(x,y+1,false);
	}
	else
	{
		if (!c)
		{
			a[x][y]=a[x-1][y+1];
			if (y==m)
			go(x+1,1,c);
			else
			go(x,y+1,c);
		}
		else
		{
			if (!a[x-1][y+1])
			{
				a[x][y]=0;
				if (y==m)
				go(x+1,1,c);
				else
				go(x,y+1,c);
			}
			a[x][y]=1;
			if (y==m)
			go(x+1,1,c);
			else
			go(x,y+1,c);
		}
	}
}
void go2(int x,int y)
{
	if (x==n+1)
	{
		ans=(ans+1)%mo;
		return;
	}
	if (!a[x-1][y+1])
	{
		a[x][y]=0;
		if (y==m)
		go2(x+1,1);
		else
		go2(x,y+1);
	}
	a[x][y]=1;
	if (y==m)
	go2(x+1,1);
	else
	go2(x,y+1);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==1)
	{
		ans=1;
		for (i=1;i<=m;i++)
		ans=(ans*2)%mo;
		printf("%d\n",ans);
		return 0;
	}
	if (n==3)
	{
		go(1,1,false);
		printf("%d\n",ans);
		return 0;
	}
	go2(1,1);
	printf("%d\n",ans);
	return 0;
}
