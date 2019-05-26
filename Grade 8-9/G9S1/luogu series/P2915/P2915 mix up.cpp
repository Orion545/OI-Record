#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll read(){
	ll re=0,flag=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') re=re*10+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,a[20],dp[20][500010];
int main(){
	ll i,j,k,maxn,place;
	n=read();m=read();
	for(i=0;i<n;i++) a[i]=read();
	maxn=(1<<n)-1;
	for(i=0;i<n;i++) dp[i][1<<i]=1;
	for(i=3;i<=maxn;i++){
		for(j=0;j<n;j++) if((1<<j)==i) goto skip;
//		cout<<"in dp "<<i<<endl;
		for(j=0;j<n;j++){
			if(i&(1<<j)){
//				cout<<"	most right "<<j<<endl;
				for(k=0;k<n;k++){
					if(j!=k&&i&(1<<k)&&abs(a[k]-a[j])>m){
//						cout<<"		last right "<<k<<endl;
						dp[j][i]+=dp[k][i^(1<<j)];
					}
				}
			}
		}
		skip:place=0;
	}
	ll ans=0;
	for(i=0;i<n;i++) ans+=dp[i][maxn];
	printf("%lld",ans);
}
