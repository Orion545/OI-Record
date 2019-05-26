#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int n,m,a[20][20],f[20][20],cost[20][20];
int bitcnt(int x){return (x?(bitcnt(x>>1)+(x&1)):0);}
int min(int l,int r){return l>r?r:l;}
int max(int l,int r){return l<r?r:l;}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	int S,i,j,k,tmp,cnt,sum[20],ans=inf;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(S=0;S<=(1<<(n-1))-1;S++){
		cnt=bitcnt(S);
		if(cnt>k) continue;
		for(i=1;i<=n;i++){
			memset(sum,0,sizeof(sum));
			for(j=i+1;j<=n+1;j++){
				cost[i][j]=0;
				tmp=0;
				for(k=1;k<=n;k++){
					sum[k]+=a[j-1][k];
					tmp+=sum[k];
					cost[i][j]=max(cost[i][j],tmp);
					if((S>>(k-1))&1) tmp=0;
				}
			}
		}
		memset(f,127,sizeof(f));
		f[0][1]=0;
		for(i=1;i<=m-cnt+1&&i<=n;i++){
			for(k=1;k<=n;k++){
				for(j=k+1;j<=n+1;j++){
					f[i][j]=min(f[i][j],max(f[i-1][k],cost[k][j]));
				}
			}
			ans=min(ans,f[i][n+1]);
		}
	}
	printf("%d",ans);
} 
/*
5 2
693 526 775 951 722
837 340 238 271 115
608 176 694 483 573
581 140 807 730 355
704 401 865 400 482

4822

*/
