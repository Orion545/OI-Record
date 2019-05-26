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
int main(){
	int n=read();int i,m=(n-2)/2,mm=n-2-m;
	if(n<6){
		printf("-1\n");goto second;
	}
	printf("1 2\n");
	for(i=1;i<=m;i++) printf("1 %d\n",2+i);
	for(i=1;i<=mm;i++) printf("2 %d\n",2+m+i);
	second:
	for(i=1;i<n;i++){
		printf("%d %d\n",i,i+1);
	}
}
