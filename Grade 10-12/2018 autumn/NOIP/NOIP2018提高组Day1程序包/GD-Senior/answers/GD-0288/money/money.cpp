#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
void exgcd(ll A,ll B,ll&x,ll&y,ll&d){
	if(!B){
		x=1,y=0,d=A;
	}else{
		exgcd(B,A%B,y,x,d);
		y-=x*(A/B);
	}
}
const int N=202;
int T,n,A[N];bool del[N];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(del,0,sizeof(del));
		scanf("%d",&n); int res=0;
		for(int i=1;i<=n;i++) scanf("%d",A+i);
		
//		sort(A+1,A+n+1);
		for(int i=1;i<=n;i++){
			 for(int j=1;j<=n;j++){
			 	if(i==j) continue;
			 	for(int k=j;k<=n;k++){
			 		if(i==k) continue;
			 		if(k==j){
			 			if(A[i]%A[k]==0) del[i]=1;
			 			if(del[i]) break;
			 			continue;
			 		}
			 		ll x,y,d,a,b; a=A[j],b=A[k];
			 		if(A[j]>A[k]) exgcd(A[j],A[k],x,y,d);
			 		else exgcd(A[k],A[j],y,x,d);
			 		if(A[i]%d!=0) continue;
			 		x*=(A[i]/d); y*=(A[i]/d);
			 		if(x>y) swap(x,y),swap(a,b);
//			 		if(x*a+b*y!=A[i]) puts("err");
			 		if(x>=0) del[i]=1;
			 		else{
			 			x=x%(b*d)+b*d;
			 			y=(A[i]-x*a)/b;
			 			if(y>=0) del[i]=1;
			 		}
			 		if(del[i]) break;
			 	}
			 	if(del[i]) break;
			 }
		}
		for(int i=1;i<=n;i++) if(!del[i]) res++;
		printf("%d\n",res);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
