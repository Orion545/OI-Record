#include <cstdio>
#include <cstring>
#include <iostream>
#define fo(i,a,b) for(i=a;i<=b;i++)
const int maxN=1e5+10;
int n,i,x,ans,las;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	las=0;
	fo(i,1,n)
		scanf("%d",&x),ans+=(las<x)?x-las:0,las=x;
	printf("%d\n",ans);
	return 0;
}
