#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
char a[2010],b[2010];int n,ans=1e9;
int minn[2010],maxn[2010],ch[2010];
void solve(){
	int i,j,diff,tot,tmp;
	for(i=0;i<n;i++){
		minn[i]=maxn[i]=0;
		while(b[(i+maxn[i])%n]!='1') maxn[i]++;
		while(b[(i+minn[i]+n)%n]!='1') minn[i]--;
	}
	for(j=0;j<n;j++){
		for(i=0;i<n;i++) ch[i]=0;
		diff=0;
		for(i=0;i<n;i++){
			if(a[i]!=b[(i+j)%n]){
				ch[-minn[i]]=max(ch[-minn[i]],maxn[i]-j);
				diff++;
			}
		}
		tot=1e9;tmp=0;
		for(i=n-1;i>=0;i--){
			tot=min(tot,tmp+i);
			tmp=max(tmp,ch[i]);
		}
		ans=min(ans,tot*2+diff+j);
	}
}
int main(){
	scanf("%s%s",a,b);int i,fa=0,fb=0;
	n=strlen(a);
	for(i=0;i<n;i++) fa|=(a[i]=='1');
	for(i=0;i<n;i++) fb|=(b[i]=='1');
	if(!fb){
		if(fa) puts("-1");
		else puts("0");
		return 0;
	}
	solve();
	reverse(a,a+n);reverse(b,b+n);
	solve();
	cout<<ans<<'\n';
}

