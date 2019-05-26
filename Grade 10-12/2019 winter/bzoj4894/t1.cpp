#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define MOD 1000000007
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,a[310][310],ch=0;
void gauss(){
//	cout<<"gauss\n";
	ll i,j,k,num,tmp,val,inv;
//	for(i=2;i<=n;i++){
//		for(j=2;j<=n;j++) cout<<a[i][j]<<' ';
//		cout<<'\n';
//	}
	for(i=2;i<=n;i++){
		num=i;
		for(j=i+1;j<=n;j++) if(abs(a[j][i])>abs(a[num][i])) num=j;
		if(num!=i) ch^=1,swap(a[num],a[i]);
		for(j=i+1;j<=n;j++){
			while(a[j][i]){
				tmp=a[j][i]/a[i][i];
//				cout<<i<<' '<<j<<' '<<a[j][i]<<' '<<a[i][i]<<' '<<tmp<<'\n';
				for(k=2;k<=n;k++)
					a[j][k]=(a[j][k]-(a[i][k]*tmp%MOD)+MOD)%MOD;
//				cout<<i<<' '<<j<<' '<<a[j][i]<<' '<<a[i][i]*tmp%MOD<<'\n';
				if(a[j][i]==0) break;
				ch^=1;
				swap(a[j],a[i]);
			}
		}
	}
//	for(i=2;i<=n;i++){
//		for(j=2;j<=n;j++) cout<<a[i][j]<<' ';
//		cout<<'\n';
//	}
}
int main(){
	n=read();ll i,j;char s[310];
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<n;j++){
			if(s[j]=='0') continue;
			a[j+1][j+1]++;a[i][j+1]--;
		}
	}
	gauss();ll ans=1;
	for(i=2;i<=n;i++) ans=(ans*a[i][i]%MOD);
	if(ch) ans=-ans;
	ans=(ans+MOD)%MOD;
	cout<<ans<<'\n';
}
