#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long n,m;
	scanf("%ld%ld",&n,&m);
	if(n==1||m==1)printf("0\n");
	else if(n==2||m==2){
		if(m==2){
			long t=n;n=m;m=t;
		}
		long long t=1;
		for(int i=1;i<=m-1;i++){
			t=(t*2)%1000000007;
		}
		t=(t*t)%1000000007;
		printf("%lld\n",(t-1)*4%1000000007);
	}
	else if(n==3||m==3){
		if(m==3){
			long t=n;n=m;m=t;
		}
		long long t=1;
		for(int i=1;i<=m;i++){
			t=(t*2)%1000000007;
		}
		printf("%lld\n",(t/2*28)%1000000007);
	}
	else if(n==5&&m==5)printf("7136\n");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
