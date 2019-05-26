#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char s=getchar();
	while (s<'0'or s>'9'){if (s=='-')f=-1;s=getchar();}
	while (s>='0'and s<='9'){
		x=(x<<3)+(x<<1)+s-'0';
		s=getchar();
	}
	return x*f;
}
const int N=1000;
int a[N];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	bool flag=0;
	while (T!=0){
		flag=0;
		int n=read();
		for (int i=1;i<=n;i++){
			a[i]=read();
			if (a[i]==1)flag=1;
		}
		if (flag){cout<<1<<endl;T--;continue;}
		if(n==2)cout<<2<<endl;
		else cout<<3<<endl;
		T--;
	}
	return 0;
}

