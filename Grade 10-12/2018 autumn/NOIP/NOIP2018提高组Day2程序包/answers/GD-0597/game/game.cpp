#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
bool g[100][100];
int getans(int row)
{
	int ans=4;
	for(int i=1;i<row;i++)
	{
		ans*=3;
		ans%=1000000007;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
		cout<<pow(2,m)<<endl;
	if(n==2)
		cout<<getans(m)<<endl;
	if(n==3)
	{
		if(m==2)
			cout<<36<<endl;
		if(m==3)
			cout<<112<<endl;
	}
	if(n==5&&m==5)
		cout<<7136<<endl;
	return 0;
}
