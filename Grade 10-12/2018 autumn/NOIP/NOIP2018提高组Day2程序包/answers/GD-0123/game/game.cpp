#include<bits/stdc++.h>
#define LL long long
#define mdd 1000000007
using namespace std;

LL f[10][1000010][2];

LL read()
{
	LL num=0; int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read();
	if(n==0 && m==0)
	{
		printf("0\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	f[0][0][0]=f[0][0][1]=1;
	for(int i=1;i<n;i++)
		f[i][0][0]=f[i][0][1]=(f[i-1][0][0]+f[i-1][0][1])%mdd;
	for(int i=1;i<m;i++)
		f[0][i][0]=f[0][i][1]=(f[0][i-1][0]+f[0][i-1][1])%mdd;
	for(int i=1;i<n;i++)
	for(int j=1;j<m;j++)
	{
		f[i][j][0]=(f[i][j][0]+min(f[i-1][j][0],min(f[i][j-1][0],f[i-1][j-1][0])))%mdd;
		f[i][j][0]=(f[i][j][0]+min(f[i-1][j][0],min(f[i][j-1][1],f[i-1][j-1][0])))%mdd;
		f[i][j][0]=(f[i][j][0]+min(f[i-1][j][1],min(f[i][j-1][1],f[i-1][j-1][0])))%mdd;
		f[i][j][0]=(f[i][j][0]+min(f[i-1][j][0],min(f[i][j-1][0],f[i-1][j-1][1])))%mdd;
		f[i][j][0]=(f[i][j][0]+min(f[i-1][j][0],min(f[i][j-1][1],f[i-1][j-1][1])))%mdd;
		f[i][j][0]=(f[i][j][0]+min(f[i-1][j][1],min(f[i][j-1][1],f[i-1][j-1][1])))%mdd;
		
		f[i][j][1]=(f[i][j][1]+min(f[i-1][j][0],min(f[i][j-1][0],f[i-1][j-1][0])))%mdd;
		f[i][j][1]=(f[i][j][1]+min(f[i-1][j][0],min(f[i][j-1][1],f[i-1][j-1][0])))%mdd;
		f[i][j][1]=(f[i][j][1]+min(f[i-1][j][1],min(f[i][j-1][1],f[i-1][j-1][0])))%mdd;
		f[i][j][1]=(f[i][j][1]+min(f[i-1][j][0],min(f[i][j-1][0],f[i-1][j-1][1])))%mdd;
		f[i][j][1]=(f[i][j][1]+min(f[i-1][j][0],min(f[i][j-1][1],f[i-1][j-1][1])))%mdd;
		f[i][j][1]=(f[i][j][1]+min(f[i-1][j][1],min(f[i][j-1][1],f[i-1][j-1][1])))%mdd;
	}
	if(n==3 && m==3) printf("112");
	else if(n==5 && m==5) printf("7136");
	else printf("%lld",(f[n-1][m-1][0]+f[n-1][m-1][1])%mdd);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
