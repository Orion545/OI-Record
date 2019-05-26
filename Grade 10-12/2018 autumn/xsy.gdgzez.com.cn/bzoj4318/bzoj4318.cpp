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
int main(){
	int n;double p1=0,p2=0,p3=0,p;
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%lf",&p);
		p3=p*(p3+3.0*p2+3.0*p1+1.0)+(1.0-p)*p3;
		p2=p*(p2+2.0*p1+1.0);
		p1=p*(p1+1.0);
//		cout<<i<<' '<<p1<<' '<<p2<<' '<<p3<<'\n';
	}
	printf("%.1lf\n",p3);
}
