#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
}
void ex_gcd(int a, int b, int &d, int &x, int &y){
    if(!b){d=a;x=1;y=0;}
    else{
		ex_gcd(b,a%b,d,y,x); 
		y-=x*(a/b);
	}
} 
int main(){
	freopen("pour.in","r",stdin);
	freopen("pour.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int t=gcd(n,m),tt=t;
	int x,y;
	n/=t;m/=t;
	ex_gcd(n,m,t,x,y);
	while(x>0||y<0) x-=n,y+=m;
	while(x+n<=0&&y-m>=0) x+=n,y-=m;
	printf("%d\n%d %d",tt,-x,y);
}
