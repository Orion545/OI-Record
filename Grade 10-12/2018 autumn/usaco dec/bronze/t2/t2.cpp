#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
int n,op[110],ed[110],val[110],a[10010];
int main(){
	freopen("blist.in","r",stdin);
	freopen("blist.out","w",stdout);
	n=read();int i,j;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++){
		op[i]=read();
		ed[i]=read();
		val[i]=read();
		for(j=op[i];j<=ed[i];j++){
			a[j]+=val[i];
		}
	}
	int ans=0;
	for(i=1;i<=1000;i++) ans=max(ans,a[i]);
	cout<<ans<<'\n';
}
