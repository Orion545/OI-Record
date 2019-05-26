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
int n,a[200010],pos[200010],b[200010];
int main(){
	n=read();int i,cur=0;
	for(i=1;i<=n;i++){
		a[i]=read();
		pos[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		b[i]=read();
		if(pos[b[i]]>cur){
			printf("%d ",pos[b[i]]-cur);
			cur=pos[b[i]];
		}
		else{
			printf("0 ");
		}
	}
}
