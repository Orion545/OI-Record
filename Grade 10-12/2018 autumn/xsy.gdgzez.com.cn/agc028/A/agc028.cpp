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
int n,m,k,i;
char s[100010],t[100010];
int gcd(int l,int r){
	if(r==0) return l;
	return gcd(r,l%r);
}
int main(){
	n=read();m=read();k=gcd(n,m);
	int nn=n/k,mm=m/k;
	scanf("%s",s);
	scanf("%s",t);
	for(i=0;i<k;i++){
		if(s[nn*i]!=t[mm*i]){puts("-1");return 0;}
	}
	printf("%lld\n",(ll)n/(ll)k*(ll)m);
}
