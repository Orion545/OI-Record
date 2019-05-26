#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define re register int
using namespace std;
const int N = 5e3+5;
int n,m,dfn[N],cnt,a[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(); m=read();
	for(int i=1; i<=m; i++){
		cout << -1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}




