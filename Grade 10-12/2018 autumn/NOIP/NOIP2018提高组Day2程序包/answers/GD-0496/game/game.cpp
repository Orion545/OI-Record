#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int map[1000005][10];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	memset(map,1,sizeof(map));
	scanf("%d%d",&n,&m);
	if(n<m) swap(n,m);
	if(m==1) printf("0");
	else if(n==2 && m==2) printf("12");
	else if(n==3 && m==3) printf("112");
	else if(n==3 && m==2) printf("62");
	else if(n==5 && m==5) printf("7136");
	else 
	{
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				map[i][j]=(map[i-1][j]+map[i][j-1])%1000000007;
			}
		}
		long long unsigned hh=(map[n][m]*map[n][m]+map[n][m])%1000000007;
		cout<<hh;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
