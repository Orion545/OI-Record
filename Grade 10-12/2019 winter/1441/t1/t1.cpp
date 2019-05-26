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
ll n,k,h[100010];
struct node{
	ll h,l,re;
}s[100010],cur;ll top,ans;
int main(){
	n=read();k=read();ll i,re,left,dis,cnt;ll S;
	for(i=1;i<=n;i++) h[i]=read();
	s[++top]=(node){0,0,0};
	for(i=1;i<=n+1;i++){
		re=0,left=i;
		while(top>1&&s[top].h>=h[i]){
			cur=s[top--];
			cur.re+=re;
			left=cur.l;
			dis=max(s[top].h,h[i]);
			S=1ll*(cur.h-dis)*(i-cur.l)-cur.re;
			if(S<=0) re=-S;
			else{
				cnt=(S-1)/k+1;
				ans+=cnt;
				re=k*cnt-S;
			}
		}
		s[++top]=(node){h[i],left,re};
	}
	cout<<ans<<'\n';
}
