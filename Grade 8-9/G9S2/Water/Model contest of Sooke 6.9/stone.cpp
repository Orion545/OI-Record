#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define log log_2
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
int st[1000010][25],log[1000010],n;
void init(){
	int i,j=1;
	for(i=2;i<=n;i++){
		if(i==(j<<1)) log[i]=log[j]+1,j=i;
		else log[i]=log[j];
	}
	for(j=1;j<=20;j++){
		for(i=1;i+(j<<1)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r){
	int k=log[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	n=read();int i,l,r,mid,ans=0;
	for(i=1;i<=n;i++) st[i][0]=read();
	init();
	for(i=1;i<=n;i++){
		l=0,r=min(i-1,n-i);
		while(l<r){
			mid=(l+r)>>1;mid++;
			if(query(i-mid,i+mid)==st[i][0]) l=mid;
			else r=mid-1;
		}
		ans=max(ans,(l<<1)+1);
	}
	printf("%d\n",ans);
}
