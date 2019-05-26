#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;
#define fo(i,a,b) for(i=a;i<=b;i++)
const int N=105,MX=25005;
int cas,n,i,j,a[N],ans;
bool P[MX];
int read(){
	char c=getchar(); int x=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+(c-'0');
	return x;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	cas=read();
	while(cas--){
		memset(P,0,sizeof(P));ans=0;
		n=read();fo(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
		P[0]=1;
		fo(i,1,n){
			if(P[a[i]]) continue;
			ans++;
			fo(j,0,a[n]-a[i])if(P[j])P[j+a[i]]=1;
		}
		printf("%d\n",ans);
	}
}
