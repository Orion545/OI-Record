#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,d[N],minn,maxn;
long long ans;
bool f;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	minn=0;
	f=1;
	for(int i=1;i<=n;i++){
		if(f){
			if(d[i]<d[i-1]){
				maxn=d[i-1];
				ans+=maxn-minn;
				f=0;
			}
		}
		else{
			if(d[i]>=d[i-1]){
				minn=d[i-1];
				f=1;
			}
		}
	}
	if(d[n]>d[n-1])ans+=d[n]-minn;
	printf("%lld",ans);
	return 0;
}
