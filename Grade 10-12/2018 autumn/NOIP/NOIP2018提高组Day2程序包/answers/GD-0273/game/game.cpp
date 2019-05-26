#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
typedef long long LL;
const LL mod=1e9+7;
using namespace std;
int read(){
	int ans=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-48;c=getchar();}
	return ans*f;
}
LL ksm(LL a,LL b){
	LL res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n=read(),m=read();
	if(n==1||m==1){printf("%lld",ksm(2,m));return 0;}
	if(n==2)printf("%lld",ksm(3,m-1)*4%mod);
	else printf("%lld",(ksm(2,m+3)+48)%mod);
	fclose(stdin);fclose(stdout);
	return 0;
}
