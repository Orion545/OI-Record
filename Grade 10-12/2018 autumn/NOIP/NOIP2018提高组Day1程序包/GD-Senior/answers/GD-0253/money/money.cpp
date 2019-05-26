#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
#define N 105
using namespace std;
int t,n,a[N],l,r,qwq[N];
void read(int &x){
	x=0;
	char c;
	int w=1;
	for (c=getchar();c<'0'||c>'9';c=getchar()) if (c=='-') w=-1;
	for (;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
	x*=w;
}
bool cmp(const int a,const int b){
	return (a<b);
}
bool check(int x,int y,int z){
	int cnt=z/y;
	y=y%x;
	z=z%x;
	if (z%y!=0) return false;
	else if (z/y>cnt) return false;
	return true; 
}
void work(){
	bool sign=false;
	r=1;
	l=1;
	qwq[r]=a[l];
	++l;
	while (a[l]%qwq[r]==0) ++l;
	qwq[++r]=a[l];
	while (l<=n){
		++l;
		sign=false;
		for (int x=1;x<r;++x){
			if (sign) break;
			for (int y=x+1;y<=r;++y){
				if (sign) break;
				if ((a[l]%qwq[x]==0)||(a[l]%qwq[y]==0)) sign=true;
				else if (check(qwq[x],qwq[y],a[l])) sign=true;
			}
		}
		if (!sign) qwq[++r]=a[l];
	}
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	read(t);
	while (t--){
		memset(a,0,sizeof(a));
		memset(qwq,0,sizeof(qwq));
		read(n);
		for (int i=1;i<=n;++i)
			read(a[i]);
		sort(a+1,a+1+n,cmp);
		work();
		if (n==1) r=1;
		printf("%d\n",r);
	}
	return 0;
}
