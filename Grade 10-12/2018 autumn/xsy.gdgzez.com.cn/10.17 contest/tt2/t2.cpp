#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
using namespace std;
inline int read(int &x){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	x=re*flag;
}

int n,t,v[110],top;
int x[200010],le[20][200010],ri[20][200010],f[1000010],g[1000010];
int ans[1000010];
int main(){
	read(n);read(t);int i,j,s;
	for(i=1;i<=n;i++) read(x[i]);
	v[0]=t;t>>=1;
	while(t){
		v[++top]=t;
		t>>=1;
	}
	v[++top]=0;
	reverse(v,v+top+1);
	for(i=0;i<=top;i++){
		le[i][1]=1;
		for(j=2;j<=n;j++){
			if(x[j]-x[j-1]<=v[i]) le[i][j]=le[i][j-1];
			else le[i][j]=j;
		}
		ri[i][n]=n;
		for(j=n-1;j>=1;j--){
			if(x[j+1]-x[j]<=v[i]) ri[i][j]=ri[i][j+1];
			else ri[i][j]=j;
		}
//		for(j=1;j<=n;j++) cout<<"check "<<i<<' '<<j<<' '<<le[j][i]<<' '<<ri[j][i]<<'\n';
	}
	f[0]=0;g[0]=n+1;
	for(s=1;s<=(1<<(top))-1;s++){
		f[s]=0;g[s]=n+1;
		for(i=0;i<=top;i++){
			if(s&(1<<i)){
				j=s^(1<<i);
				if(f[j]==n) f[s]=n;
				else f[s]=max(f[s],ri[i][f[j]+1]);
				if(g[j]==1) g[s]=1;
				else g[s]=min(g[s],le[i][g[j]-1]);
			}
		}
//		cout<<"dp "<<s<<' '<<f[s]<<' '<<g[s]<<'\n';
	}
	for(i=0;i<=n;i++) ans[i]=n+2;
	for(i=0;i<=((1<<top)-1);i++){
		j=((1<<top)-1)^i;
		ans[f[i]]=min(ans[f[i]],g[j]);
	}
	for(i=n-1;i>=0;i--) ans[i]=min(ans[i],ans[i+1]);
	for(i=1;i<=n;i++){
		if(ans[le[top][i]-1]<=ri[top][i]+1) puts("Possible");
		else puts("Impossible");
	}
}

