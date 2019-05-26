#include<bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long ll;
inline int read(){
	int n=0,f=1;char c;
	for(c=getchar();c!='-'&&(c<'0'||c>'9');c=getchar());
	if (c=='-') c=getchar(),f=-1;
	for(;c>='0'&&c<='9';c=getchar()) n=n*10+c-48;
	return n*f;
}
const int maxn=25e3+5;
int T,i,j,x,n,num,mx,a[105],bz[maxn],bk;
int f[maxn],ans;
void work(){
	n=read(),num=mx=0,bk++;
	fo(i,1,n) {
		j=read();
		if (bz[j]==bk) continue;
		a[++num]=j,bz[j]=bk;
		mx=max(mx,j);
	}
	fo(i,1,mx) f[i]=0;
	fo(i,1,num){
		x=a[i];
		fo(j,x,mx) f[j]+=f[j-x],f[j]=f[j]>1?2:f[j];
	}
	ans=0;
	fo(i,1,num) ans+=f[a[i]]==1;
	printf("%d\n",ans);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	f[0]=1;
	for(T=read();T--;) work();
	return 0;
}
