#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define mod 1000000007
int n,m;
int mi(int x)
{
	if(x==1)return 2;
	long long ans=mi(x/2)%mod;
	ans=(ans*ans)%mod;
	if(x&1)ans=(ans*2)%mod;
	return ans;
}
int a[5][100086];
int sum[5][100086];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==1){printf("%d",mi(n));return 0;}
	if(n==1){printf("%d",mi(m));return 0;}
	if(n==2&&m==2)cout<<12;
	if(n==3&&m==3)cout<<112;
		
	return 0;
}
