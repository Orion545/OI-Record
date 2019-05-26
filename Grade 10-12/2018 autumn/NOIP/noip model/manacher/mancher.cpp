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
char s[22000010];int n,len[30000010];char a[30000010];
int main(){
	scanf("%s",s);n=strlen(s);int i,ans=0,lim,pos;
	for(i=0;i<n;i++) a[i*2+2]=s[i],a[i*2+1]='#';
	a[0]='*';n=n*2;
	a[++n]='#';
	lim=0;pos=0;
	for(i=1;i<=n;i++){
		if(i<=lim) len[i]=min(len[pos]+pos-i,len[pos*2-i]);
		else len[i]=1;
		while(a[i+len[i]]==a[i-len[i]]) len[i]++;
		if(i+len[i]>lim) lim=i+len[i],pos=i;
		ans=max(ans,len[i]);
//		cout<<i<<' '<<a[i]<<' '<<len[i]<<'\n';
	}
	cout<<ans-1<<'\n';
}
