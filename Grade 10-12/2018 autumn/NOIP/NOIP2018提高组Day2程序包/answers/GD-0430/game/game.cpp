#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int INF=260;
const int mo=1000000007;
using namespace std;
int n,m;
int map[INF][INF],f[5][INF];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);//m代表行数，n代表列数
	for (int i=0;i<=(1<<n)-1;++i){//预处理出所有当前状态的合法状态 
		for (int j=0;j<=(1<<n)-1;++j){
			int l=0;
			if (i>=(1<<(n-1))) l=i-(1<<(n-1)); else l=i;
			//if (j==15&&i==0) printf("%d %d\n",(j>>1)|l,(j>>1));
			if (((j>>1)|l)<=(j>>1)) map[i][++map[i][0]]=j;
		}
	}/*
	for (int i=0;i<=(1<<n)-1;++i){
		printf("%d\n",i);
		for (int j=1;j<=map[i][0];++j) printf("%d ",map[i][j]);
		printf("\n");
	}*/
	memset(f,0,sizeof(f));
	for (int i=0;i<(1<<n);++i) f[1][i]=1;
	for (int i=2;i<=m;++i){
		for (int j=0;j<(1<<n);++j){
			for (int k=1;k<=map[j][0];++k){
				f[(i%3)][map[j][k]]=(f[(i%3)][map[j][k]]+f[((i-1)%3)][j])%mo;
			}
		}
	}
	int ans=0;
	for (int i=0;i<(1<<n);++i) ans=(ans+f[m%3][i])%mo;
	printf("%d",ans);
	return 0;
}
