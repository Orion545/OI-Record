#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,a[300010],b[300010];
int main(){
	n=read();ll i,j;
//	cout<<n<<' '<<m<<'\n';
	for(i=1;i<=n;i++) a[i]=read();
	m=read();
	for(i=1;i<=m;i++) b[i]=read();
	i=1;j=1;
	ll cura=a[1],curb=b[1],ans=0;
	while(i<=n&&j<=m){
//		cout<<i<<' '<<j<<' '<<cura<<' '<<curb<<'\n';
		if(cura==curb){
			i++;j++;ans++;
			cura=a[i];curb=b[j];
			continue;
		}
		if(cura<curb){
			i++;cura+=a[i];
		}
		if(cura>curb){
			j++;curb+=b[j];
		}
	}
	if(i==n+1&&j==m+1) cout<<ans<<'\n';
	else puts("-1");
}
