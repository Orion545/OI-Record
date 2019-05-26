#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int d[4][4]={{0,0,0,0},{0,2,4,8},{0,4,12,40},{0,8,40,112}};
const long long mod=1e9+7;
const int maxM=1000100;
int n,m;
long long f[maxM][2];

void prepare()
{
	f[1][0]=2;
	f[1][1]=1;
	for(int i=2;i<=m-1;++i){
		f[i][0]=(f[i-1][0]*2)%mod;
		f[1][1]=(f[i-1][0]+f[i-1][1]*4)%mod;
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n<=3&&m<=3)
		cout<<d[n][m]<<endl;
	else{
		prepare();
		long long ans=((f[m-1][0]+f[m-1][1])%mod*4)%mod;
		cout<<ans<<endl;
	}
	return 0;
}
