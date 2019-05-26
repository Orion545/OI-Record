#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int mo=1e9+7,mn=1e5+50;
int i,j,k,n,m,p,f[mn][9][9],F[9],ans,num,num1,num2,b;
int qs(int x,int y){
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%mo) if (y&1) s=(ll)s*x%mo;
	return s;
}
int pd(int x){
	if (x<n) return x+1;
	int p=n+m-2-x; 
	if (p<n) return p+1;
	return n; 
} 
void mod(int &x) {x-=x>=mo?mo:0;} 
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==1) return printf("%d\n",qs(2,m)),0;
	if (n==2) return printf("%d\n",(ll)4*qs(3,m-1)%mo),0;
	if (n==3) {
		if (m==1) puts("8");else
		if (m==2) puts("36");else
		printf("%d\n",(ll)112*qs(3,m-3)%mo);
		return 0;
	} 
	f[n+m-2][0][0]=4; 
	fd(i,n+m-3,1){
		num=pd(i),num1=pd(i+1),num2=pd(i+2),b=i+2<n?-1:(i<n?0:1); 
		memset(F,0,sizeof(F)); 
		fo(k,0,num2)if (!k||k==num2||k+b>=num){
			fo(j,0,num1) mod(F[j]+=f[i+1][j][k]);
		}else fo(j,0,num1) f[i][k+b][j]+=f[i+1][j][k];
		fo(j,0,num) fo(k,0,num1) mod(f[i][j][k]+=F[k]); 
	} 
	fo(j,0,num) fo(k,0,num1) mod(ans+=f[1][j][k]); 
	printf("%d\n",ans); 
	return 0; 
}
