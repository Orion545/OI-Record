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
int n,m,q,a[2010][2010],snode[2010][2010],sedge[2010][2010],le[2010][2010],up[2010][2010];
int main(){
	n=read();m=read();q=read();int i,j,l1,l2,r1,r2;char s[2010];
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=1;j<=m;j++){
			a[i][j]=(s[j-1]=='1');
			snode[i][j]=snode[i][j-1]+snode[i-1][j]-snode[i-1][j-1]+a[i][j];
			sedge[i][j]=sedge[i][j-1]+sedge[i-1][j]-sedge[i-1][j-1];
			if(a[i][j]) sedge[i][j]+=a[i][j-1]+a[i-1][j];
			up[i][j]=up[i][j-1]+(a[i][j]&a[i-1][j]);
			le[i][j]=le[i-1][j]+(a[i][j]&a[i][j-1]);
//			cout<<i<<' '<<j<<' '<<snode[i][j]<<' '<<sedge[i][j]<<'\n';
		}
	}
	while(q--){
		l1=read();r1=read();l2=read();r2=read();
		printf("%d\n",snode[l2][r2]-snode[l1-1][r2]-snode[l2][r1-1]+snode[l1-1][r1-1]-(sedge[l2][r2]-sedge[l1-1][r2]-sedge[l2][r1-1]+sedge[l1-1][r1-1])+(up[l1][r2]-up[l1][r1-1])+(le[l2][r1]-le[l1-1][r1]));
	}
}
