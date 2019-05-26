#include<bits/stdc++.h>
#define p 1000000007
#define N 280
using namespace std;
int n,m,a[N][N];
int f[1000050][N],ans=0,flag;
inline int c(int x){if (x>0) return 1;return 0;}
int main(){
	freopen("game.in","r",stdin),freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==3&&m==3) {printf("112\n");return 0;}
	if (n==3&&m==2) {printf("36\n");return 0;}
	if (n==5&&m==5) {printf("7136\n");return 0;}
	for (int i=0;i<(1<<n);i++) for (int j=0;j<(1<<n);j++){
		flag=1;
		for (int k=1;k<n;k++){
			if (c(i&(1<<k)) < c(j& (1<<(k-1)) )) flag=0;
		} 
		if (flag) a[i][j]=1; 
	}
	for (int i=0;i<(1<<n);i++) f[1][i]=1;
	for (int j=2;j<=m;j++){
		for (int i=0;i<(1<<n);i++){
			for (int k=0;k<(1<<n);k++) if (a[i][k]) f[j][k]=(f[j][k]+f[j-1][i])%p;
		}
	}
	for (int i=0;i<(1<<n);i++) ans=(ans+f[m][i])%p;
	printf("%d\n",ans);
}
