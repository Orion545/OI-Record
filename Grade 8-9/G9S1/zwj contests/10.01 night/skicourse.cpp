#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[110][110],ans;
int main(){
	freopen("skicourse.in","r",stdin);
	freopen("skicourse.out","w",stdout);
	int i,j,k,l;string s;
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s;
		for(j=0;j<m;j++){
			if(s[j]=='R') a[i][j+1]=1;
			else a[i][j+1]=2;
		}
	}
	int minn=min(n,m),maxn=max(n,m),tar,size,flag;
	for(i=1;i<=maxn;i++){
		for(j=1;j<=minn;j++){
			tar=a[i][j];flag=0;
			size=min(maxn-i+1,minn-j+1);
			for(size=min(maxn-i+1,minn-j+1);size>=1;size--){
				for(k=i;k<=i+size-1;k++){
					for(l=j;l<=j+size-1;l++){
						if(a[k][l]!=tar) goto skip;
					}
				}
				flag=1;
				skip:
				if(flag){
					ans=max(ans,size);break;
				} 
			}
		}
	}
	cout<<ans;
} 
