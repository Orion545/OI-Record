#include<bits/stdc++.h>
using namespace std;
int n,fr=0,x,ans=0,rest=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		x=(x-fr);
		if(x<0){
			ans=ans-x;
			rest=rest+x;
		}
		else{rest=rest+x;}
		fr=fr+x;
	}
	printf("%d\n",ans+rest);
	return 0;
}
