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
int le[2000010],*f,ri[2000010],*g,n,m,hit[1000010],pre[1000010],suf[2000010],dead[1000010];
int main(){
	n=read();m=read();int i,j;
	for(i=1;i<=m;i++) hit[i]=read();
	f=le+n+1;g=ri+n+1;
	for(i=1;i<=n;i++) f[i]=g[i]=i;
	for(i=1;i<=m;i++){
//		cout<<"process "<<i<<' '<<hit[i]<<' '<<n-f[n-hit[i]+1]+1<<' '<<g[hit[i]]<<'\n';
//		for(j=1;j<=n;j++) cout<<j<<' '<<f[j]<<' '<<g[j]<<'\n';
		f[(n-hit[i]+1)-2]=f[n-hit[i]+1];
		g[hit[i]-2]=g[hit[i]];
		if(n-f[n-hit[i]+1]+1<=g[hit[i]]){
			dead[n-f[n-hit[i]+1]+1]++;
			dead[g[hit[i]]+2]--;
		}
		f--;f[n-1]=f[n+1];
		g--;g[n-1]=g[n+1];
	}
	int sum[2]={0};
//	for(i=1;i<=n;i++) cout<<i<<' '<<f[i]<<'\n';
//	for(i=1;i<=n;i++) cout<<i<<' '<<g[i]<<'\n';
	for(i=n;i>=1;i--)
		for(j=g[i];j>g[i-2];j-=2) 
			suf[j]=i;
	for(i=n;i>=1;i--)
		for(j=f[i];j>f[i-2];j-=2)
			pre[j]=n-i+1;
	reverse(pre+1,pre+n+1);
//	for(i=1;i<=n;i++) cout<<dead[i]<<' ';
//	cout<<'\n';
	for(i=1;i<=n;i++){
		sum[i&1]+=dead[i];
		if(!sum[i&1]&&pre[i]<=suf[i]) printf("%d ",(suf[i]-pre[i])/2+1);
		else printf("0 ");
	}
}
