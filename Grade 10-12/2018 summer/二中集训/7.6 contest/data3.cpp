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
	freopen("data3.in","w",stdout);
	printf("300000 300000\n");
	for(int i=1;i<300000;i++) printf("%d %d\n",i,i+1);
	for(int i=1;i<=300000;i++) printf("%d %d\n",i,1);
}
