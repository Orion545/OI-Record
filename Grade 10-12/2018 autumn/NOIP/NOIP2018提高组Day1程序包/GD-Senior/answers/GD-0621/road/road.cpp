#include<bits/stdc++.h>
using namespace std;
namespace noip{
	int readu(){
		int ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		int value=ch-'0';
		ch=getchar();
		while(isdigit(ch)){
			value=value*10+ch-'0';
			ch=getchar();
		}
		return value;
	}
	void writeu(int a){
		if(a<10)
			putchar(a+'0');
		else{
			writeu(a/10);
			putchar(a%10+'0');
		}
	}
	void run(){
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		int n=readu();
		static int d[100000];
		for(int i=0; i<n; ++i)
			d[i]=readu();
		int result=d[0];
		for(int i=0; i<n-1; ++i)
			if(d[i+1]>d[i])
				result+=d[i+1]-d[i];
		writeu(result);
		putchar('\n');
	}
}
int main(){
	noip::run();
}
