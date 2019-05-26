#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
int Ans[110],l,r;bool f[2500001];
priority_queue <int> q;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
bool judge(int x){
	memset(f,0,sizeof(f));
	for(int i=1;i<=ans;i++)if(x%Ans[i]==0)return false;
	f[0]=1;
	for(int i=1;i<=ans;i++){
	    for(int j=Ans[i];j<=x;j++){
	    	f[j]=(f[j]||f[j-Ans[i]]);
		}
	}
	return f[x]==1?false:true;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--){
		memset(Ans,0,sizeof(Ans));
		ans=0;
		n=read();
		if(n==2){
			int a=read(),b=read();
			if(a%b==0||b%a==0){cout<<1<<endl;}
			else cout<<2<<endl;
		}
		for(int i=1;i<=n;i++){
			int a=read();
			q.push(-a);
		}
		int x=-q.top();q.pop();Ans[++ans]=x;
		while(q.size()){
			int x=-q.top();q.pop();
			if(judge(x)){Ans[++ans]=x;}
		}
//		for(int i=1;i<=ans;i++)cout<<Ans[i]<<" ";cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
