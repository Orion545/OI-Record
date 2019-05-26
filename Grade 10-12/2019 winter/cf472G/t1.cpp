#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll unsigned long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,q,cnt[200010];
char a[200010],b[200010];
ll x[200010],y[200010];
inline int calc(ll x){
//	cout<<"calc "<<x<<' '<<x<<' '<<(x>>16)<<' '<<(x>>32)<<' '<<(x>>48)<<'\n';
	return cnt[x&((1<<16)-1)]+cnt[(x>>16)&((1<<16)-1)]+cnt[(x>>32)&((1<<16)-1)]+cnt[(x>>48)&((1<<16)-1)];
}
int main(){
	int i,j,t1,t2,t3,ans;
	scanf("%s",a);n=strlen(a);
	scanf("%s",b);m=strlen(b);
	q=read();
	for(i=n;i>=1;i--) x[i]=(x[i+1]<<1)|(a[i-1]=='1');
	for(i=m;i>=1;i--) y[i]=(y[i+1]<<1)|(b[i-1]=='1');
	cnt[0]=0;
	for(i=1;i<(1<<16);i++) cnt[i]=cnt[i>>1]+(i&1);
//	for(i=1;i<=n;i++) cout<<i<<' '<<x[i]<<'\n';
//	for(i=1;i<=m;i++) cout<<i<<' '<<y[i]<<'\n';
	while(q--){
		t1=read();t2=read();t3=read();ans=0;
		t1++;t2++;
		for(;t3>=64;t1+=64,t2+=64,t3-=64) ans+=calc(x[t1]^y[t2]);
//		cout<<"check query "<<t1<<' '<<t2<<' '<<t3<<' '<<(x[t1]&((1<<t3)-1))<<' '<<(y[t2]&((1<<t3)-1))<<'\n';
		if(t3) ans+=(calc((x[t1]&((1ll<<t3)-1))^(y[t2]&((1ll<<t3)-1))));
		printf("%d\n",ans);
	}
}
