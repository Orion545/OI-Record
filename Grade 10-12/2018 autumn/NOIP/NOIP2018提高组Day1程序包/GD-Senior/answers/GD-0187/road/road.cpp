#include<bits/stdc++.h>
using namespace std;
int n,last;long long ans;
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
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	last=0;
	for(int i=1;i<=n;i++){
		int now=read();
		if(now>last)ans+=now-last;
		last=now;
	}
	cout<<ans;
	return 0;
}
