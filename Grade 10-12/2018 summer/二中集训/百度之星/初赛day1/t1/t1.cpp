#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int a[1010],n,x[200010],pre[200010],lim=200000;
int main(){
	int i,j,k,ans;
	while(~scanf("%d",&n)){
		memset(x,0,sizeof(x));memset(pre,0,sizeof(pre));
		for(i=1;i<=n;i++) a[i]=read(),x[a[i]]++;
		sort(a+1,a+n+1);ans=-1;
		for(i=1;i<=lim;i++){
			pre[i]=pre[i-1];
			if(x[i]) pre[i]=i;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<i;j++){
				k=a[i]+a[j]-1;
//				cout<<i<<' '<<j<<' '<<k<<' '<<pre[k]<<' '<<x[a[i]]<<'\n';
				if(pre[k]>a[i]||(pre[k]==a[i]&&x[a[i]]>1+(a[i]==a[j]))) ans=max(ans,a[i]+a[j]+pre[k]);
			}
		}
		printf("%d\n",ans);
	}
}

