#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
char s[400010];
ll n,a[400010],cnt[110][26],fib[110],fail[400010],m,b[400010],ans[26],l,r;
void getb(){
	ll i,j=0;fail[0]=fail[1]=0;
	for(i=1;i<n;i++){
//		cout<<"enter kmp "<<i<<' '<<j<<' '<<a[i]<<' '<<a[j]<<'\n';
		while(a[i]!=a[j]&&j) j=fail[j];
		j+=(a[i]==a[j]);fail[i+1]=j;
	}
//	for(i=0;i<=n;i++) cout<<i<<' '<<fail[i]<<'\n';
	for(i=0;i<n-fail[n];i++) b[i]=a[i];
	m=n-fail[n];
}
void solve(ll lim,ll type){
	ll i,j;
//	cout<<"solve "<<lim<<' '<<type<<'\n';
	if(lim<=n){
		for(i=1;i<=lim;i++) ans[a[i]]+=type;
		return;
	}
	for(i=1;i<=100;i++){
		if(fib[i]<=lim) continue;
		for(j=0;j<26;j++) ans[j]+=cnt[i-1][j]*type;
		solve(lim-fib[i-1],type);break;
	}
}
void add(ll len,ll type){
	ll i,tot=len/m;
	for(i=1;i<=m;i++) ans[b[i]]+=tot*type;
	for(i=tot*m+1;i<=len;i++) ans[b[i-tot*m]]+=type;
} 
void another(){
	add(l-1,-1);add(r,1);
}
int main(){
//	freopen("1.txt","r",stdin);
	scanf("%s",s);n=strlen(s)>>1;ll i,j;
	l=read();r=read();
	for(i=0;i<n;i++) a[i]=s[i]-'a';
	getb();
	for(i=n;i>=1;i--) a[i]=a[i-1];
	for(i=m;i>=1;i--) b[i]=b[i-1];
//	if(n%m==0){
//		another();goto print;
//	}
	for(i=1;i<=n;i++) cnt[0][a[i]]+=1,cnt[1][a[i]]+=1;
	for(i=1;i<=m;i++) cnt[1][b[i]]+=1;
	fib[0]=n;fib[1]=(n+m);
	for(i=2;i<=100;i++){
		fib[i]=fib[i-1]+fib[i-2];
		for(j=0;j<=25;j++) cnt[i][j]=cnt[i-1][j]+cnt[i-2][j];
	}
//	for(i=0;i<26;i++) cout<<i<<' '<<cnt[0][i]<<' '<<cnt[1][i]<<'\n';
	solve(l-1,-1);
	solve(r,1);
	print:
	for(i=0;i<26;i++) printf("%lld ",ans[i]);
}

