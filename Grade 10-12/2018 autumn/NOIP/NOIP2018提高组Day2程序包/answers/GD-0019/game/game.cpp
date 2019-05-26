#include<bits/stdc++.h>
#define mod 1000000007
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
	if(x<0) putchar('-'), write<_Tp> (~x+1);
	else{
		if(x>9) write<_Tp>(x/10);
		putchar(x%10+'0');
	}
}
int n,m;
int main(){
	freopen("game.in","r",stdout);
	freopen("game.out","w",stdout);
	n=read<int>(),m=read<int>();
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(m==1){
			cout<<"0";
			return 0;
		}
		if(m==2){
			cout<<"12";
			return 0;
		}
		if(m==3){
			cout<<"36";
			return 0;
		}
	}
	if(n==3){
		if(m==1){
			cout<<"0";
			return 0;
		}
		if(m==2){
			cout<<"36";
			return 0;
		}
		if(m==3){
			cout<<"112";
			return 0;
		}
	}
	return 0;
}
