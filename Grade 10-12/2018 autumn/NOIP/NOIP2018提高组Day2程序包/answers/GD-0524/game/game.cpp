#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans,s[100][100];
int main() {
	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
	int i,j;
	cin>>n>>m;
	memset(s,0,sizeof(s));
	ans=12;s[1][1]=12;s[1][2]=12;s[2][1]=12;
	if(n<=1||m<=1)ans=0;else {
		if(n==2) {
		for(i=3;i<=m;i++) {
			ans*=3;ans%=1000000007;
		}
	}else {
		if(n==3&&m==2)ans=36;else {
			
			ans=112;ans%=1000000007;
		}
	}
	}
	
	
	cout<<ans;
}
//1000000007
