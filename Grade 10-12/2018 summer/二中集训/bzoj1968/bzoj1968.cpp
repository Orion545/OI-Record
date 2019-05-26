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
int vis[1000010],pri[1000010],cntp,d[1000010],n,mincnt[1000010];
void init(){
	int i,j,k;d[1]=1;ll ans=0;
	for(i=2;i<=n;i++){
		if(!vis[i]) pri[++cntp]=i,d[i]=2,mincnt[i]=1;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>n) break;
			vis[k]=1;
			if(i%pri[j]==0){d[k]=d[i]/(mincnt[i]+1)*(mincnt[i]+2);mincnt[k]=mincnt[i]+1;break;}
			d[k]=d[pri[j]]*d[i];mincnt[k]=1;
		}
//		cout<<i<<' '<<d[i]<<' '<<mincnt[i]<<'\n';
	}
	for(i=1;i<=n;i++) ans+=(ll)d[i];
	printf("%lld\n",ans);
}
int main(){
	n=read();init();
}

