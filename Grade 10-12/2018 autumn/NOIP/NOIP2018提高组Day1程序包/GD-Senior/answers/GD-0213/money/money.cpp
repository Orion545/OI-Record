#include<cstdio>
#include<algorithm>
using namespace std;
bool c[25000];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,t,ans;
	register int i,j,k,a[200];
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(i=0;i<n;++i){
			scanf("%d",a+i);
		}
		sort(a,a+n);
		if(a[0]==1){printf("1\n");continue;}
		for(i=0;i<=a[n-1];++i)c[i]=false;
		c[0]=true;
		for(i=0;i<n;++i){
			//cout<<c[a[i]]<<endl;
			if(!c[a[i]]){
				c[a[i]]=true;
				for(j=0;j<=a[n-1]-a[i];++j){
					if((j==0)||(j%a[i])&&c[j]){
						for(k=a[i];k+j<=a[n-1];k+=a[i]){
							c[j+k]=true;
							//cout<<j<<" "<<k<<endl;
						}
					}
				}
				ans++;
		//cout<<ans<<endl;
			}
		//for(int i=0;i<=a[n-1];++i)if(c[i])cout<<1<<" ";else cout<<0<<" ";
		//cout<<endl;
		}
		printf("%d\n",ans);
	}
}
