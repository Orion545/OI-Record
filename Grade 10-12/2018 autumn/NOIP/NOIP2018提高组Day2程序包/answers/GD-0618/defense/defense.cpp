#include <iostream>
#include <cstdio>
using namespace std;
int n,m,cnt=0;
long long ans;
int w[100005];
string type;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>type;
	if(type=="A2"){
		long long lsum=0,rsum=0;
		int u,v;
		bool x,y;
		long long ans1,ans2;
		for(int i=1;i<=n;i++){
			cin>>w[i];
			if(i%2==0) rsum+=w[i];
			else lsum+=w[i];
		}
		for(int i=1,x,y;i<n;i++) cin>>x>>y;
		while(m--){
		cin>>u>>x>>v>>y;
		if(x^y==1){
			if(x==1){
				if(u%2==1) cout<<lsum<<" ";
				else cout<<rsum<<endl;
			}
			else{
				if(v%2==1) cout<<lsum<<" ";
				else cout<<rsum<<endl;
			}
		}
		else{
			if(x==1){
				ans1=0;
				for(int i=u;i>=1;i-=2) ans1=ans1+w[i];
				for(int i=v;i<=n;i+=2) ans1=ans1+w[i];
				cout<<ans1<<endl;
			}
			else{
				cout<<"-1"<<endl;
			}
		}
		}
	}
}
