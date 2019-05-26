#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 1e9
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int x,cnt=0,a[20],tot,ans=inf;
int main(){
	x=read();int i,j,tmp,tt,t,tcnt;
	while(x){
		a[++cnt]=x%10;x/=10;
	}
	tot=(1<<cnt);
	for(i=1;i<=tot-1;i++){
		tmp=0;tcnt=0;
		for(j=cnt;j>=1;j--){
			if(i&(1<<(j-1))){
				if(!tcnt) tt=a[j];
				tmp=tmp*10+a[j],tcnt++;
			}
		}
		if(!tt) continue;
//		cout<<i<<ends<<tmp<<ends<<tcnt<<endl;
		t=(int)sqrt(tmp);
		if(t*t==tmp) ans=min(ans,cnt-tcnt);
	}
	if(ans!=inf) cout<<ans<<endl;
	else cout<<-1<<endl;
}

