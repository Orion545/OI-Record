#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	if(a<b) swap(a,b);
	return gcd(b,a%b);
}
int T,n,a,b,ans;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
	  scanf("%d",&n);
	  if(n==2){
		  scanf("%d",&a);scanf("%d",&b);
		  if(a<b) swap(a,b);
		  if(a%b==0) ans=1;else ans=2;
		  printf("%d\n",ans);
	  }
    }
}
