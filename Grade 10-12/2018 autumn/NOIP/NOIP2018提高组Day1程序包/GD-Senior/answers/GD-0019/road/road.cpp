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

long long shuliang;
int nio,ap,bp;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	nio=read<int>();
	for(register int i=1;i<=nio;++i){
		ap=read<int>();
		if(ap>bp){
			shuliang+=(ap-bp);
		}
		bp=ap;
	}
	write(shuliang);
	return 0;
}
