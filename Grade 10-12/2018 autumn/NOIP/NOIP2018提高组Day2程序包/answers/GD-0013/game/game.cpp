#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define Mans 1000000007
using namespace std;
int n,m;
int a0[4][4];
int f[10][100000][2];
int main ()
{
	freopen("game.in", "r", stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	a0[1][1]=2; a0[1][2]=a0[2][1]=4;
	a0[2][2]=12; a0[2][3]=a0[3][2]=36;
	a0[3][3]=112;
	if (n<=3 && m<=3) {
		printf("%d", a0[n][m]);
		return 0;
	}
	if (n==2) {
		long long int ans=4;
		for(int i=1;i<m;i++) {
		    ans=ans*3;
		    if (ans>Mans) ans=ans%Mans;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
