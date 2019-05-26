#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
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
int A[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	read(n);
	int ans=0;
	for(int i=1;i<=n;i++){
		read(A[i]);
		ans+=abs(A[i]-A[i-1]);
	}
	ans+=A[n];
	printf("%d\n",ans/2);
}
/*
6
4 3 2 5 3 5
*/
