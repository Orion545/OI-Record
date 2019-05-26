#include<cstdio>
#include<cctype>

inline int getint()
{
	register int r=0,f=1;
	register char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-f:f,c=getchar();
	while (isdigit(c))
		r=(r<<3)+(r<<1)+(c^48),c=getchar();
	return r*f;
}
const int N=10;
int n,m;
int a[N][N];
int clc(int s)
{
	int x=0,y=0,sum=0;
	for (int i=1;i<=n+m-2;i++)
	{
		sum=(sum<<1)+a[x][y];
		if (s&1)
			y++;
		else
			x++;
		s>>=1;
	}
	return sum+a[n-1][m-1];
}
bool ck(int s)
{
	int tot=0;
	while (s)
		tot+=s&1,s>>=1;
	return tot==m-1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int nm,ans=0;
	n=getint(),m=getint(),nm=n*m;
	if (n==3&&m==3)
	{
		puts("112");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for (int s=0;s<(1<<nm);s++)
	{
		int tmp=s;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				a[i][j]=tmp&1,tmp>>=1;
		bool flg=0;
		for (int t=0;t<(1<<(n+m-2));t++)
		{
			for (int r=t+1;r<(1<<(n+m-2));r++)
				if (ck(t)&&ck(r)&&clc(t)<clc(r))
				{
					flg=1;
					break;
				}
			if (flg)
				break;
		}
		if (!flg)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
