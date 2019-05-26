#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n=2000,tmp;
int main(){
	srand(time(NULL));
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		tmp=(rand()*rand()%100000000);
		while(tmp==0) tmp=(rand()*rand()%100000000);
		printf("%d\n",tmp);
	}
}

