#include<cstdio>
#include<iostream>
using namespace std;
int n,m,x1,y1,x2,y2,s,mo,t;
long long mi[32];
long long ans,now,sum;
int min(int p,int q){
	if (q<p) return q; else return p;
}
int main()
{
	freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
	mo=1000000007;
	scanf("%d%d",&n,&m);
	if (m<n){
		s=m; m=n; n=s;
	}
	x1=0; y1=0; x2=0; y2=0;
	ans=1;
	for (int i=1;i<=n-1;i++){
		ans=(ans*(i+1))%mo;
		ans=(ans*(i+1))%mo;
	}
	mi[0]=1; mi[1]=n+1; t=0; now=m-n+1;
    while (now!=0){
    	if (now & (1<<(t+1))!=0){
    		ans=(ans*mi[t+1])%mo;
    		now=now & (now-1);
    	}
    	t++;
    	mi[t+1]=(mi[t]*mi[t])%mo;
    }
	printf("%lld\n",ans);
	fclose(stdin);
    fclose(stdout);
	return 0;
}
