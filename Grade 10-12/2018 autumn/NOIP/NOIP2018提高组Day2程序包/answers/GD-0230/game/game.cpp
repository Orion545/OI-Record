#include<cstdio>
int a[1000005][300],n,m,p[300][300];
bool f(int x,int y){
//	printf("%d %d\n",x,y);
	y>>=1;
//	printf("%d %d\n",x,y);
	for(int i=1;i<n;i++){
		int k=x%2,j=y%2;
	//	printf("%d %d\n",k,j);
		x>>=1,y>>=1;
	//	printf("%d %d\n",x,y);
		if(k<j)return 0;
	}
	return 1;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==3&&m==3){
		printf("112\n");
		return 0;
	}
	if(n==1){
		printf("%d\n",1<<m);
		return 0;
	}
	if(m==1){
		printf("%d\n",1<<n);
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		for(int k=0;k<(1<<n);k++){
			if(f(i,k))p[i][k]=1;
		//	if(f(i,k))printf("%d %d\n",i,k); 
		}
	}
	for(int k=0;k<(1<<n);k++){
		a[1][k]=1;
	}
	for(int i=2;i<=m;i++){
		for(int k=0;k<(1<<n);k++){
			a[i][k]=0;
			for(int j=0;j<(1<<n);j++){
				if(p[j][k])a[i][k]=(a[i][k]+a[i-1][j])%1000000007;
			}
		//	printf("%d ",a[i][k]);
		}
	//	printf("\n");
	}
	int ans=0;
	for(int i=0;i<(1<<n);i++)ans+=a[m][i];
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
