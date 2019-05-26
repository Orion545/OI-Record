#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;char ss[1100];
int hf[1100000];
int dp[110000][2];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);scanf("%s",ss+1);
	for (int i=1;i<=n;i++)scanf("%d",&hf[i]);
	for (int i=1;i<=n-1;i++){
		int x,y;scanf("%d%d",&x,&y);
	}
	for (int i=1;i<=m;i++){
		int a,x,b,y;scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(dp,63,sizeof(dp));
		dp[0][1]=0;
		for (int j=1;j<=n;j++){
			dp[j][0]=dp[j-1][1];
			dp[j][1]=min(dp[j-1][0],dp[j-1][1])+hf[j];
			if (j==a){dp[j][1-x]=999999999;}
			if (j==b){dp[j][1-y]=999999999;}
		}
		if (min(dp[n][1],dp[n][0])>=999999999)printf("-1\n");
		else printf("%d\n",min(dp[n][1],dp[n][0]));
	}
	return 0;
}
/*
第1 行包含两个正整数??, ??和一个字符串????????，分别表示城市数、要求数和数据类
型。????????是一个由大写字母A，B 或C 和一个数字1，2，3 组成的字符串。它可以帮助
你获得部分分。你可能不需要用到这个参数。这个参数的含义在【数据规模与约定】中
有具体的描述。
第2行n个整数pi，表示编号i的城市中驻扎军队的花费。
接下来n ? 1行，每行两个正整数u, v，表示有一条u到v的双向道路。
接下来m行，第j行四个整数a, x, b, y(a ≠ b)，表示第j个要求是在城市a驻扎x支军队，
在城市b驻扎y支军队。其中，x 、 y 的取值只有0 或1：若x 为0，表示城市a 不得驻
扎军队，若x 为1，表示城市a 必须驻扎军队；若y 为0，表示城市b 不得驻扎军队，
若y 为1，表示城市b 必须驻扎军队。
输入文件中每一行相邻的两个数据之间均用一个空格分隔。
*/
