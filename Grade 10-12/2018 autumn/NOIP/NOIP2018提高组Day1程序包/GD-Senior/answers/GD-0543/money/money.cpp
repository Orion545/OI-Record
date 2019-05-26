#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void read(int &x){
	int f=1;x=0;
	char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}
int A[105];
bool f[25005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	read(T);
	while(T--){
		memset(f,0,sizeof(f));
		int n;
		read(n);
		for(int i=1;i<=n;i++) read(A[i]);
		sort(A+1,A+n+1);
		int ans=0;
		f[0]=1;
		for(int i=1;i<=n;i++){
			if(!f[A[i]]){
				ans++;
				for(int j=0;j+A[i]<=A[n];j++){
					if(f[j]) f[j+A[i]]=1;
				}
			}
		}
		printf("%d\n",ans);
	}
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
