/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
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
long double n,nn,d,delta;
long double calc(long double st,long double del,long double tot){
	return (st+del*(tot+1.0)/2.0);
}
int main(){
	nn=n=read();d=read();delta=read();d-=delta;
	long double ans=0;
	for(int i=1;i<=nn;i++){
		ans+=calc(d,delta,n*2.0);
//		cout<<i<<' '<<d<<' '<<delta<<' '<<ans<<'\n';
		d=(3.0*delta+(n*2.0+2.0)*d)/(n*2.0);
		delta=((n*2.0+4.0)*delta)/(n*2.0);
		n--;
	}
	printf("%.15lf\n",(double)ans);
}

