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
int len,a[10010],b[10010]={0};char s[10010];
int main(){
	freopen("bigint.in","r",stdin);
	freopen("bigint.out","w",stdout);
	scanf("%s",s);len=strlen(s);int i;
	for(i=0;i<len;i++) a[len-i]=(s[i]-'0');
	b[1]=8;b[2]=1;b[3]=0;b[4]=2;
	for(i=1;i<=len;i++){
		a[i]=a[i]+b[i];
		if(a[i]>=10) a[i+1]++,a[i]-=10;
	}
	if(a[len+1]) len++;
	for(i=len;i>=1;i--) printf("%d",a[i]);
}
