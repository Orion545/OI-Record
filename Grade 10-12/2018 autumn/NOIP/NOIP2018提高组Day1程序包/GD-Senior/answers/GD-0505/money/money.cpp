#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
inline char gc(){
	static char bb[1000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,1000000,stdin),s==t)?EOF:*s++;
}
inline int read(){
	register int x=0;register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+ch-48,ch=gc();
	return x;
}
int n;
vector<int>arr;
bool dp[25005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--){
		arr.clear();
		n=read();
		for(int i=0;i<n;i++)arr.push_back(read());
		sort(arr.begin(),arr.end());
		int cnt=n;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<n;i++){
			for(int u=0;u<i;u++){
				for(int j=0;j<=arr[i]-arr[u];j++){
					dp[j+arr[u]]|=dp[j];
					if(dp[arr[i]])goto huaji;
				}
			}
			continue;
		huaji:
			cnt--;
		}
		cout<<cnt<<endl;
	}
}
