#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define MOD 998244353
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}


int add(int x,int y){
	x+=y;
	if(x>=MOD) x-=MOD;
	return x;
}

int n,m,dp[1010][2020][4],ans;

int main(){
	scanf("%d%d",&n,&m);

	int i,j,k,ch,ttmp;

	dp[1][2][1]=1;
	dp[1][2][2]=1;
	dp[1][1][0]=1;
	dp[1][1][3]=1;

	for(i=1;i<n;i++)
	{
		for(j=1;j<=(i<<1);j++)
		{
			for(k=0;k<=3;k++)
			{
				if(dp[i][j][k]==0) continue;
				for(ch=0;ch<4;ch++)
				{
					ttmp=0;
					if((k^ch)==3) ttmp=1+(k==1||k==2);
					else if(!(k^ch)) ttmp=0;
					else ttmp=(ch==1||ch==2);
					dp[i+1][j+ttmp][ch]=add(dp[i+1][j+ttmp][ch],dp[i][j][k]);
				}
			}
		}
	}

	for(int i=0;i<=3;i++) ans=add(ans,dp[n][m][i]);

	printf("%d\n",ans);
}
