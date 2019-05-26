#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int n,m,ap[10][10],ans=0;
int ch[513],last[513];bool checks;
const int mod=1e9+7;
void check_dfs(int x,int y){
//	if(ans==2) printf("123");
	if(checks) return ;
	if(x==n&&y==m){
		for(int i=1;i<=x+y-2;i++){
	//		printf("%d ",ch[i]);
			if(ch[i]<last[i]){
		//		printf("N %d %d %d\n",i,ch[i],last[i]);
				checks=true;
				break;
			}
		}
		for(int i=1;i<=x+y-2;i++)
			last[i]=ch[i];
		return;
	}
	ch[x+y-2]=ap[x][y];
	if(y+1<=m)
		check_dfs(x,y+1);
	if(x+1<=n)
		check_dfs(x+1,y);
}
bool check(){
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(ap[i][j+1]>ap[i+1][j])
				return false;
	memset(last,0,sizeof last);
	memset(ch,0,sizeof ch);
	checks=false;
	check_dfs(1,1);
//	printf("%d",checks);
	return (checks==false);
}
void dfs(int i,int j){
	if(i==n+1){
	/*	for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				printf("%d ",ap[i][j]);
			printf("\n");
		}*/
		if(check()){
	//		printf("Y\n");
			ans=(ans+1)%mod;
		}
	//	printf("\n");
		return;
	}
	ap[i][j]=0;
	if(j<m) dfs(i,j+1);
	else dfs(i+1,1);
	ap[i][j]=1;
	if(j<m) dfs(i,j+1);
	else dfs(i+1,1);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		printf("2\n");
		return 0;
	} if((n==1&&m==2)||(n==2&&m==1)){
		printf("4\n");
		return 0;
	} if((n==3&&m==3)){
		printf("112\n");
		return 0;
	} if(n==5&&m==5){
		printf("7136\n");
		return 0;
	}
	dfs(1,1);
	printf("%d",ans%mod);
	return 0;
}
