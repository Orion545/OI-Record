#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,lim[2010],f[2010],g[2010];char s[2010];
int main(){
	n=read();m=read();int i,j,k,tmp;
	for(i=n;i>=1;i--){
		scanf("%s",s);
		for(j=0;j<m;j++) if(s[j]=='*'&&lim[j+1]==0) lim[j+1]=i;
	}
//	for(i=1;i<=m;i++) cout<<"lim "<<i<<' '<<lim[i]<<'\n';
	for(i=0;i<=lim[1];i++) f[i]=(i+1)>>1;
	for(i=2;i<=m;i++){
		g[0]=f[lim[i-1]];k=1;
		for(j=1;j<=lim[i];j++){
			g[j]=1e9;
			for(k--;k<=j/2;k++){
				tmp=f[max(lim[i-1]+3*k-2*j,0)]+j-k;
				if(g[j]>tmp) g[j]=tmp;
				else break;
			}
//			cout<<"dp "<<i<<' '<<j<<' '<<g[j]<<'\n';
		}
		memcpy(f,g,sizeof(g));
	}
	cout<<f[lim[m]]<<'\n';
}
