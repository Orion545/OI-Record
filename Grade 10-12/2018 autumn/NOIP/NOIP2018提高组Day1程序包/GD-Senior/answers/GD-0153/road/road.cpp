#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define in(a) a=read()
#define out(a) printf("%d\n",a)
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define clr(a,x) memset(a,x,sizeof(a))
int read(){
	int f=1,x=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
int s[100010],a[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	in(n);
	ll ans=0;
	FOR(i,1,n){
		in(a[i]);
		s[i]=a[i]-a[i-1];
		if(s[i]>0)ans+=(ll)s[i];
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
