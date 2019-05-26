#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int n,ans,a[N],d[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		d[i]=a[i]-a[i-1];
	}
	sort(d+1,d+n+1);
	int hd=1,tl=n;
	while(d[hd]<0){
		while(1){
			int v=-d[hd];
			if(d[tl]<=v){
				d[hd]+=d[tl];
				ans+=d[tl];
				d[tl--]=0;
			}
			else{
				ans+=v;
				d[tl]-=v;
				d[hd]=0;
				break;
			}
		}
		++hd;
	}
	for(int i=1;i<=n;i++)
		ans+=d[i];
	printf("%d",ans);
	return 0;
}
