#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000009LL
using namespace std;
int n,m,f[200100];
int find(int x){
	return ((f[x]==x)?x:f[x]=find(f[x]));
}
int read(){
	int re=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		re=re*10+(int)(ch-'0');ch=getchar();
	}
	return re;
}
void put(long long x){
	char s[100];int cnt=0;
	if(x==0) putchar('0');
	else{
		while(x){
			s[++cnt]=(char)(x%10+48);
			x/=10;
		}
	}
	while(cnt) putchar(s[cnt--]);
	putchar('\n');
}
int main(){
	freopen("magician.in","r",stdin);
	freopen("magician.out","w",stdout);
	int i,x,y,fx,fy;
	long long ans=0;
	n=read();m=read();
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++){
		x=read();y=read();
		fx=find(x);fy=find(y);
		if(fx==fy){
			ans=((ans*2)%mod+1LL)%mod;
			put(ans);
		}
		else{
			f[fx]=fy;
			put(ans);
		}
	}
} 
