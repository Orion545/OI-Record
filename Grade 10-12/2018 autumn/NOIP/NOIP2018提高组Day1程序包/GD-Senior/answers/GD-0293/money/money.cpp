#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

bool f[25001];
int T,m,n,a[101];

void update(int j){
	f[a[j]]=true;
	for(int k=a[j]+1;k<=25000;++k)if(!f[k])f[k]|=f[k-a[j]];
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		memset(f,false,sizeof(f));
		m=1;
		scanf("%d",&n);for(int j=1;j<=n;++j)scanf("%d",a+j);sort(a+1,a+n+1);
		for(int j=1;j*a[1]<=25000;++j)f[j*a[1]]=true;
		for(int j=2;j<=n;++j)if(!f[a[j]])update(j),++m;
		printf("%d\n",m);
	}
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
