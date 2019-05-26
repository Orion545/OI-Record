#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
char s[1010];int a[1010][10];
int main(){
	scanf("%s",s);int n=strlen(s),i,cnt[10];
	if(n<=2){
		puts("No");return 0;
	}
//	if(s[0]!='.') cnt[s[0]-'A'+1]++;
//	if(s[1]!='.') cnt[s[1]-'A'+1]++;
//	if(s[2]!='.') cnt[s[2]-'A'+1]++;
//	if(cnt[1]&&cnt[2]&&cnt[3]){
//		puts("Yes");return 0;
//	}
//	for(i=3;i<n;i++){
//		if(s[i-3]!='.') cnt[s[i-3]-'A'+1]--;
//		if(s[i]!='.') cnt[s[i]-'A'+1]++;
//		if(cnt[1]&&cnt[2]&&cnt[3]){
//			puts("Yes");return 0;
//		}
//	}
	for(i=0;i<n;i++){
		if(s[i]=='.') continue;
		a[i][s[i]-'A'+1]++;
		a[i+1][s[i]-'A'+1]++;
		a[i+2][s[i]-'A'+1]++;
	}
	for(i=1;i<=n;i++){
		if(a[i][1]&&a[i][2]&&a[i][3]){
			puts("Yes");return 0;
		}
	}
	puts("No");
} 
