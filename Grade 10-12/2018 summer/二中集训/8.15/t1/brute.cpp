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
int n,a[200010][2],pre,cur;
int main(){
	freopen("in.in","r",stdin);
	n=read();int i,l=1,r=(n<<1)-1,mn,mx;pre=0;cur=1;
	for(i=1;i<(n<<1);i++) a[i][cur]=read();
	while(l<r){
		l++;r--;swap(pre,cur);
		for(i=l;i<=r;i++){
			mn=min(min(a[i-1][pre],a[i][pre]),a[i+1][pre]);
			mx=max(max(a[i-1][pre],a[i][pre]),a[i+1][pre]);
			if(a[i-1][pre]!=mn&&a[i-1][pre]!=mx) a[i][cur]=a[i-1][pre];
			else if(a[i][pre]!=mn&&a[i][pre]!=mx) a[i][cur]=a[i][pre];
			else a[i][cur]=a[i+1][pre];
			cout<<i<<' '<<a[i][cur]<<'\n';
		}
	}
//	cout<<l<<'\n';
	printf("%d\n",a[l][cur]);
}
