#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 25500
#define ll long long
ll a[110],c[110],n,TAT,l,r,ans,pd[N],R;
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
void rpr(){
	ll tot;
	a[tot=1]=c[1];
	for(int i=2;i<=n;++i){
		int F=1;
		for(int j=1;j<=tot;++j)if(c[i]%a[j]==0){
			F=0;break;
		}
		if(F)a[++tot]=c[i];
	}
	n=tot;
}
ll g(ll a,ll b){
	if(!a)return b;
	return g(b%a,a);
}
void pre(){
	ll G=a[1];
	for(int i=2;i<=n;++i)G=g(G,a[i]);
	for(int i=1;i<=n;++i)a[i]/=G;	
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	rd(TAT);
	while(TAT--){
		rd(n);
		for(int i=1;i<=n;++i)rd(c[i]);
		sort(c+1,c+n+1);
		rpr();
		pre();
		if(n==1||a[1]==1){printf("%d\n",1);continue;}
		l=a[1],r=a[n];
		ans=0;
		for(int i=l;i<=r;++i)pd[i]=0;
		for(int i=1;i<=n;++i){
			if(!pd[a[i]]){
				++ans;
				pd[a[i]]=1;
				R=r-a[i];
				for(int j=l;j<=R;++j)if(pd[j])pd[j+a[i]]=1;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
}

