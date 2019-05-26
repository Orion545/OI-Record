#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int d[100001];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		long long tmp=d[i]-d[i-1];
		if(tmp>0)ans+=tmp;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
}
