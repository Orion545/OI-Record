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
int n,a[2010];
int main(){
	srand(time(NULL));
	freopen("in.in","w",stdout);
	n=1000;int i;
	for(i=1;i<=n;i++) a[i]=rand();
	printf("%d\n",n);
	for(i=1;i<=n;i++) printf("%d ",a[i]);
}