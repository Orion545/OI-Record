#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,m,a[2010][2010],b[2010][2010],height[2010],sta[2010],top,le[2010],ri[2010];
char s[2010];
int main(){
	n=read();m=read();int i,j;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=1;j<=m;j++) a[i][j]=(s[j-1]=='#');
	}
	for(i=1;i<n;i++) 
		for(j=1;j<m;j++)
			b[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];
	int ans=max(n,m);
	for(i=1;i<=n;i++){
		for(j=1;j<m;j++) height[j]++,le[j]=0,ri[j]=m;
		top=1;sta[top]=0;
		for(j=1;j<m;j++){
			while(height[sta[top]]>height[j]){
//				cout<<"poped1\n";
				ri[sta[top]]=j;
				sta[top--]=0;
			}
			sta[++top]=j;
		}
		top=1;sta[top]=m;
		for(j=m-1;j>0;j--){
			while(height[sta[top]]>height[j]){
//				cout<<"poped2\n";
				le[sta[top]]=j;
				sta[top--]=0;
			}
			sta[++top]=j;
		}
		for(j=1;j<m;j++) ans=max(ans,height[j]*(ri[j]-le[j]));
		for(j=1;j<m;j++) if(b[i][j]) height[j]=0;
	}
	printf("%d\n",ans);
}

