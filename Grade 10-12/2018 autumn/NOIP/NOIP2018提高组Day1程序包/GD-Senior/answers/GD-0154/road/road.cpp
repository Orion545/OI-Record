#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define N 100010
#define P(a) putchar(a)
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int a[N];
int i,j,k,l,n,m,ans;
int read(){
	int rs=0,fh=0;char ch=0;
	while((ch<'0'||ch>'9')&&(ch^'-'))ch=getchar();
	if(ch=='-')fh=1,ch=getchar();
	while(ch>='0'&&ch<='9')rs=(rs<<3)+(rs<<1)+(ch^'0'),ch=getchar();
	return fh?-rs:rs;
}
void write(int x){
	if(x>9)write(x/10);
	P(x%10+'0');
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	fo(i,1,n)a[i]=read();
	fo(i,1,n)if(a[i]<a[i-1])ans=ans+a[i-1]-a[i];
	ans=ans+a[n];
	write(ans);
	return 0;
}
