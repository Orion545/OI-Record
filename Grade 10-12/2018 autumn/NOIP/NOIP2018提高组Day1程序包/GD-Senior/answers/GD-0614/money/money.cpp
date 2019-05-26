#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,mx,ans[25],a[110],v[25010];
void work(int x){
	for(int y=mx;y>=1;y--){
		if(v[y]){
			int l=y+x;
			while(l<=mx){
				v[l]=1;
				l+=x;
			}
		}
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		memset(v,0,sizeof(v));
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			mx=max(a[i],mx);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			if(!v[a[i]]){
				ans[tt]++;
				v[a[i]]=1;
				work(a[i]);
			}
		}
	}
	for(i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
