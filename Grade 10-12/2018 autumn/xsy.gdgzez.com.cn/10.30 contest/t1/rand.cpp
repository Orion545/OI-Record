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
#include<ctime>
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
struct node{
	int val,s;
}x[1100010];int cnt=0;
inline bool cmp(node l,node r){return l.val<r.val;}
int main(){
	int n=20,a[50],i,s,sum=0;srand(time(NULL));
	for(i=1;i<=n;i++) a[i]=(rand()%2000)+1,sum+=a[i];
	for(s=1;s<(1<<n);s++){
		int tmp=0;
		for(i=1;i<=n;i++) if(s&(1<<(i-1))) tmp+=a[i];
		x[++cnt]=(node){tmp,s};
	}
	sort(x+1,x+cnt+1,cmp);
	cout<<"answer "<<x[(cnt+1)>>1].val<<' '<<sum<<'\n';
	for(i=1;i<=n;i++) cout<<i<<' '<<a[i]<<' '<<((x[(cnt+1)>>1].s&(1<<(i-1)))?"YES":"NO")<<'\n';
}

