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
ll f[1010][1010],g[1010],w[110],c[110],n,m,lim;
//currently time i, have j, produces f[i][j] every second
//used i at a moment, receiving productivity raise of g[i]
int main(){
	n=read();m=read();lim=read();
	if(m>=lim){
		puts("0");
		return 0;
	}
	ll i,j,k,tmp;
	for(i=1;i<=n;i++) c[i]=read(),w[i]=read();
	memset(g,-1,sizeof(g));
	g[0]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=lim;j++){
			if(j>=c[i]&&(~g[j-c[i]])){
				g[j]=max(g[j],g[j-c[i]]+w[i]);
			}
		}
	}
	memset(f,-1,sizeof(f));
	f[0][m]=0;
	for(i=0;i<=1000;i++){
		if(~f[i][lim]){
			cout<<i<<'\n';
			return 0;
		}
		for(j=1;j<=lim;j++){
			if(f[i][j]==-1) continue;
			for(k=0;k<=j;k++){
				//time i, have j, uses k to buy
				if(g[k]==-1) continue;
//				cout<<"check "<<i<<' '<<j<<' '<<k<<' '<<f[i][j]<<' '<<g[k]<<'\n';
				tmp=j-k+g[k]+f[i][j];
				if(tmp>=lim){
					cout<<i+1<<'\n';
					return 0;
				}
				f[i+1][tmp]=max(f[i+1][tmp],f[i][j]+g[k]);
			}
		}
	}
}
