#include<bits/stdc++.h>
using namespace std;
template <typename _Tp> _Tp read(){
	register int f=1;
	register _Tp num=0;register char c=0;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	while(isdigit(c))
	num=(num<<1)+(num<<3)+(c&15),c=getchar();
	return num*f;
}
template <typename _Tp> void write(_Tp x){
	if(x<0) putchar('-'), write<_Tp>(~x+1);
	else{
		if(x>9) write<_Tp>(x/10);
		putchar(x%10+'0');
	}
}

int n,T,a[10000001];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read<int>();
	while(T--){
		n=read<int>();
		for(register int i=1;i<=n;++i) a[i]=read<int>();
		write(n),putchar('\n');
	}
	return 0;
}
