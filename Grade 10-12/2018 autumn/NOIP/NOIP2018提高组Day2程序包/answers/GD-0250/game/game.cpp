#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
long long ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)printf("1");
	else if(n==2){
		ans=4;
		for(int i=1;i<m;i++){
			ans=(ans*3)%1000000007;
		}
		printf("%lld",ans);
	}
	else if(n==3){
		ans=36;
		for(int i=1;i<m-1;i++){
			ans=(ans*4)%1000000007;
		}
		printf("%lld",ans);
	}
	
	fclose(stdin);fclose(stdout);
	return 0;	
}
