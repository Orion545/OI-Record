#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,min_a,max_a,ans,a[108];
bool p[25008];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		min_a=a[1];
		max_a=a[n];
		for(int i=min_a;i<=max_a;i++){
			p[i]=false;
		}
		ans=1;
		for(int i=0;i*min_a<=max_a;i++){
			p[i*min_a]=true;
		}
		for(int i=2;i<=n;i++)if(!p[a[i]]){
			ans++;
			for(int j=max_a;j>=min_a;j--)if(p[j]){
				for(int x=j+a[i];x<=max_a;x+=a[i]){
					if(!p[x]){
						p[x]=true;
					}else{
						break;
					}
				}
			}
			for(int x=0+a[i];x<=max_a;x+=a[i]){
				if(!p[x]){
					p[x]=true;
				}else{
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
