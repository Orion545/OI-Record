#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 100010
#define ll long long
ll n,m,pre,ans,d[N];
void rd(ll &x){
	static char ch;ll F=1;
	while(!isdigit(ch=getchar()))if(ch=='-')F=-1;
	for(x=0;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	x*=F;
}
void rd(int &x){
	static ll T_T;
	rd(T_T);x=T_T;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	rd(n);
	ll pre=0;
	ll tag=1;
	for(int i=1;i<=n;++i){
		rd(d[i]);
		if(d[i]>=d[i-1]&&tag==1)continue;
		if(d[i]<=d[i-1]&&tag==0)continue;
		if(d[i]>d[i-1]&&tag==0){
			pre=d[i-1];
			tag=1;
		}
		if(d[i]<d[i-1]&&tag==1){
			ans+=d[i-1]-pre;
			tag=0;
		}
	}
	if(tag==1)ans+=d[n]-pre;
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
}
