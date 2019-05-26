#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int X,n,rev[100010],val[100010],l[100010],r[100010],ans0[100010],ans1[100010],ch[100010];
int main(){
	X=read();n=read();int i,tmp=1,t,a,ans,pos;
	val[i]=0;
	for(i=1;i<=n;i++){
		rev[i]=read();
		ch[i]=tmp*(rev[i]-rev[i-1]);
		val[i]=val[i-1]-ch[i];
		tmp=-tmp;
//		cout<<i<<' '<<val[i]<<'\n';
	}
	rev[n+1]=2e9; 
	l[0]=0;r[0]=X;
	for(i=1;i<=n;i++){
		l[i]=max(l[i-1],-val[i]);
		r[i]=min(r[i-1],X-val[i]);
//		cout<<i<<' '<<l[i]<<' '<<r[i]<<'\n';
	}
	ans0[0]=0;ans1[0]=X;
	for(i=1;i<=n;i++){
		ans0[i]=min(X,max(0,ans0[i-1]-ch[i]));
		ans1[i]=max(0,min(X,ans1[i-1]-ch[i]));
//		cout<<i<<' '<<ans0[i]<<' '<<ans1[i]<<'\n';
	}
	int Q=read();
	while(Q--){
		t=read();a=read();
		pos=lower_bound(rev+1,rev+n+1,t)-rev;
		if(rev[pos]>t) pos--;
//		cout<<"query "<<t<<' '<<a<<' '<<pos<<' '<<rev[pos]<<' '<<l[pos]<<' '<<r[pos]<<' '<<ans0[pos]<<' '<<ans1[pos]<<'\n'; 
		if(a<l[pos]) ans=ans0[pos];
		if(a>r[pos]) ans=ans1[pos];
		if(a>=l[pos]&&a<=r[pos]) ans=a+val[pos];
//		cout<<"tmpquery "<<t<<' '<<rev[pos]<<' '<<ans<<'\n'; 
		ans+=(t-rev[pos])*((pos&1)?1:-1);
		printf("%d\n",min(X,max(ans,0)));
	}
} 
