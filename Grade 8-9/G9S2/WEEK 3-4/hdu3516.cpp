#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
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
int n,x[1010],y[1010],dp[1010][1010],s[1010][1010];
int w(int l,int mid,int r){
    //cout<<l<<' '<<mid<<' '<<r<<' '<<x[mid+1]-x[l]+y[mid]-y[r]<<'\n';
    return x[mid+1]-x[l]+y[mid]-y[r];
}
int main(){
    freopen("hdu3516.in","r",stdin);
    int i,j,len,tmp,k;
    while(~scanf("%d",&n)){
		for(i=1;i<=n;i++) x[i]=read(),y[i]=read();
    	for(i=1;i<=n;i++) dp[i][i]=0,s[i][i]=i;
    	for(len=1;len<n;len++){
    	    for(i=1;i<=n;i++){
    	        j=len+i;if(j>n) break;
    	        dp[i][j]=inf;
    	        for(k=s[i][j-1];k<=s[i+1][j]&&k<j;k++){
    	            if((tmp=dp[i][k]+dp[k+1][j]+w(i,k,j))<dp[i][j]){
    	                dp[i][j]=tmp;s[i][j]=k;
    	            }
    	        }
                //cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
    	    }
    	}
    	printf("%d\n",dp[1][n]);
    }
}
