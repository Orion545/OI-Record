#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<ctime>
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
int random(int l,int r){
	return rand()%(r-l+1)+l;
}
int n=80000,base[100010];
int main(){
	srand(time(NULL));
	printf("%d\n",n);int i;
	for(i=1;i<=n;i++) base[i]=random(1,1000000),printf("%d ",base[i]);
	puts("");
	for(i=1;i<=n;i++) printf("%d ",random(0,base[i]-1));
	puts("");
} 
