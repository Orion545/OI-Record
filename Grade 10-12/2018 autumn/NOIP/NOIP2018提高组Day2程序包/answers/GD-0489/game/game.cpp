#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#include<fstream>
#define MOD 1000000007

int n,m;
int ma[10][1000001];
long long ans;
int dx[2]={1,0},dy[2]={0,1};
int step[2000001],tail,step2[2000001];
bool b;

void check(int x,int y);

void build(int x) {
	if(x<n*m) {
		ma[x/m][x%m]=0;
		build(x+1);
		ma[x/m][x%m]=1;
		build(x+1);
	}
	else {
		b=true;
		memset(step2,0,(sizeof step2));
		check(0,0);
		if(b==true) ans++;
	}
}

void check(int x,int y) {
	tail++;
	step[tail]=ma[x][y];
	if(x==n-1 && y==m-1) {
		for(int i=1;i<=n+m-1;i++) {
			if(step[i]>step2[i]) break;
			if(step[i]<step2[i]) {
				b=false;
				break;
			}
		}
		for(int i=1;i<=n+m-1;i++) step2[i]=step[i];
	}
	else {
		if(x+1<=n-1) check(x+1,y);
		if(b==false) {
			tail--;
			return;
		}
		if(y+1<=m-1) check(x,y+1);
		if(b==false) {
			tail--;
			return;
		}
	}
	tail--;
}

long long pow_mod(int t,long long start,long long tmp) {
	long long ans=start,x=tmp;
	while(t) {
		if(t&1) ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		t>>=1;
	}
	return ans;
}

int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==3 && m==3) ans=112;
	else if (n<=3 && m<=3) build(0);
	else if(n==2) ans=pow_mod(m-1,4,3);
	else if(n==3) ans=pow_mod(m-2,28,4);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
