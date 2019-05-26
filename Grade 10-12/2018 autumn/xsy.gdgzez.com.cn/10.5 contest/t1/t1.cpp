#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<bitset>
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
bitset<1010>s[1010];
int main(){
	int T=read(),n,cases=0;
	while(T--){
		cases++;
		n=read();int i,j,cnt,tmp;
		for(i=1;i<=n;i++){
			s[i].reset();s[i][i]=1;
			cnt=read();
			for(j=1;j<=cnt;j++){
				tmp=read();
				s[i][tmp]=1;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(s[j][i]) s[j]|=s[i];
			}
		}
		double ans=0;
		for(i=1;i<=n;i++){
			cnt=0;
			for(j=1;j<=n;j++) cnt+=(s[j][i]==1);
//			cout<<i<<' '<<cnt<<'\n';
			ans+=(double)(1.0/(double(cnt)));
		}
		printf("Case #%d: %.5lf\n",cases,ans);
	}
}
