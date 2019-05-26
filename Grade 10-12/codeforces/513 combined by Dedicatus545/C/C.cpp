#include<iostream>
#include<cstring>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 2e9

using namespace std;

#define ll long long
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}

int AFSDGHJ[300010],LLLBBNB[300010];
int n,m;
ll s[300010],s1[300010]; 
ll MAAIINNN[300010];

void input(){
	int i;
	for(i=1;i<=n;i++){
		AFSDGHJ[i]=read();
		s1[i]=s1[i-1]+AFSDGHJ[i];
	}
	for(i=1;i<=m;i++){
		LLLBBNB[i]=read();
		s[i]=s[i-1]+LLLBBNB[i];
		MAAIINNN[i]=INF;
	}
}

void getmin(){
	int i,j;
	for(i=1;i<=m;i++){
		for(j=i;j<=m;j++){
			MAAIINNN[j-i+1]=min(MAAIINNN[j-i+1],s[j]-s[i-1]);
		}
	}
}

int main(){
	n=read();m=read();
	int i,j;
	input();getmin();
	ll ret=0,XX=read(),l,r,mid,X,ans;
	
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			ans=0;
			X=s1[j]-s1[i-1];
			l=1,r=m; 
			while(l<=r){
				mid=(l+r)>>1;
				if(1LL*X*MAAIINNN[mid]<=XX){
					l=mid+1;
					ans=mid;
				}
				else r=mid-1;
			}
			ret=max(ret,ans*(j-i+1));
		}
	} 
	cout<<ret;
}
