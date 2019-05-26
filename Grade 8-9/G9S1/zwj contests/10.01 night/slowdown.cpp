#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef double ll;
int n,cnts=0,cntt=0;
ll s[10005],t[10005];
int main(){
	freopen("slowdown.in","r",stdin);
	freopen("slowdown.out","w",stdout);
	scanf("%d",&n);
	char aa[2];
	for(int i=1,x;i<=n;i++){
		scanf("%s%d",&aa,&x);
		if(aa[0]=='T') t[++cntt]=x;
		if(aa[0]=='D') s[++cnts]=x;
	}
	s[++cnts]=1000;
	sort(t+1,t+cntt+1);
	sort(s+1,s+cnts+1);
	int S=1,T=1;
	ll ans=0,pos=0,v=1;
	for(int i=1;i<=n+1;i++,v++){
		if((S==cnts+1||(s[S]-pos)*v+ans>t[T])&&T<=cntt){
			pos+=(t[T]-ans)/v;
			ans=t[T];
			T++;
		}
		else{
			ans+=(s[S]-pos)*v;
			pos=s[S];
			S++;
		}
	}
	double o=ans;
	printf("%.0lf",o);
	return 0;
} 
