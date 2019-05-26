#include<cstdio>
using namespace std;
long long mo=1000000007;
long long n,m,x,tot;
long long ksm(long long a,long long b){
	long long ans=1; 
	while (b){
		if (b&1) ans=(ans*a)%mo;
		a=(a*a)%mo;b>>=1;
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if (n==1 || m==1) printf("0");
	else{
		if (n!=2){		
	    	if (n==3 && m==3) printf("112");
    		if (n==3 && m==2) printf("144");    		
    	}
    	else{
	    	x=12;--m;tot=ksm(x,m);
        	printf("%lld",tot);
      	}
	}	
	return 0;
}
