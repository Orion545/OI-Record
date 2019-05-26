#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int t,n,ans,mx,a[101];
bool ch[25001];
vector<int>v;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(ch,0,sizeof(ch));
		v.clear();
		mx=0;
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(ch[a[i]]){
				ans--;
				continue;
			}else{
				for(int s=a[i];s<=mx;s+=a[i]){
					ch[s]=true;
					for(int k=1;k<=mx;k++){
						if(k+s>mx)break;
						if(ch[k])ch[k+s]=true;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
