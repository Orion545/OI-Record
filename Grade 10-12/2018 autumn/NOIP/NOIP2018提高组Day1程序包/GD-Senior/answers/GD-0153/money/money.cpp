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
bool f[100000];
int a[200];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	in(t);
	while(t--){
		clr(f,0);
		int n;
		in(n);
		FOR(i,1,n)in(a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		f[0]=1;
		FOR(i,1,n){
			if(f[a[i]])continue;
			ans++;	
			FOR(j,a[i],25000)f[j]|=f[j-a[i]];
		}
		out(ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
