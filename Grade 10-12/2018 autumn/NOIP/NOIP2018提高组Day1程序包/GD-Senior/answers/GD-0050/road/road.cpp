#include<cstdio>
#include<iostream>
#define maxn 100010
using namespace std;
int n,ans;
int d[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);ans=0;
	for (int i=1;i<=n;++i){
		scanf("%d",&d[i]);
		if(d[i]>d[i-1]) ans+=d[i]-d[i-1];
	}
	printf("%d\n",ans);
}
