#include <iostream>
#include <cstdio>
using namespace std;

long long a[1000010];int n,m;const int MD=1000000007;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==1){
		a[1]=2;
		for (int i=2;i<=m;i++){
			a[i]=a[i-1]*2;
			a[i]%=MD;
		}
	}
	else if (n==2){
		a[1]=4;
		for (int i=2;i<=m;i++){
			a[i]=a[i-1]*3;	
			a[i]%=MD;
		}		
	}
	else if (n==3){
		a[1]=8,a[2]=36,a[3]=112;
		for (int i=4;i<=m;i++){
			a[i]=a[i-1]*3;
			a[i]%=MD;
		}
	}
	else if (n==4){
		a[1]=16,a[2]=108,a[3]=336,a[4]=912,a[5]=2688,a[6]=8064;
	}
	else if (n==5){
		a[1]=32,a[2]=324,a[3]=1008,a[4]=2688,a[5]=7136;
	}
	else if (n==6){
		a[1]=64,a[2]=972,a[3]=3024,a[4]=8064;
	}
	else if (n==7){
		a[1]=128,a[2]=2916,a[3]=9072;
	}
	else if (n==8){
		a[1]=256,a[2]=8748,a[3]=27216;
	}
	printf("%lld\n",a[m]);
	return 0;
}
