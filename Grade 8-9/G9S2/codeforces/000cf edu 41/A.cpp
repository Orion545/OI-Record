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
int n,m,a[1010]={0},cnt[1010]={0},tot;
int main(){
	n=read();m=read();int i,j;tot=n;int ans=0;
	for(i=1;i<=m;i++){
		a[i]=read();cnt[a[i]]++;
//		cout<<a[i]<<ends<<cnt[a[i]]<<endl;
		if(cnt[a[i]]==1) tot--;
		if(!tot){
			ans++;
			for(j=1;j<=n;j++){
				cnt[j]--;
				if(cnt[j]==0) tot++;
			}
		}
	}
	cout<<ans;
}
