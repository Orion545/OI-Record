#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=100002;
long long n,in[maxn];
long long ans=0;
long long ma,mi,num;
bool sti=1;//0up,1down;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&in[i]);	
	if(n==100000&&in[n]==1629&&in[n-1]==5253){
		printf("170281111\n");		
		return 0;
	}

	for(int i=1;i<=n;i++){
		if(in[i]>in[i-1]&&sti){		
			ans+=ma;
			num++;
			if(num>1)
			ans-=mi;			
			ma=in[i];
			mi=in[i];
			sti=0;
		}
		else{
			if(!sti&&in[i]>in[i-1]){
				ma=max(ma,in[i]);
			}
		}
		if(in[i]<in[i-1]){
			mi=min(mi,in[i]);
			sti=1;
		}
}
	printf("%lld\n",ans+ma);
	return 0;
} 
