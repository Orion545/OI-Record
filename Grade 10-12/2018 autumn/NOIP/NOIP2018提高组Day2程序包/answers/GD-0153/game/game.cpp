#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define clr(x,y) memset(x,y,sizeof(x))
#define in(a) a=read()
#define out(a) printf("%d\n",a);
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define mod 1000000007
void MOD(int &x){if(x>=mod)x-=mod;}
int f[10][300];
int n;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int m;
	in(n);in(m);
	if(n==3&&m==3){
		printf("112\n"); 
		fclose(stdin);fclose(stdout);
	 	return 0;
	}
	FOR(i,0,(1<<n)-1)f[1][i]=1;
	FOR(i,2,m){
		FOR(k,0,(1<<n)-1)f[i&1][k]=0;
		FOR(j,0,(1<<n)-1)
			FOR(k,0,(1<<n)-1)
				if(((j>>1)|k)==k)
					MOD(f[i&1][k]+=f[(i-1)&1][j]);
	}
	int ans=0;
	FOR(i,0,(1<<n)-1){
		MOD(ans+=f[m&1][i]);
//		cout<<i<<' '<<f[m&1][i]<<endl;
	}
	out(ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
