#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int n;
inline int read()
{
	char ch=getchar();int x=0,f=0;
	for(; ch<'0'||ch>'9' ;ch=getchar())	if(ch=='-')	f=1;
	for(;'0'<=ch&&ch<='9';ch=getchar())	x=(x<<3)+(x<<1)+(ch^48);
	return f?-x:x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)	a[i]=read();
	a[0]=a[n+1]=0;
	int ans=0;
	for(int i=1;i<=n+1;i++)
	{
		b[i]=a[i]-a[i-1];	
		if(b[i]>0)	ans+=b[i];
	}
	cout<<ans<<endl;
	return 0;
}
