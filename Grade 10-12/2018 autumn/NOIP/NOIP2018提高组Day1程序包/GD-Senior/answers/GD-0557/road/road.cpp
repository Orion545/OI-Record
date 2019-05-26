#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,d[100005],sumd=0,Ans=0,FirstPos=1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		sumd+=d[i];
	}
	while(sumd>0){
		int LastPos,MinVal=2100000000;
		for(;(!d[FirstPos])&&FirstPos<=n;FirstPos++){}
		for(LastPos=FirstPos;d[LastPos]&&LastPos<=n;LastPos++)
			MinVal=min(MinVal,d[LastPos]);
		for(int i=FirstPos;i<LastPos;i++)
			d[i]-=MinVal;
		if(FirstPos<LastPos) sumd-=(LastPos-FirstPos)*MinVal;
		Ans+=MinVal;
	}
	printf("%d",Ans);
	return 0;
}
