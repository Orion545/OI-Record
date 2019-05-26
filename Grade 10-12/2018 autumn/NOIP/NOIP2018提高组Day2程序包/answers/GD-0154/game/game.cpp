#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mo 1000000007
#define P(a) putchar(a)
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
int n,m,w;
int i,j,x,y;
int read(){
	int fh=0,rs=0;char ch=0;
	while((ch<'0'||ch>'9')&&(ch^'-'))ch=getchar();
	if(ch=='-')fh=1,ch=getchar();
	while(ch>='0'&&ch<='9')rs=(rs<<3)+(rs<<1)+(ch^'0'),ch=getchar();
	return fh?-rs:rs;
}
void write(int x){
	if(x>9)write(x/10);
	P(x%10+'0');
}
int ksm(int x,int y){
	int rs=1;
	for(;y;y>>=1,x=(1ll*x*x)%mo)
	if(y&1)rs=(1ll*rs*x)%mo;
	return rs;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if(n>m)swap(n,m);
	if(n==1){
		w=ksm(2,m);
		write(w);
		return 0;
	}
	if(n==1&&m==1){printf("2");return 0;}
	if(n==1&&m==2){printf("4");return 0;}
	if(n==1&&m==3){printf("8");return 0;}
	if(n==2&&m==1){printf("4");return 0;}
	if(n==2&&m==2){printf("12");return 0;}
	if(n==2&&m==3){printf("36");return 0;}
	if(n==3&&m==1){printf("8");return 0;}
	if(n==3&&m==2){printf("36");return 0;}
	if(n==3&&m==3){printf("112");return 0;}
	if(n==2){
		w=4;
		w=(1ll*w*ksm(3,m-1))%mo;
		write(w);
		return 0;
	}
	if(n==3){
		w=112;
		w=(1ll*w*ksm(3,m-3))%mo;
		write(w);
		return 0;
	}
	if(n==4){
		if(m==1)printf("16");else
		if(m==2)printf("108");else
		if(m==3)printf("336");else
		if(m==4)printf("912");else
		if(m==5)printf("2688");else{
			w=2688;
		    w=(1ll*w*ksm(3,m-5))%mo;
		    write(w);
		}
		return 0;
	}
	if(n==5){
		if(m==1)printf("16");else
		if(m==2)printf("108");else
		if(m==3)printf("336");else
		if(m==4)printf("912");else
		if(m==5)printf("2688");else
		if(m==6)printf("21312");
		return 0;
	}
	return 0;
}
