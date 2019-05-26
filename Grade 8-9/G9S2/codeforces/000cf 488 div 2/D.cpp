#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,x1[20],y1[20],x2[20],y2[20];
int a[20][20];
int main(){
	int i,j,ans1[20]={0},ans2[20]={0};n=read();m=read();
	for(i=1;i<=n;i++){
		x1[i]=read();y1[i]=read();
		if(x1[i]>y1[i]) swap(x1[i],y1[i]);
	}
	for(i=1;i<=m;i++){
		x2[i]=read();y2[i]=read();
		if(x2[i]>y2[i]) swap(x2[i],y2[i]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if((x1[i]==x2[j]&&y1[i]!=y2[j])||(x1[i]!=x2[j]&&y1[i]==y2[j])||(y1[i]==x2[j])){
				if(x1[i]==x2[j]&&y1[i]!=y2[j]) a[i][j]=x1[i];
				if(x1[i]!=x2[j]&&y1[i]==y2[j]) a[i][j]=y1[i];
				if(y1[i]==x2[j]) a[i][j]=y1[i];
//				cout<<i<<' '<<j<<' '<<a[i][j]<<'\n';
			}
		}
	}
	
	for(i=1;i<=n;i++){
		int cnt=0,tmp=0;
		for(j=1;j<=m;j++){
			if(a[i][j]==0) continue;
			if(a[i][j]!=tmp) cnt++,tmp=a[i][j];
		}
		if(cnt==1) ans1[tmp]=1;
		if(cnt>1){
			puts("-1");return 0;
		}
	}
	int cnt1=0;
	for(i=1;i<=9;i++) if(ans1[i]) cnt1++;
	
	for(j=1;j<=m;j++){
		int cnt=0,tmp=0;
		for(i=1;i<=n;i++){
			if(a[i][j]==0) continue;
			if(a[i][j]!=tmp) cnt++,tmp=a[i][j];
		}
		if(cnt==1) ans2[tmp]=1;
		if(cnt>1){
			puts("-1");return 0;
		}
	}
	int cnt2=0;
	for(i=1;i<=9;i++) if(ans2[i]) cnt2++;
	
	if(cnt1==1&&cnt2==1){
		for(i=1;i<=9;i++) if(ans1[i]){
			cout<<i;return 0;
		}
	}
	else puts("0");
}
