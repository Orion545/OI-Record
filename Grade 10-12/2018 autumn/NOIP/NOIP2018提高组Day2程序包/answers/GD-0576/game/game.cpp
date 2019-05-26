#include <bits/stdc++.h>
using namespace std;
int m,n;
int ma[22][22];

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	long long sum=0;
	if(n<m){
		int c=n;
		n=m;
		m=c;
	}
	if(m==2){
		sum+=(pow(2,n-1)-1)*4;
		sum+=pow(2,n+1);
	}
	cout<<sum;
	return 0;
}
