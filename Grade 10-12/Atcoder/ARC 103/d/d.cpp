#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,x[1010],y[1010];
int main(){
	std::ios::sync_with_stdio(false);
	n=read();int i,j,f0=0,f1=0;
	for(i=1;i<=n;i++){
		x[i]=read();y[i]=read();
		if((x[i]+y[i])&1)f1=max(f1,abs(x[i])+abs(y[i]));
		else f0=max(f0,abs(x[i])+abs(y[i]));
	}
	if(f0&&f1){
		puts("-1");return 0;
	}
	int m;m=max(f0,f1);
	if(m>40) return 0;
//	cout<<(m=max(f0,f1))<<'\n';
	printf("%d\n",m);
	for(i=1;i<=m;i++) printf("1 ");
	puts("");
	for(i=1;i<=n;i++){
		f0=(x[i]>0);
		for(j=1;j<=abs(x[i]);j++){
			if(f0) putchar('R');
			else putchar('L');
		}
		f0=(y[i]>0);
		for(j=1;j<=abs(y[i]);j++){
			if(f0) putchar('U');
			else putchar('D');
		}
//		cout<<abs(x[i])+abs(y[i])+1<<'\n';
		for(j=abs(x[i])+abs(y[i])+1;j<=m;j+=2){
			putchar('L');putchar('R');
		}
		putchar('\n');
	}
}
