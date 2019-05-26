#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rep(i,a,b) for(int i=b;i>=a;--i)

#define p(x) ('0'<=x&&x<='9')
char cc;
template <class T> void read(T &x)
{
	static int re;
	x=0; re=1; cc=getchar();
	while(!p(cc)) { re= cc=='-'?-1:1; cc=getchar(); }
	while(p(cc)) { x=x*10+cc-'0'; cc=getchar(); }
	x=x*re;
}
#undef p

using namespace std;

#define N 25050
int n,top;
bool cover[N];
int a[110],ans;

int que[65540];
unsigned short int he,ta;
void C(int val)
{
	int node;
	For(i,a[1],a[n]) if(cover[i]&&i+val<25000) cover[i+val]=1;
}

void Main()
{
	read(n);
	memset(a,0,sizeof(a));
	memset(cover,0,sizeof(cover));
	top=1;
	ans=0;
	For(i,1,n) read(a[i]);
	sort(a+1,a+1+n);
	For(i,1,n)
		if(!cover[a[i]])
		{
			++ans;
			cover[a[i]]=true;
			C(a[i]);
		}
	printf("%d\n",ans);
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	for(read(T);T;--T) Main();
	return 0;
}
