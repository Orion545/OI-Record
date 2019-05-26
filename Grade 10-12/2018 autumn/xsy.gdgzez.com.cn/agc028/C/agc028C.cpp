/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
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
int n,a[200010],b[200010],x[500010],rk[500010],pos[500010];
inline bool cmp(int l,int r){
	return x[l]<x[r];
}
int main(){
//	freopen("in.in","r",stdin);
	n=read();int i;ll tota=0,totb=0;
	for(i=1;i<=n;i++){
		a[i]=read();b[i]=read();
		x[i]=a[i];x[i+n]=b[i];
		rk[i]=i;rk[i+n]=i+n;
		tota+=a[i];totb+=b[i];
	}
	sort(rk+1,rk+n*2+1,cmp);
	ll ans=min(tota,totb),sum=0,tmp=0,cur;
	for(i=1;i<=n*2;i++) pos[rk[i]]=i;
	for(i=1;i<=n;i++) sum+=x[rk[i]];
//	cout<<tota<<' '<<totb<<' '<<tmp<<'\n';
	for(i=1;i<=n;i++){
		if(x[i]>x[i+n]) cur=i;
		else cur=i+n;
		if(pos[cur]<n) tmp=0;
		else if(i==((rk[n]-1)%n+1)) tmp=x[cur]-x[rk[n-1]];
		else tmp=x[cur]-x[rk[n]];
//		cout<<"choose "<<i<<' '<<sum<<' '<<tmp<<' '<<rk[pos[i]]<<' '<<rk[pos[i+n]]<<'\n';
		ans=min(ans,sum+tmp);
	}
	printf("%lld\n",ans);
}
