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
int n,a[5][110][110],ans[5][2];
int main(){
	n=read();int i,j,k;char s[110];
	for(k=1;k<=4;k++){
		for(i=1;i<=n;i++){
			scanf("%s",s);
			for(j=1;j<=n;j++){
				a[k][i][j]=(s[j-1]=='1');
			}
		}
		//top-left 0
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[k][i][j]) ans[k][(i+j)%2]++;
				else ans[k][(i+j+1)%2]++;
			}
		}
//		cout<<ans[k][0]<<ends<<ans[k][1]<<endl;
	}
	int minn=4*n*n;
	minn=min(minn,ans[1][0]+ans[2][1]+ans[3][0]+ans[4][1]);
	minn=min(minn,ans[1][0]+ans[2][0]+ans[3][1]+ans[4][1]);
	minn=min(minn,ans[1][0]+ans[2][1]+ans[3][1]+ans[4][0]);
	minn=min(minn,ans[1][1]+ans[2][0]+ans[3][1]+ans[4][0]);
	minn=min(minn,ans[1][1]+ans[2][1]+ans[3][0]+ans[4][0]);
	minn=min(minn,ans[1][1]+ans[2][0]+ans[3][0]+ans[4][1]);
	cout<<minn<<endl;
}
