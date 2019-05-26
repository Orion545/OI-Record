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
		freopen("money.in", "r", stdin);
		freopen("money.out", "w", stdout);
		int t=readu();
		while(--t>=0){
			int n=readu();
			static int a[100];
			for(int i=0; i<n; ++i)
				a[i]=readu();
			sort(a, a+n);
			n=unique(a, a+n)-a;
			static bool ok[25000+1];
			memset(ok, 0, sizeof ok);
			ok[0]=true;
			int result=0;
			for(int i=0; i<n; ++i){
				int value=a[i];
				if(ok[value])
					continue;
				++result;
				for(int j=value; j<=25000; ++j)
					if(ok[j-value])
						ok[j]=true;
			}
			writeu(result);
			putchar('\n');
		}
	}
}
int main(){
	noip::run();
}
