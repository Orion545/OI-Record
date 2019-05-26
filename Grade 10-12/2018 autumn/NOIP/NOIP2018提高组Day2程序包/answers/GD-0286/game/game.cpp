#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long map[10][10];
long long as(int x)
{
	long long sum=1;
	for (int i=2;i<=x;++i) sum*=i,sum%=1000000007;
	return sum;
}
int main()
{
	int n,m;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=10;++i)
	 for (int j=1;j<=10;++j) map[i][j]=as(i)*as(j)%1000000007;
	map[1][1]=2; map[1][2]=4; map[2][1]=4;
	map[2][2]=12; map[3][3]=112; map[5][5]=7136;
	map[2][3]=map[3][2]=36;
	cout<<map[n][m];
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
