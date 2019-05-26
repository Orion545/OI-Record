#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL long long
using namespace std;
const int maxn=100005;
int n;
int a[maxn];
LL ans;
inline void read(int &x){
	int w=0,X=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')w^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0')X=(((X<<2)+X)<<1)+(ch^48),ch=getchar();
	x=w?-X:X;
	return;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
inline void writeln(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
	puts("");
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	memset(a,0,sizeof(a));
	ans=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]>a[i-1])ans+=a[i]-a[i-1];
	}
	writeln(ans);
	return 0;
}
