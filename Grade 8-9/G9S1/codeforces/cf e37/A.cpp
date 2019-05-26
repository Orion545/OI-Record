#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,x[210];
int main(){
	int i,j,T=read(),ans;
	while(T--){
		n=read();m=read();ans=1;
		for(i=1;i<=m;i++){
			x[i]=read();
			if(i>1) ans=max(ans,(x[i]-x[i-1])/2+1);
		}
		ans=max(ans,(n-x[m]+1));ans=max(ans,x[1]);
		cout<<ans<<endl;
	}
} 
