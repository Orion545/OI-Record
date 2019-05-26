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
int n,cnt[1010][30],pre[1010][30];
char s[1010];
int main(){
	n=read();scanf("%s",s);int i,j,k;
	for(i=0;i<n;i++){
		cnt[i+1][s[i]-'a']++;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++){
			pre[i][j]=pre[i-1][j]+cnt[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			bool flag=1;
			for(k=0;k<26;k++){
				if(pre[j][k]-pre[i-1][k]>((j-i+1)/2)) flag=0;
			}
			if(flag){
				puts("YES");
				for(k=i-1;k<j;k++) putchar(s[k]);
				return 0;
			}
		}
	}
	puts("NO");
}
