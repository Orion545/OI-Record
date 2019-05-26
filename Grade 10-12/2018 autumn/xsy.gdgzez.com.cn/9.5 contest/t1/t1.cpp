#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,hitc[1000010];
int l[1000010],r[1000010];
int main(){
	n=read();m=read();int i,j;
	for(i=1;i<=m;i++) hitc[i]=read();
	for(i=1;i<=n;i++){
		l[i]=r[i]=i;bool flag=1;
		for(j=1;j<=m;j++){
			if(hitc[j]==l[i]&&hitc[j]==r[i]){
				flag=0;break;
			}
			if(hitc[j]==l[i]) l[i]++,r[i]++;
			else {
				if(hitc[j]==r[i]) l[i]--,r[i]--;
				else if(hitc[j]!=l[i]&&hitc[j]!=r[i]) l[i]--,r[i]++;
			}
			if(r[i]>n) r[i]-=2;
			if(l[i]<1) l[i]+=2;
//			cout<<i<<' '<<j<<' '<<l[i]<<' '<<r[i]<<'\n';
		}
		if(!flag) printf("%d ",0);
		else printf("%d ",(r[i]-l[i])/2+1);
	}
	puts("");
}
