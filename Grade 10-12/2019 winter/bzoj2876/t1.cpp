#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n;
double eu,s[10010],v[10010],k[10010],vp[10010];
bool check(long double lambda){
	int i,j;long double l,r,mid,sum=0;
//	cout<<"check "<<lambda<<'\n';
	for(i=1;i<=n;i++){
		l=max((double)0.0,vp[i]);r=1e9;v[i]=l;
		while(l<=r){
			mid=(l+r)*0.5;
			if(2*k[i]*lambda*mid*mid*(mid-vp[i])>=-1) l=mid+1e-17,v[i]=mid;
			else r=mid-1e-17;
		}
//		cout<<"	get "<<i<<' '<<v[i]<<' '<<vp[i]<<'\n';
		sum+=k[i]*s[i]*(v[i]-vp[i])*(v[i]-vp[i]);
	}
//	cout<<"get sum "<<sum<<'\n';
	return sum<=eu;
}
int main(){
	n=read();int i;long double l,r,mid,lambda;
	scanf("%lf",&eu);
	for(i=1;i<=n;i++){
		scanf("%lf",&s[i]);
		scanf("%lf",&k[i]);
		scanf("%lf",&vp[i]);
	}
	l=-1e9;r=0;
	while(l<=r){
		mid=(l+r)*0.5;
		if(check(mid)) l=mid+1e-17,lambda=mid;
		else r=mid-1e-17;
	}
	check(lambda);
	long double ans=0;
	for(i=1;i<=n;i++) ans+=(s[i]/v[i]);
	printf("%.8lf\n",(double)ans);
}
