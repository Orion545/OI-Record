#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int n,x,las,ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&las);
	ans=las;
	for(int i=1;i<n;i++){
		scanf("%d",&x);
		if(x>las){
			ans+=x-las;
		}
		las=x;
	}
	printf("%d",ans);
	return 0;
}
