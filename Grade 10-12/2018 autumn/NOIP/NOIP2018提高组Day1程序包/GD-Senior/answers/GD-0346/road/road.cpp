#include <iostream>
#include <cstdio>
#define ll long long
#define re register int
using namespace std;
const int N = 1e5+5;
int n,a[N];
ll res;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch == '-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	for(re i=1; i<=n; i++){
		a[i] = read();
	}
	int k = a[1];
	res += (ll)a[1];
	for(re i=2; i<=n; i++){
		if(a[i]<=k){
			k = a[i];
			continue;
		} 
		res += (ll)(a[i]-k);
		k = a[i];
	}
	cout <<res << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
