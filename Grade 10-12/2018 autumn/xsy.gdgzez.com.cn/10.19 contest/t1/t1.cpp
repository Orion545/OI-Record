#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,a[310][310],ban[310],cnt[310],cur[310];
bool check(int lim){
	int i;
	memset(ban,0,sizeof(ban));
	for(i=1;i<=n;i++) cur[i]=1;
	while(1){
		bool flag=1;
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++){
			while(cur[i]<=m&&ban[a[i][cur[i]]]) cur[i]++;
			cnt[a[i][cur[i]]]++;
//			cout<<"check "<<i<<' '<<cur[i]<<' '<<a[i][cur[i]]<<' '<<cnt[a[i][cur[i]]]<<'\n';
			if(cnt[a[i][cur[i]]]>lim) ban[a[i][cur[i]]]=1,flag=0;
			if(cur[i]>m) return 0;
		}
		if(flag) return 1;
	}
	return 0;
}

		
int main(){
	n=read();m=read();int i,j,l,r,mid;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++) a[i][j]=read();
	}
	l=1;r=n;
	while(l<r){
		mid=(l+r)>>1;
//		cout<<"binary "<<mid<<'\n';
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}

