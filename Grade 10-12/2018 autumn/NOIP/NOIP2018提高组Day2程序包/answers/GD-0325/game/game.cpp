#include<iostream>
#include<cstdio>
#include<fstream>
	using namespace std;
	const int c=1000000007;
	int n=0,m=0,ans=0,x[2000005],lx[2000005],f[1000005][2],s[10][1000005];
	bool w=false;
int cha_y_i()
{
	for(int i=1;i<=n+m-1;i++)
		if(lx[i]>x[i]) return 0;
	return 1;
}
void cha_e_r(int a,int b,int k)
{
	if(a>n||b>m||w) return;
	if(a==n&&b==m)
	{
		x[k+1]=s[a][b];
		if(!cha_y_i()) w=true;
		for(int i=1;i<=k+1;i++) lx[i]=x[i];
		return;
	}
	x[k+1]=s[a][b],cha_e_r(a,b+1,k+1);
	x[k+1]=s[a][b],cha_e_r(a+1,b,k+1);
}
void gao(int x,int y)
{
	if(y>m) y=1,x++;
	if(x>n)
	{
		w=false;
		for(int i=1;i<=n+m-1;i++) lx[i]=0;
		cha_e_r(1,1,0);
		if(!w) ans++;
		return;
	}
	s[x][y]=0,gao(x,y+1);
	s[x][y]=1,gao(x,y+1);
}
int dfs(int x,int y)
{
	if(x>m) return 1;
	if(f[x][y]!=-1) return f[x][y];
	f[x][y]=(dfs(x+1,0)+dfs(x+1,1))%c;
	if(y==0) f[x][y]=(f[x][y]+f[x][y])%c;
	return f[x][y];
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1||m==1)
	{
		if(m==1) swap(n,m);
		int ans=1;
		for(int i=1;i<=m;i++) ans=(ans+ans)%c;
		printf("%d",ans);
	}
	else if(n==2||m==2)
	{
		if(m==2) swap(n,m);
		for(int i=1;i<=m+1;i++) f[i][0]=f[i][1]=-1;
		printf("%d",dfs(1,0));
	}
	else
	{
		gao(1,1);
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
	
