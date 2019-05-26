#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<map>
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
int sum,n,m,yy1,yy2,a[100010],b[100010];
map<int,int>s1,s2;
int main(){
	n=read();yy1=read();int i,j,len,tmp;
	for(i=1;i<=n;i++) a[i]=read();
	m=read();yy2=read();
	for(i=1;i<=m;i++) b[i]=read();
	int ans=0;
	for(j=1;j<=30;j++){
		len=(1<<j);
		s1.clear(),s2.clear();
		for(i=1;i<=n;i++){
			tmp=a[i]%len;
			if(s1.count(tmp)) s1[tmp]++;
			else s1[tmp]=1;
		}
		for(i=1;i<=m;i++){
			tmp=b[i]%len;
			if(s2.count(tmp)) s2[tmp]++;
			else s2[tmp]=1;
		}
		tmp=len;tmp>>=1;
		for(i=1;i<=n;i++){
			sum=s2.count((a[i]+tmp)%len)?s2[(a[i]+tmp)%len]:0;
			ans=max(ans,s1[a[i]%len]+sum);
		}
		for(i=1;i<=m;i++){
			sum=s1.count((b[i]+tmp)%len)?s1[(b[i]+tmp)%len]:0;
			ans=max(ans,sum+s2[b[i]%len]);
		}
	}
	cout<<ans<<'\n';
}
