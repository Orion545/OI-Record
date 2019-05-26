#include<iostream>
#include<ctime>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n=500,m=499,k=3;
	cout<<n<<' '<<m<<' '<<k<<'\n';
	for(int i=1;i<=n;i++){
		int j;
		for(j=1;j<=k;j++){
			int k=rand()%3;
			if(k==0) putchar('+');
			if(k==1) putchar('-');
			if(k==2) putchar('/');
		}
		putchar('\n');
	}
	for(int i=1;i<=m;i++){
		cout<<i<<' '<<i+1<<'\n';
	}
}
