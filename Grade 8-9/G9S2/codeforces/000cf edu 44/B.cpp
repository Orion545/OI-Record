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
int n,m,cnt[2010],a[2010][2010];
char s[2010];
int main(){
	n=read();m=read();int i,j;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++) a[i][j+1]=(s[j]=='1'),cnt[j+1]+=a[i][j+1];
	}
	for(i=1;i<=n;i++){
		int flag=1;
		for(j=1;j<=m;j++) if(a[i][j]==1&&cnt[j]==1){
			flag=0;break;
		}
		if(flag){
			puts("YES");return 0;
		}
	}
	puts("NO");
}
