#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n,m,c[510];
long double a[510][510];
int main(){
	n=read();m=read();int i,j,k,cnt=0,num,cur=0;long double tmp;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) a[i][j]=read();
	for(i=1;i<=n;i++) c[i]=read();
	c[0]=1e9;int ans=0;
	for(i=1;i<=n;i++){
		num=0;
		for(j=cur+1;j<=n;j++) if(fabs(a[j][i])>1e-5&&c[num]>c[j]) num=j;
		if(num==0) continue;
		cur++;ans+=c[num];cnt++;
//		cout<<cur<<' '<<num<<' '<<ans<<'\n';
		swap(a[cur],a[num]);swap(c[cur],c[num]);
		for(j=1;j<=n;j++){
			if(cur==j||fabs(a[j][i])<1e-5) continue;
			tmp=a[j][i]/a[cur][i];
			for(k=i;k<=m;k++){
				a[j][k]-=tmp*a[cur][k];
			}
		}
	}
	cout<<cnt<<' '<<ans<<'\n';
}
