#include<stdio.h>
#include<algorithm>
using namespace std;
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}
void exgcd(int a,int b,int&x,int&y){
	if(b==0){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int up(int a,int b){return a/b+(bool)(a%b);}
bool solve(int a,int b,int c){
	int g,x,y,k;
	g=gcd(a,b);
	if(c%g)return 0;
	a/=g;
	b/=g;
	exgcd(a,b,x,y);
	x*=c/g;
	y*=c/g;
	if(x<0){
		k=up(-x,b);
		x+=k*b;
		y-=k*a;
	}
	if(y<0){
		k=up(-y,a);
		y+=k*a;
		x-=k*b;
	}
	return x>=0&&y>=0;
}
bool solve4(int a,int b,int c,int d){
	while(d>=0){
		if(solve(a,b,d))return 1;
		d-=c;
	}
	return 0;
}
bool solve5(int a,int b,int c,int d,int e){
	for(int i=0;i<=e;i++){
		if(solve(a,b,i)&&solve(c,d,e-i))return 1;
	}
	return 0;
}
int a[110],b[110],M;
void work(){
	int n,i,j,k;
	bool flag;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	M=0;
	for(i=n;i>0;i--){
		flag=1;
		for(j=1;j<i;j++){
			if(a[i]%a[j]==0){
				flag=0;
				goto end;
			}
		}
		for(j=1;j<i-1;j++){
			for(k=j+1;k<i;k++){
				if(solve(a[j],a[k],a[i])){
					flag=0;
					goto end;
				}
			}
		}
		end:if(flag)b[++M]=a[i];
	}
	n=M;
	sort(b+1,b+n+1);
	if(n<=3){
		printf("%d\n",n);
		return;
	}
	if(n==4){
		printf("%d\n",n-solve4(b[1],b[2],b[3],b[4]));
		return;
	}
	if(n==5){
		if(solve4(b[1],b[2],b[3],b[5])||solve4(b[1],b[2],b[4],b[5])
		 ||solve4(b[1],b[3],b[4],b[5])||solve4(b[2],b[3],b[4],b[5]))n--;
		if(n==5&&solve4(b[1],b[2],b[3],b[4])){
			swap(b[4],b[5]);
			n--;
		}
		if(n==5)n-=solve5(b[1],b[2],b[3],b[4],b[5]);
		printf("%d\n",n);
		return;
	}
	printf("%d\n",n);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)work();
}
