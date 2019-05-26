#include<cstdio>
#include<cctype>
using namespace std;
int ans,last;
inline int read()
{
	int X=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) X=(X<<1)+(X<<3)+(ch^48),ch=getchar();
	return w?-X:X;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	while(n--)
	{
		int now=read();
		if(now>last) ans+=now-last;
		last=now;
	}
	printf("%d",ans);
	return 0;
}
