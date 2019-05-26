#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll n,m,a[200010],b[200010];
int main(){
	ll i,j,tmpa,tmpb,ans=0;
	n=read();m=read();
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=m;i++) b[i]=read();
	i=j=1;tmpa=a[1];tmpb=b[1];
	while(i<=n&&j<=m){
//		cout<<i<<ends<<j<<ends<<tmpa<<ends<<tmpb<<ends<<ans<<endl;
		if(tmpa==tmpb){
			tmpa=a[++i];tmpb=b[++j];ans++;continue;
		}
		if(tmpa<tmpb) i++,tmpa+=a[i];
		if(tmpa>tmpb) j++,tmpb+=b[j];
	}
	printf("%I64d\n",ans);
}
