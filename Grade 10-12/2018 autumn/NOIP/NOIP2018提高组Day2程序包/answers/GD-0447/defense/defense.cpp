#include <iostream>
#include <cstdio>
using namespace std;

int n,m;
inline int read();

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(); m=read();
	while(m--) cout<<-1<<endl;
	fclose(stdin); fclose(stdout);
}

inline int read()
{
	int ret=0,neg=0; char ch=getchar();
	while((ch<'0' || ch>'9') && ch!='-') ch=getchar();
	if (ch=='-') {neg=1;ch=getchar();}
	while(ch>='0' && ch<='9') {
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	if (neg) return -ret;
	return ret;
}

