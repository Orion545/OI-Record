#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,x[510],rk[510],a[300010],cur;
bool cmp(int l,int r){
	return x[l]<x[r];
}
int main(){
	n=read();int i,j,tmp;
	for(i=1;i<=n;i++) x[i]=read(),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	int used=0;cur=1;
	for(i=1;i<=n;i++){
//		cout<<"do "<<i<<' '<<cur<<'\n';
		if(x[rk[i]]-used<rk[i]){
			puts("No");return 0;
		}
		used+=rk[i];
		a[x[rk[i]]]=rk[i];
		for(j=1;j<=rk[i]-1;j++){
			while(a[cur]) cur++;
//			cout<<"	mark "<<cur<<'\n';
			a[cur]=rk[i];
		}
	}
	for(i=1;i<=n;i++){
		tmp=rk[i];if(tmp==n) continue;
		for(j=x[rk[i]]+1;j<=n*n;j++){
			if(a[j]) continue;
//			cout<<"mark "<<rk[i]<<' '<<j<<' '<<tmp<<' '<<n<<'\n';
			a[j]=rk[i];tmp++;
			if(tmp==n) break;
		}
		if(tmp<n){
			puts("No");return 0;
		}
	}
	puts("Yes");
	for(i=1;i<=n*n;i++) printf("%d ",a[i]);
} 
