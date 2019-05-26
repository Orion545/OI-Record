#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
int n,m,s[110][110],a[10010],ans=0;char str[110];
int main(){
	n=read();m=read();int i,j,k,x,ff,flag;
	for(i=1;i<=n;i++){
		scanf("%s",str);
		s[i][0]=strlen(str);
		for(j=0;j<s[i][0];j++) s[i][j+1]=(str[j]=='1');
	}
	for(x=0;x<(1<<m);x++){
		for(i=0;i<m;i++){
			if(x&(1<<i)) a[i+1]=1,a[2*m-i]=0;
			else a[i+1]=0,a[2*m-i]=1;
		}
//		for(i=1;i<=m*2;i++) cout<<a[i];
//		cout<<'\n';
		ff=1;
		for(i=1;i<=n;i++){
			flag=0;
			for(j=1;j<=2*m-s[i][0]+1;j++){
				for(k=1;k<=s[i][0];k++){
					if(a[j+k-1]!=s[i][k]) break;
				}
				if(k==s[i][0]+1){flag=1;break;}
			}
			if(!flag){ff=0;break;}
		}
//		cout<<ff<<'\n';
		if(ff) ans++;
	}
	cout<<ans<<'\n';
}
