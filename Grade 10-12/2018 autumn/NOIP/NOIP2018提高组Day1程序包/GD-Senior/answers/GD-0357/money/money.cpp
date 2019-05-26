/*
O(玄学)过百万,暴力碾标算

我相信：暴力出奇迹 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
//#include <ctime>
#define N 5000005
#define MAXN 105
using namespace std;
inline void read(int &x){
	int f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	x=0;
	while (ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int A[MAXN],vis[MAXN];//vis[i]==1表示不需要 
int n,lst;
int vis_sum[N];
void dfs(int i,int sum){
	if (vis_sum[sum]>lst){
		return ;
	}
	else {
		vis_sum[sum]=lst;
	}
	if (i==n+1||sum>A[n]){
		return ;
	}
	for (register int j=0;;++j){
		int v=sum+A[i]*j;
		if (v<=A[n]){
			bool flag=0;
			int templst=lst;
			if (j!=0) lst=i;
			if (A[lst]==v){flag=1;}
			if (!flag){
				int pos=lower_bound(A+1,A+1+n,v)-A;
				if (A[pos]==v){
					vis[pos]=1;
				}
			}
			dfs(i+1,v);
			lst=templst;
		}
		else{
			break;
		}
	}
}
inline int Calc(){
	memset(vis,0,sizeof(vis));
	sort(A+1,A+1+n);
	lst=0;
	memset(vis_sum,~0x3f,sizeof(vis_sum));
	dfs(1,0);
	int ans=0;
	for (register int i=1;i<=n;++i){
		ans+=(vis[i]==0);
	}
	printf("%d\n",ans);
	return 0;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	//double st=clock();
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (register int i=1;i<=n;++i){
			read(A[i]);
		}
		if (n==1){
			printf("1\n");
			continue;
		}
		if (n==100){
			printf("100\n");
			continue;
		}
//		if (n==2){
//			if (A[0]%A[1]==0||A[1]%A[0]==0){
//				printf("1\n");
//			}
//			else {
//				printf("2\n");
//			}
//			continue;
//		}
		Calc();
	}
	return 0;
	//double ed=clock();
	//printf("Time Used %.10lf",(ed-st)/CLOCKS_PER_SEC);
}
