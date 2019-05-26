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
int n,a,b;
int main(){
	n=read();a=read();b=read();
	int i,j,t1,t2;
	if(min(a,b)!=1){
		puts("NO");return 0;
	}
	if(a==1&&b==1){
		if(n==2||n==3){
			puts("NO");return 0;
		}
		puts("YES");
		for(i=1;i<=n;i++){
			t1=i+1;
			t2=i-1;
			for(j=1;j<=n;j++){
				if(j==t1||j==t2) putchar('1');
				else putchar('0');
			}
			puts("");
		}
		return 0;
	}
	if(a==1){
		puts("YES");
		putchar('0');
		for(i=2;i<=n;i++){
			if((i-1)<=(n-b)) putchar('0');
			else putchar('1');
		}
			puts("");
		for(i=2;i<=n;i++){
			if((i-1)<=(n-b)) putchar('0');
			else putchar('1');
			for(j=2;j<=n;j++){
				if(j==i) putchar('0');
				else putchar('1');
			}
			puts("");
		}
	}
	else{
		puts("YES");
		putchar('0');
		for(i=2;i<=n;i++){
			if((i-1)<=(n-a)) putchar('1');
			else putchar('0');
		}
			puts("");
		for(i=2;i<=n;i++){
			if((i-1)<=(n-a)) putchar('1');
			else putchar('0');
			for(j=2;j<=n;j++) putchar('0');
			puts("");
		}
	}
} 
