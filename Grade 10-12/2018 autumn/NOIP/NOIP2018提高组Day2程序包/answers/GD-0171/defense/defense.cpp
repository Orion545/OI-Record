#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int n,m;
char ty,pe;
int edge[100010][2]={0};
int edgenum[100010]={0};
int index[100010]={0};
int liantong[200010]={0};
int price[100010]={0};
int dp[100010][3]={0};
int dp2[100010][3]={0};

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d %d %c%c",&n,&m,&ty,&pe);
	//printf("%c %c",ty,pe);
	int i,j,k;
	int x,y;
	int rex,rey;
	for(i=1;i<=n;i++){
		scanf("%d",&price[i]);
	}
	if(ty=='A'){
		dp[1][1]=price[1];
		dp[1][0]=0;
		dp[1][3]=0;
		for(i=2;i<=n;i++){
			dp[i][1]=price[i]+dp[i-1][2];
			dp[i][0]=dp[i-1][1];
			dp[i][2]=min(dp[i][1],dp[i][0]);
		}
		for(i=1;i<=m;i++){
			scanf("%d %d %d %d",&x,&rex,&y,&rey);
			if(x==y+1 || x==y-1){
				if(rex==0 && rey==0){
					printf("-1\n");
					continue;
				}
			}
			if(x>y){
				j=x;x=y;y=j;
				j=rex;rex=rey;rey=j;
			}
			memset(dp2,0,sizeof(dp2));
			dp2[x][0]=dp[x][0];
			dp2[x][1]=dp[x][1];
			if(rex==1){
				dp2[x][2]=dp2[x][1];
			}
			else{
				dp2[x][1]=2100000000;
				dp2[x][2]=dp2[x][0];
			}
			for(j=x+1;j<=n;j++){
				dp2[j][1]=price[j]+dp2[j-1][2];
				dp2[j][0]=dp2[j-1][1];
				dp2[j][2]=min(dp2[j][1],dp2[j][0]);
				if(j==y){
					if(rey==1){
						dp2[y][2]=dp2[y][1];
					}
					else{
						dp2[y][1]=2100000000;
						dp2[y][2]=dp2[y][0];
					}
				}
			}
			printf("%d\n",dp2[n][2]);
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	for(i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		edge[i][0]=x;
		edge[i][1]=y;
		edgenum[x]++;
		edgenum[y]++;
	}
	index[1]=1;
	for(i=2;i<=n;i++){
		index[i]=index[i-1]+edgenum[i-1];
	}
	for(i=1;i<=m;i++){
		x=edge[i][0];
		y=edge[i][1];
		liantong[index[x]]=y;
		liantong[index[y]]=x;
		index[x]++;
		index[y]++;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
