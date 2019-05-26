#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct ele{
	ll a[10];
	ele(){memset(a,0,sizeof(a));}
	friend ele operator +(ele a,ele b){
		ele re;
		for(ll i=0;i<10;i++) re.a[i]=a.a[i]+b.a[i];
		return re;
	}
	void show(){for(ll i=0;i<10;i++) cout<<a[i]<<' ';cout<<'\n';}
}f[30][10];
ll a,b,t[30];
ele solve(ll x){
//	cout<<"solve "<<x<<'\n';
	ele re;
	if(!x){re.a[0]=1;return re;}
	ll len=12,i,j;
	while(t[len]>x) len--;
	for(i=1;i<len;i++){
		for(j=1;j<10;j++) re=re+f[i][j];
	}
	re.a[0]++;
//	re.show();
	ll cur=x/t[len];
//	cout<<"cur "<<cur<<'\n';
	for(i=1;i<cur;i++) re=re+f[len][i];
	x%=t[len];
	re.a[cur]+=x+1;
//	re.show();
	for(i=len-1;i;i--){
		cur=x/t[i];
		for(j=0;j<cur;j++) re=re+f[i][j];
		x%=t[i];
		re.a[cur]+=x+1;
//	re.show();
	}
	return re;
}
int main(){
	a=read();b=read();ll i,j,k;
	t[1]=1;
	for(i=2;i<=15;i++) t[i]=t[i-1]*10ll;
	for(i=0;i<10;i++) f[1][i].a[i]=1;
	for(i=2;i<=12;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				f[i][k]=f[i][k]+f[i-1][j];
				f[i][k].a[k]+=t[i-1];
			}
		}
//		for(j=0;j<10;j++) cout<<i<<' '<<j<<' ',f[i][j].show();
	}
	ele t1=solve(b),t2=solve(a-1);
	for(i=0;i<10;i++) cout<<t1.a[i]-t2.a[i]<<' ';
	cout<<'\n';
}
