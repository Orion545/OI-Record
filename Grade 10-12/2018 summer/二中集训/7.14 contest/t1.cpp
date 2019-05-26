#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector> 
#define ll long long
using namespace std;
int n;double p,q,f[100010],g[100010];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%lf%lf",&n,&p,&q);
		f[0]=0;g[0]=1;n=min(n,1000);
		for(int i=1;i<=n;i++){
			if(f[i-1]>g[i-1]) p=1-p,q=1-q;
			f[i]=(p*g[i-1]+(1-p)*q*f[i-1])/(1-(1-p)*(1-q));
			g[i]=(q*f[i-1]+(1-q)*p*g[i-1])/(1-(1-p)*(1-q));
			if(f[i-1]>g[i-1]) p=1-p,q=1-q;
		}
		printf("%.6lf\n",f[n]);
	}
}
