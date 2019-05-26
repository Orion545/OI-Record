#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long double
ll k,d,t,tot,ans,tt;
int main(){
	cin>>k>>d>>t;ll tmp=k;
	tmp=fmod(tmp,d);if(!tmp) tmp=d;
	tot=(d-tmp)*0.5+k*1.0;tt=(d-tmp)+k;
//	cout<<"tot: "<<tot<<ends<<tt<<endl;
//	while(t>tot) ans+=tt,t-=tot,cout<<"cnt\n";
	ans+=(t-fmod(t,tot))/tot*tt;t=fmod(t,tot);
//	cout<<"tans "<<ans<<ends<<t<<endl; 
	if(t<=k) ans+=t;
	else ans+=k,t-=k,ans+=t*2.0;
	cout<<ans<<"\n";
}
