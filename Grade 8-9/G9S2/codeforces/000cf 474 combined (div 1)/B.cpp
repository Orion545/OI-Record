#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,k1,k2,a[1010],b[1010]; 
priority_queue<ll>q;
int main(){
	n=read();k1=read();k2=read();ll i,tmp;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++) b[i]=read(),q.push(abs(a[i]-b[i]));
	for(i=1;i<=k1+k2;i++){
		tmp=q.top();q.pop();
//		cout<<i<<ends<<tmp<<endl;
		if(tmp==0){
			printf("%d",(k1+k2-i+1)%2);return 0;
		}
		tmp--;q.push(tmp);
	}
	ll ans=0;
	while(!q.empty()){
		tmp=q.top();q.pop();
		ans+=tmp*tmp;
	}
	cout<<ans<<endl;
}

