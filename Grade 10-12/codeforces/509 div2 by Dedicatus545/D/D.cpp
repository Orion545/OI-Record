#include<iostream>
#include<cstring>
using namespace std;
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,h;

ll s[200010],XXXXX_f[200010],x2[200010],s2[200010],MMMMMMMM;


void getttt(){
	ll i;
	for(i=1;i<=n;i++){
		
		
		s[i]=s[i-1]+XXXXX_f[i]-x2[i-1];
		
		
		s2[i]=s2[i-1]+x2[i]-XXXXX_f[i];
	}
}

int main(){
	n=read();h=read(); MMMMMMMM=h;
	ll i,l,r,ans;
	
	for(i=1;i<=n;i++) {
		
		XXXXX_f[i]=read();
		
		
		x2[i]=read();
	}
	
	getttt();
	i=1;
	while(i<=n){
		s[i]=s[i-1]+XXXXX_f[i]-x2[i-1];
		
		
		s2[i]=s2[i-1]+x2[i]-XXXXX_f[i];
		
		i++;
	}
	
	ll mid;
	
	for(i=1;i<=n;i++){
		l=i;r=n;
		
		
		while(!(l>r)){
							mid=(l+r)>>1;
							
							
							
						if(s[mid]-s[i]<h) ans=mid,l=mid+1;
						else r=mid-1;
		}
		MMMMMMMM=max(MMMMMMMM,h+s2[ans]-s2[i-1]);
	}
	
	
											cout<<MMMMMMMM<<'\n';
}
