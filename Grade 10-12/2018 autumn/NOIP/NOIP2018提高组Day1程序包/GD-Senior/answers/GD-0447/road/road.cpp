#include <iostream>
#include <cstdio>
using namespace std;

const int N=100005;
int n,d[N];
long long ans=0;

void work(int l,int r,int minus);
inline int read();

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) d[i]=read();
	work(1,n,0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}

void work(int l,int r,int minus)
{
	if (l>r) return;
	int mini=0x7fffffff,pos=0;
	for (int i=l;i<=r;i++) {
		if (d[i]<mini && d[i]>=minus) {
			mini=d[i];
			pos=i;
		}
	}
	//cout<<pos<<endl;
	ans+=mini-minus;
	work(l,pos-1,mini);
	work(pos+1,r,mini);
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

