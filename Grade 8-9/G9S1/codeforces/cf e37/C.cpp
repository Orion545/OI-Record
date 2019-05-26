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
int n,a[200010],b[200010],l[200010],r[200010];
int main(){
	int i,j;string s;
	n=read();
	for(i=1;i<=n;i++){
		a[i]=read();l[i]=r[i]=i;
	} 
	cin>>s;
	for(i=0;i<(n-1);i++) b[i+1]=(s[i]=='1');
	for(i=1;i<n;i++){
		if(b[i]){
			l[i+1]=l[i];r[l[i]]=i+1;
		}
	}
//	for(i=1;i<=n;i++) cout<<l[i]<<ends<<r[i]<<endl;
	for(i=1;i<=n;i++){
		if(a[i]>=l[i]&&a[i]<=r[l[i]]) continue;
		else{
			printf("NO\n");return 0;
		}
	}
	printf("YES\n");
} 
