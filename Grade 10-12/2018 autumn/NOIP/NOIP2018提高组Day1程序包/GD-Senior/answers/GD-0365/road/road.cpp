#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
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
const int N=100010;
long long a[N];
long long ans;
int n;
void work(int l,int r){
	if (l==r){
		ans+=a[l];
		return;
	}
	int minx=a[l];
	for (int i=l+1;i<=r;i++){
		if (a[i]<minx){
			minx=a[i];
		}
	}
	ans+=minx;
	for (int i=l;i<=r;i++){
		if(a[i]) a[i]-=minx;
	}
//	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<endl;
	int l1=l;
	for (l1;l1<=r;l1++)if(a[l1]) break;
	for (int i=l1;i<=r;i++){
		if (a[i]==0){
//			cout<<l1<<" "<<i-1<<endl;
			work(l1,i-1);
//			cout
			l1=i+1;
		}
		
	}
	if (a[r])work(l1,r);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//  	freopen("road2.in","r",stdin);
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	work(1,n);
	cout<<ans;
	return 0;
}

