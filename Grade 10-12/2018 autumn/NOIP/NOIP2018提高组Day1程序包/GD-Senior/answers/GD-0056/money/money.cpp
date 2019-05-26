#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[25010],m,maxn;
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--){
		int flag=0;
		m=maxn=0;
		cin>>n;
		for(int i=1;i<=n;++i) {
			cin>>a[i];
			maxn=max(a[i],maxn);
			if(a[i]==1) {
				cout<<1<<endl;
				flag=1;
				break;
			}
		}
		if(flag) continue;
		sort(a+1,a+1+n);
		if(n==2){
			if(a[2]%a[1]==0) cout<<1<<endl;
			else cout<<n<<endl;
		}
		else if(n==3){
			if(gcd(a[2],a[1])==a[1]&&gcd(a[3],a[1])==a[1]) cout<<1<<endl;
			else if(gcd(a[2],a[1])==1&&gcd(a[3],a[1])==1&&gcd(a[3],a[2])==1) cout<<3<<endl;
			else if(gcd(a[2],a[1])==1&&a[2]*a[1]-a[2]-a[1]<a[3]) cout<<2<<endl;
			else cout<<2<<endl;
		}
		else if(n<=5){
			int tmp=0;
			for(int i=2;i<=n;++i){
				if(a[i]%a[1]!=0) tmp=1;
			}
			if(!tmp){
				cout<<1<<endl;
				continue;
			}
			tmp=0;
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(gcd(a[j],a[i])!=1) tmp=1;
				}
			}
			if(!tmp){
				cout<<n<<endl;
				continue;
			}
			cout<<n-1<<endl;
		}
		else {
			int tmp=0;
			for(int i=2;i<=n;++i){
				if(a[i]%a[1]!=0) tmp=1;
			}
			if(!tmp){
				cout<<1<<endl;
				continue;
			}
			if(gcd(a[2],a[1])==1&&a[2]*a[1]-a[2]-a[1]<a[3]) cout<<2<<endl;
			else cout<<n<<endl;
		}
	}
	return 0;
}
